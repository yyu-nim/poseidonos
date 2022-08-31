#include <thread>
#include "src/include/pos_event_id.h"
#include "src/logger/logger.h"
#include "src/telemetry/telemetry_client/easy_telemetry_publisher.h"

namespace pos {

EasyTelemetryPublisher::EasyTelemetryPublisher()
{
    pthread_rwlock_init(&counterLock, nullptr);
    pthread_rwlock_init(&gaugeLock, nullptr);

    publisher = new TelemetryPublisher("EasyTelemetryPublisher");
    TelemetryClientSingleton::Instance()->RegisterPublisher(publisher);

    POS_TRACE_INFO(EID(SUCCESS), "Easy Telemetry Publisher has been created");

    std::thread(
        [this] {
            this->_PeriodicPublish();
        }).detach();
    POS_TRACE_INFO(EID(SUCCESS), "Easy Telemetry Publisher started to periodically publish stats");

}

EasyTelemetryPublisher::~EasyTelemetryPublisher()
{
    delete publisher;
    POS_TRACE_INFO(EID(SUCCESS), "Easy Telemetry Publisher has been deleted");
}

TelemetryPublisher*
EasyTelemetryPublisher::tp()
{
    return publisher;
}

void
EasyTelemetryPublisher::BufferIncrementCounter(std::string id_)
{
    BufferIncrementCounter(id_, 1);
}

void
EasyTelemetryPublisher::BufferIncrementCounter(std::string id_, uint64_t counts)
{
    vector<pair<string, string>> emptyLabels;
    BufferIncrementCounter(id_, counts, emptyLabels);
}

void
EasyTelemetryPublisher::BufferIncrementCounter(std::string id_, uint64_t counts, vector<pair<string, string>>& labels)
{
    POSMetric m(id_, MT_COUNT);
    for(auto& label: labels) {
        m.AddLabel(label.first, label.second);
    }
    auto hashed = m.Hash();

    count_buffered_counter += 1;
    pthread_rwlock_wrlock(&counterLock);
    auto itor = counters_with_labels.find( hashed );
    if( itor == counters_with_labels.end() ) {
        // new entry and/or label
        m.SetCountValue(counts);
        counters_with_labels[hashed] = m; // "copy" happens
    } else {
        // existing entry
        auto existingValue = itor->second.GetCountValue();
        auto newValue = existingValue + counts;
        itor->second.SetCountValue(newValue);
    }
    pthread_rwlock_unlock(&counterLock);
}

void
EasyTelemetryPublisher::BufferUpdateGauge(std::string id_, uint64_t currValue, vector<pair<string, string>>& labels)
{
    POSMetric m(id_, MT_COUNT);
    for(auto& label: labels) {
        m.AddLabel(label.first, label.second);
    }
    auto hashed = m.Hash();

    count_buffered_gauge += 1;
    pthread_rwlock_wrlock(&gaugeLock);
    m.SetGaugeValue(currValue);
    gauges_with_labels[hashed] = m;
    pthread_rwlock_unlock(&gaugeLock);
}

void
EasyTelemetryPublisher::BufferUpdateGauge(std::string id_, uint64_t currValue)
{
    vector<pair<string, string>> emptyLabels;
    BufferUpdateGauge(id_, currValue, emptyLabels);
}

void
EasyTelemetryPublisher::ShardedBufferIncrementCounter(std::string shardId, std::string id_)
{
    ShardedBufferIncrementCounter(shardId, id_, 1);
}

void
EasyTelemetryPublisher::ShardedBufferIncrementCounter(std::string shardId, std::string id_, uint64_t counts)
{
    vector<pair<string, string>> emptyLabels;
    ShardedBufferIncrementCounter(shardId, id_, counts, emptyLabels);
}

void
EasyTelemetryPublisher::ShardedBufferIncrementCounter(std::string shardId, std::string id_, uint64_t counts, vector<pair<string, string>>& labels)
{
    _ShardedBufferUpdateMetric(shardId, POSMetricTypes::MT_COUNT, id_, counts, labels);
}

void
EasyTelemetryPublisher::ShardedBufferUpdateGauge(std::string shardId, std::string id_, uint64_t currValue)
{
    vector<pair<string, string>> emptyLabels;
    ShardedBufferUpdateGauge(shardId, id_, currValue, emptyLabels);
}

void
EasyTelemetryPublisher::ShardedBufferUpdateGauge(std::string shardId, std::string id_, uint64_t currValue, vector<pair<string, string>>& labels)
{
    _ShardedBufferUpdateMetric(shardId, POSMetricTypes::MT_GAUGE, id_, currValue, labels);
}

void
EasyTelemetryPublisher::_ShardedBufferUpdateMetric(std::string shardId, POSMetricTypes metricType, std::string id_, uint64_t value, vector<pair<string, string>>& labels)
{
    // caller is expected to pick up a proper shard where the caller is the only writer that can update the metric
    POSMetric m(id_, metricType);
    for(auto& label: labels) {
        m.AddLabel(label.first, label.second);
    }
    auto hashed = m.Hash();

    if ( this->shardedMetricMap.find(shardId) == this->shardedMetricMap.end() ) {
        // new metric & new map. we will create a new ShardedMap and spawn a publisher thread
        pthread_rwlock_t* shardLock = new pthread_rwlock_t ();
        pthread_rwlock_init( shardLock, nullptr );
        this->shardedMetricLock[shardId] = shardLock;
        this->shardedMetricMap[shardId] = MetricMap();
        POS_TRACE_INFO(EID(SUCCESS), "Created a new sharded metric map for shard id = {}", shardId);

        std::string* shardIdPtr = new string(shardId);
        std::thread(
            [this, shardIdPtr] {
                this->_PeriodicPublish(*shardIdPtr);
                // shardIdPtr will be used internally in an infinite loop, so I will not be freeing it.
            }).detach();
        POS_TRACE_INFO(EID(SUCCESS), "Created a new publisher thread for metric map for shard id = {}", shardId);
    }
    auto& metricMap = this->shardedMetricMap[shardId];
    auto& shardLock = this->shardedMetricLock[shardId];
    pthread_rwlock_rdlock(shardLock);
    if( metricType == POSMetricTypes::MT_GAUGE ) {
        // Gauge doesn't have to remember its previous value
        m.SetGaugeValue(value);
    } else {
        // Counter will have to look up its previous value
        auto itor = metricMap.find(hashed);
        if( itor == metricMap.end() ) {
            if( metricType == POSMetricTypes::MT_COUNT ) {
                m.SetCountValue(value);
            } else {
                POS_TRACE_ERROR(EID(TELEMETRY_DEBUG_MSG), "EasyTelemetry for Metric Type {} is not supported yet - new metric", metricType);
            }
        } else {
            if( metricType == POSMetricTypes::MT_COUNT ) {
                auto newValue = itor->second.GetCountValue() + value;
                m.SetCountValue(newValue);
            } else {
                POS_TRACE_ERROR(EID(TELEMETRY_DEBUG_MSG), "EasyTelemetry for Metric Type {} is not supported yet - existing metric", metricType);
            }
        }
    }
    metricMap[hashed] = m;
    pthread_rwlock_unlock(shardLock);
}

void
EasyTelemetryPublisher::_PeriodicPublish()
{
    while(true) {

        // publish & clear counter metrics with label
        _PublishMetricsWithLabels(this->counters_with_labels, this->counterLock);

        // publish & clear counter metrics with label
        _PublishMetricsWithLabels(this->gauges_with_labels, this->gaugeLock);

        // Sleep
        usleep(1 * 1000 * 1000); // sleeps for a second
    }
}

void
EasyTelemetryPublisher::_PeriodicPublish(std::string& shardId)
{
    while(true) {
        auto itor = this->shardedMetricMap.find(shardId);
        auto lockItor = this->shardedMetricLock.find(shardId);
        if( itor == this->shardedMetricMap.end() || lockItor == this->shardedMetricLock.end() ) {
            POS_TRACE_INFO(EID(SUCCESS), "Easy Telemetry Publisher for shard id {} is not ready yet", shardId);
        } else {
            auto& metricMap = itor->second;
            auto& shardLock = *lockItor->second;
            _PublishMetricsWithLabelsWithNonTBB(metricMap, shardLock);
        }

        // sleep
        usleep(1 * 1000 * 1000);
    }
}

void
EasyTelemetryPublisher::_PublishMetricsWithLabels(tbb::concurrent_unordered_map<size_t, POSMetric>& map, pthread_rwlock_t& metricLock)
{
    std::vector<POSMetric>* metrics = new std::vector<POSMetric>;
    pthread_rwlock_wrlock(&metricLock);
    for(auto& entry: map) {
        metrics->emplace_back(entry.second);
    }
    map.clear();
    pthread_rwlock_unlock(&metricLock);
    publisher->PublishMetricList(metrics);
}

void
EasyTelemetryPublisher::_PublishMetricsWithLabelsWithNonTBB(MetricMap& map, pthread_rwlock_t& metricLock)
{
    std::vector<POSMetric>* metrics = new std::vector<POSMetric>;
    pthread_rwlock_wrlock(&metricLock);
    for(auto& entry: map) {
        metrics->emplace_back(entry.second);

        if( entry.second.GetType() == POSMetricTypes::MT_COUNT ) {
            entry.second.SetCountValue(0);
        }
    }
    //map.clear(); // => lead to memory corruption somehow. instead, we erased the counter metric by setting it to zero
    pthread_rwlock_unlock(&metricLock);
    publisher->PublishMetricList(metrics);
}


/*** DEPRECATED ***/
void
EasyTelemetryPublisher::_Report()
{
    for(auto& map: {this->counters_with_labels, this->gauges_with_labels}) {
        pthread_rwlock_t* lockPtr = nullptr;
        if( &map == &this->counters_with_labels ) {
            lockPtr = &this->counterLock;
        } else {
            lockPtr = &this->gaugeLock;
        }
        pthread_rwlock_wrlock(lockPtr);
        for(auto& entry: map) {
            POS_TRACE_INFO(EID(SUCCESS), "Easy Telemetry Publisher (counter): key = {}, value = {}", entry.second.GetName(), entry.second.GetCountValue());
            for(auto& label: *entry.second.GetLabelList()) {
                POS_TRACE_INFO(EID(SUCCESS), "\t- label key = {}, label value = {}", label.first, label.second);
            }
        }
    	pthread_rwlock_unlock(lockPtr);
    }

}

}
