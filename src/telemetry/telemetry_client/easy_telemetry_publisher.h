#pragma once

#include "src/telemetry/telemetry_client/telemetry_publisher.h"
#include "src/telemetry/telemetry_client/telemetry_client.h"
#include "src/lib/singleton.h"
#include <tbb/concurrent_unordered_map.h>
#include <pthread.h>
#include "src/telemetry/telemetry_client/pos_metric.h"

namespace pos
{

using MetricMap = tbb::concurrent_unordered_map<size_t/*hash(metric name + labels)*/, POSMetric/* counter or gauge */>;
//using MetricMap = std::unordered_map<size_t/*hash(metric name + labels)*/, POSMetric/* counter or gauge */>;

class EasyTelemetryPublisher
{

public:
    EasyTelemetryPublisher();
    virtual ~EasyTelemetryPublisher();
    TelemetryPublisher* tp(); // DEPRECATED. Use Buffer* API instead.
    virtual void BufferIncrementCounter(std::string id_);
    virtual void BufferIncrementCounter(std::string id_, uint64_t counts);
    virtual void BufferIncrementCounter(std::string id_, uint64_t counts, vector<pair<string, string>>& labels);
    virtual void BufferUpdateGauge(std::string id_, uint64_t currValue);
    virtual void BufferUpdateGauge(std::string id_, uint64_t currValue, vector<pair<string, string>>& labels);

    // "Sharded" => there's a single writer that updates the metric in the map, e.g., meta worker thread in a event loop. Hence, no lock is acquired for metrics update
    // caller is expected to pick up a proper shard where the caller is the only writer that can update the metric
    virtual void ShardedBufferIncrementCounter(std::string shardId, std::string id_);
    virtual void ShardedBufferIncrementCounter(std::string shardId, std::string id_, uint64_t counts);
    virtual void ShardedBufferIncrementCounter(std::string shardId, std::string id_, uint64_t counts, vector<pair<string, string>>& labels);

    virtual void ShardedBufferUpdateGauge(std::string shardId, std::string id_, uint64_t currValue);
    virtual void ShardedBufferUpdateGauge(std::string shardId, std::string id_, uint64_t currValue, vector<pair<string, string>>& labels);
private:
    virtual void _PeriodicPublish();
    virtual void _PeriodicPublish(std::string& shardId);
    int _PublishMap(tbb::concurrent_unordered_map<std::string, int64_t>& map, POSMetricTypes metricType);
    void _PublishMetricsWithLabels(tbb::concurrent_unordered_map<size_t, POSMetric>& map, pthread_rwlock_t& metricLock);
    void _PublishMetricsWithLabelsWithNonTBB(MetricMap& map, pthread_rwlock_t& metricLock);

    void _Report();
    void _ShardedBufferUpdateMetric(std::string shardId, POSMetricTypes metricType, std::string id_, uint64_t value, vector<pair<string, string>>& labels);

    TelemetryPublisher* publisher = nullptr;

    tbb::concurrent_unordered_map<size_t, POSMetric> counters_with_labels;
    tbb::concurrent_unordered_map<size_t, POSMetric> gauges_with_labels;
    tbb::concurrent_unordered_map<std::string, MetricMap> shardedMetricMap; // for both counter & gauge. use it at your own risk.
    tbb::concurrent_unordered_map<std::string, pthread_rwlock_t*> shardedMetricLock;
    //tbb::concurrent_unordered_map<size_t, POSMetric> metrics_by_single_writer;

    std::atomic<uint64_t> count_buffered_counter {0};
    std::atomic<uint64_t> count_buffered_gauge {0};
    pthread_rwlock_t counterLock;
    pthread_rwlock_t gaugeLock;
    pthread_rwlock_t singleWriterPublishLock;
};

using EasyTelemetryPublisherSingleton = Singleton<EasyTelemetryPublisher>;

}
