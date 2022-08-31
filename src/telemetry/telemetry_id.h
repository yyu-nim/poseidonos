/*
 *   BSD LICENSE
 *   Copyright (c) 2021 Samsung Electronics Corporation
 *   All rights reserved.
 *
 *   Redistribution and use in source and binary forms, with or without
 *   modification, are permitted provided that the following conditions
 *   are met:
 *
 *     * Redistributions of source code must retain the above copyright
 *       notice, this list of conditions and the following disclaimer.
 *     * Redistributions in binary form must reproduce the above copyright
 *       notice, this list of conditions and the following disclaimer in
 *       the documentation and/or other materials provided with the
 *       distribution.
 *     * Neither the name of Samsung Electronics Corporation nor the names of
 *       its contributors may be used to endorse or promote products derived
 *       from this software without specific prior written permission.
 *
 *   THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS
 *   "AS IS" AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT
 *   LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR
 *   A PARTICULAR PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT
 *   OWNER OR CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL,
 *   SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT
 *   LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE,
 *   DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY
 *   THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT
 *   (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE
 *   OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
 */
#pragma once

#include <string>
namespace pos
{
#define MAX_NUM_METRICLIST 1000
#define MAX_NUM_LABEL 100
#define TEL_PUBNAME_LABEL_KEY "publisher_name"
#define TEL_RUNID_LABEL_KEY "run_id"

// ID = "modulecode_itemname_collectiontype(count/history)"

static const std::string TEL05000_COMMON_PROCESS_UPTIME_SECOND = "common_process_uptime_second";

static const std::string TEL20000_READ_IOPS_DEVICE = "read_iops_device";
static const std::string TEL20001_READ_BPS_DEVICE = "read_bps_device";
static const std::string TEL20010_WRITE_IOPS_DEVICE = "write_iops_device";
static const std::string TEL20011_WRITE_BPS_DEVICE = "write_bps_device";

static const std::string TEL30000_ALCT_FREE_SEG_CNT = "alct_free_seg_cnt";
static const std::string TEL30001_ALCT_ALCTX_PENDINGIO_CNT = "alct_allocctx_pendio_cnt";
static const std::string TEL30002_ALCT_GCVICTIM_SEG = "alct_gcvictim_segid";
static const std::string TEL30003_ALCT_GCMODE = "alct_gcmode";
static const std::string TEL30004_ALCT_RSV = "rsv";
static const std::string TEL30005_ALCT_RSV = "rsv";
static const std::string TEL30006_ALCT_RSV = "rsv";
static const std::string TEL30007_ALCT_RSV = "rsv";
static const std::string TEL30008_ALCT_RSV = "rsv";
static const std::string TEL30009_ALCT_RSV = "rsv";
static const std::string TEL30010_ALCT_VICTIM_SEG_INVALID_PAGE_CNT = "alct_victim_invalidpg_cnt";
static const std::string TEL30011_ALCT_PROHIBIT_USERBLK_ALLOCATION_ONOFF = "alct_prohibit_userblk_alloc_onoff";

static const std::string TEL33000_MAP_RSV = "rsv";
static const std::string TEL33001_MAP_RSV = "rsv";
static const std::string TEL33002_MAP_LOADED_VOL_CNT = "map_loaded_int_volid";
static const std::string TEL33003_MAP_RSV = "rsv";
static const std::string TEL33004_MAP_UNMOUNTED_VOL = "map_unmounted_volid";
static const std::string TEL33005_MAP_RSV = "rsv";
static const std::string TEL33006_MAP_MOUNTED_VOL_CNT = "map_mounted_volume_cnt";
static const std::string TEL33007_MAP_VSA_LOAD_PENDINGIO_CNT = "map_vsa_load_pendio_cnt";
static const std::string TEL33008_MAP_VSA_FLUSH_PENDINGIO_CNT = "map_vsa_flush_pendio_cnt";
static const std::string TEL33009_MAP_STRIPE_FLUSH_PENDINGIO_CNT = "map_stripe_flush_pendio_cnt";
static const std::string TEL33010_MAP_VSA_FLUSHED_DIRTYPAGE_CNT = "map_vsa_flushed_dirtypg_cnt";
static const std::string TEL33011_MAP_REVERSE_FLUSH_IO_ISSUED_CNT = "map_reverse_flush_io_issued_cnt";
static const std::string TEL33012_MAP_REVERSE_FLUSH_IO_DONE_CNT = "map_reverse_flush_io_done_cnt";
static const std::string TEL33013_MAP_REVERSE_LOAD_IO_ISSUED_CNT = "map_reverse_load_io_issued_cnt";
static const std::string TEL33014_MAP_REVERSE_LOAD_IO_DONE_CNT = "map_reverse_load_io_done_cnt";
static const std::string TEL33015_REVMAPPACK_CREATED = "revmappack_created";
static const std::string TEL33015_REVMAPPACK_DESTROYED = "revmappack_destroyed";
static const std::string TEL33015_REVMAPPACK_INIT = "revmappack_init";
static const std::string TEL33015_REVMAPPACK_ASSIGN = "revmappack_assign";
static const std::string TEL33015_REVMAPPACK_LOAD = "revmappack_load";
static const std::string TEL33015_REVMAPPACK_FAILED_TO_ISSUE_LOAD_CNT       = "revmappack_failed_to_issue_load";
static const std::string TEL33015_REVMAPPACK_SUCCEEDED_TO_ISSUE_LOAD_CNT    = "revmappack_succeeded_to_issue_load";
static const std::string TEL33015_REVMAPPACK_FAILED_TO_ISSUE_FLUSH_CNT      = "revmappack_failed_to_issue_flush";
static const std::string TEL33015_REVMAPPACK_SUCCEEDED_TO_ISSUE_FLUSH_CNT   = "revmappack_succeeded_to_issue_flush";
static const std::string TEL33015_REVMAPPACK_WAITING_PENDING_IO_ENTER_CNT   = "revmappack_waiting_pending_io_enter_cnt";
static const std::string TEL33015_REVMAPPACK_WAITING_PENDING_IO_EXIT_CNT    = "revmappack_waiting_pending_io_exit_cnt";
static const std::string TEL33015_REVMAPPACK_REVMAP_PAGE_IO_DONE_ERROR      = "revmappack_revmap_page_io_done_error_cnt";
static const std::string TEL33015_REVMAPPACK_REVMAP_PAGE_IO_DONE_BEFORE_LAST= "revmappack_revmap_page_io_done_before_last_cnt";
static const std::string TEL33015_REVMAPPACK_REVMAP_PAGE_IO_DONE_ENQ_CALLBACK   = "revmappack_revmap_page_io_done_enqueue_callback";
static const std::string TEL33015_REVMAPPACK_REVMAP_PAGE_IO_DONE_CALLBACK_NULL  = "revmappack_revmap_page_io_done_null_callback";

static const std::string TEL34000_GC_COPIER_EVENT_STATE = "gc_copier_event_state";
static const std::string TEL34000_GC_COPIER_CREATED = "gc_copier_created_cnt";
static const std::string TEL34000_GC_COPIER_DESTROYED = "gc_copier_destroyed_cnt";
static const std::string TEL34000_GC_COPIER_EXECUTE = "gc_copier_execute_cnt";
static const std::string TEL34000_GC_COPIER_EXECUTE_B1 = "gc_copier_execute_b1_cnt";
static const std::string TEL34000_GC_COPIER_EXECUTE_B2 = "gc_copier_execute_b2_cnt";
static const std::string TEL34000_GC_COPIER_EXECUTE_B3 = "gc_copier_execute_b3_cnt";
static const std::string TEL34000_GC_COPIER_EXECUTE_B4 = "gc_copier_execute_b4_cnt";
static const std::string TEL34000_GC_COPIER_EXECUTE_DEFAULT = "gc_copier_execute_default_cnt";

static const std::string TEL34000_GC_COPIER_VICTIMCOPY_NOTDONE = "gc_copier_victimcopy_notdone_cnt";
static const std::string TEL34000_GC_COPIER_STRIPEMGR_FLUSH_NOTDONE = "gc_copier_stripemgr_flush_notdone_cnt";
static const std::string TEL34000_GC_COPIER_PAUSE_RETURN = "gc_copier_pause_return_cnt";
static const std::string TEL34000_GC_COPIER_STOP_RETURN = "gc_copier_stop_return_cnt";
static const std::string TEL34000_GC_COPIER_COMPARE_PREPARE = "gc_copier_compare_prepare_cnt";
static const std::string TEL34000_GC_COPIER_GCMODE = "gc_copier_gcmode";
static const std::string TEL34000_GC_COPIER_VICTIM_SEG_UNMAPPED = "gc_copier_victimseg_unmapped_cnt";
static const std::string TEL34000_GC_COPIER_COPY_INCOMPLETE_META_NOTSYNC = "gc_copier_copy_incomplete_meta_notsync";
static const std::string TEL34000_GC_COPIER_NOTSYNC_BUT_COPYDONE_CNT = "gc_copier_notsync_copydone_cnt";

static const std::string TEL34001_GC_COPIERMETA_CREATED = "gc_copiermeta_created_cnt";
static const std::string TEL34001_GC_COPIERMETA_DESTROYED = "gc_copiermeta_destroyed_cnt";
static const std::string TEL34001_GC_COPIERMETA_REQUEST_BLK_CNT = "gc_copiermeta_request_blk_cnt";
static const std::string TEL34001_GC_COPIERMETA_REQUEST_STRIPE_CNT = "gc_copiermeta_request_stripe_cnt";
static const std::string TEL34001_GC_COPIERMETA_DONE_BLK_CNT = "gc_copiermeta_done_blk_cnt";
static const std::string TEL34001_GC_COPIERMETA_REQUEST_STRIPECNT_NOMATCH = "gc_copiermeta_request_stripecnt_nomatch";
static const std::string TEL34001_GC_COPIERMETA_REQUEST_DONE_NOMATCH = "gc_copiermeta_request_done_nomatch";
static const std::string TEL34001_GC_COPIERMETA_VICTIM_SEG_IDX = "gc_copiermeta_victim_seg_idx";

static const std::string TEL34002_SEGMENTCTX_ALLOC_GCVICTIM_LOOP = "segmentctx_alloc_gc_victim_loop_cnt";

static const std::string TEL34003_COPIERREADCOMPLETION_CREATED = "copierreadcomp_created";
static const std::string TEL34003_COPIERREADCOMPLETION_DESTROYED = "copierreadcomp_destroyed";
static const std::string TEL34003_COPIERREADCOMPLETION_DO_JOB = "copierreadcomp_do_job";
static const std::string TEL34003_COPIERREADCOMPLETION_DO_JOB_ELAPSED_MILLI = "copierreadcomp_elapsed_milli";
static const std::string TEL34003_COPIERREADCOMPLETION_FAILED_TO_ALLOCATE_BLKS = "copierreadcomp_failed_to_allocate_blks";
static const std::string TEL34003_COPIERREADCOMPLETION_BLKS_CNT_DONE = "copierreadcomp_blks_done_cnt";

static const std::string TEL34004_GCFLUSHSUBMISSION_OUT_OF_TOKEN = "gcflushsubmission_out_of_token";
static const std::string TEL34004_GCFLUSHSUBMISSION_FAILED_TO_ALLOC_STRIPE = "gcflushsubmission_failed_to_alloc_stripe";
static const std::string TEL34004_GCFLUSHSUBMISSION_CREATED = "gcflushsubmission_created";
static const std::string TEL34004_GCFLUSHSUBMISSION_DESTROYED = "gcflushsubmission_destroyed";
static const std::string TEL34004_GCFLUSHSUBMISSION_ASYNCIO_CNT = "gcflushsubmission_asyncio_cnt";

static const std::string TEL34005_GCFLUSHCOMPLETION_CREATED = "gcflushcompletion_created";
static const std::string TEL34005_GCFLUSHCOMPLETION_DESTROYED = "gcflushcompletion_destroyed";
static const std::string TEL34005_GCFLUSHCOMPLETION_FAILED_TO_ACQUIRE_OWNERSHIP = "gcflushcompletion_failed_to_acquire_ownership";
static const std::string TEL34005_GCFLUSHCOMPLETION_SUCCESS = "gcflushcompletion_success_cnt";

static const std::string TEL34006_REVMAP_LOAD_CNT = "reverse_map_load_cnt";
static const std::string TEL34007_STRIPECOPIER_READ_CNT = "stripecopier_read_cnt";

static const std::string TEL34008_UBLOCKDEV_DEVICECTX_EXIST_CNT = "ublockdevice_devicectx_exists_cnt";
static const std::string TEL34008_UBLOCKDEV_DEVICECTX_NULL_CNT = "ublockdevice_devicectx_null_cnt";
static const std::string TEL34008_UBLOCKDEV_COMPLETE_IO_CNT = "ublockdevice_devicectx_complete_io_cnt";
static const std::string TEL34008_UBLOCKDEV_COMPLETE_ERRORS_CNT = "ublockdevice_devicectx_complete_errors_cnt";
static const std::string TEL34008_UBLOCKDEV_PENDING_IO_CNT = "ublockdevice_pending_io_cnt";
static const std::string TEL34008_UBLOCKDEV_PENDING_ERROR_CNT = "ublockdevice_pending_error_cnt";

static const std::string TEL34009_FLOWCONTROL_USERBUCKET_TOKEN = "flowcontrol_userbucket_token";
static const std::string TEL34009_FLOWCONTROL_GCBUCKET_TOKEN = "flowcontrol_gcbucket_token";
static const std::string TEL34009_FLOWCONTROL_WAITFOR_PEER_TOKENCONSUMPTION = "flowcontrol_waitfor_peer_token_consumption";
static const std::string TEL34009_FLOWCONTROL_RUN_OUT_OF_MY_TOKEN = "flowcontrol_run_out_of_my_token";
static const std::string TEL34009_FLOWCONTROL_REFILLCONFLICT_RETURN = "flowcontrol_refillconflict_return";
static const std::string TEL34009_FLOWCONTROL_POSITIVE_OLDBUCKET_TOKEN = "flowcontrol_positive_oldbucket_token";
static const std::string TEL34009_FLOWCONTROL_NEGATIVE_NEWBUCKET_TOKEN = "flowcontrol_negative_newbucket_token";
static const std::string TEL34009_FLOWCONTROL_OLDBUCKET_USER_TOKEN = "flowcontrol_oldbucket_user_token";
static const std::string TEL34009_FLOWCONTROL_OLDBUCKET_GC_TOKEN = "flowcontrol_oldbucket_gc_token";
static const std::string TEL34009_FLOWCONTROL_RETURN_USERTOKEN = "flowcontrol_return_usertoken";
static const std::string TEL34009_FLOWCONTROL_RETURN_GCTOKEN = "flowcontrol_return_gctoken";
static const std::string TEL34009_FLOWCONTROL_REFILL_USERTOKEN = "flowcontrol_refill_usertoken";
static const std::string TEL34009_FLOWCONTROL_REFILL_GCTOKEN = "flowcontrol_refill_gctoken";
static const std::string TEL34009_FLOWCONTROL_RESET_PREVBUCKET_USERTOKEN = "flowcontrol_reset_prevbucket_usertoken";
static const std::string TEL34009_FLOWCONTROL_RESET_PREVBUCKET_GCTOKEN = "flowcontrol_reset_prevbucket_gctoken";
static const std::string TEL34009_FLOWCONTROL_RESET_CURRBUCKET_USERTOKEN = "flowcontrol_reset_currbucket_usertoken";
static const std::string TEL34009_FLOWCONTROL_RESET_CURRBUCKET_GCTOKEN = "flowcontrol_reset_currbucket_gctoken";
static const std::string TEL34009_FLOWCONTROL_RESET_COUNTER_TYPE = "flowcontrol_reset_counter_type";
static const std::string TEL34009_FLOWCONTROL_RESET_UPDATE_PREVBUCKET_RETURN = "flowcontrol_reset_update_prevbucket_return";
static const std::string TEL34009_FLOWCONTROL_RESET_SET_TIMEOUT_RETURN = "flowcontrol_reset_set_timeout_return";
static const std::string TEL34009_FLOWCONTROL_RESET_NOTIMEOUT_YET_RETURN = "flowcontrol_reset_notimeout_yet_return";
static const std::string TEL34009_FLOWCONTROL_RESET_SUCCESSFUL = "flowcontrol_reset_successful_cnt";

static const std::string TEL36000_JRN_ = "j_test";
static const std::string TEL36001_JRN_CHECKPOINT = "jrn_checkpoint";
static const std::string TEL36002_JRN_LOG_GROUP_RESET_CNT = "jrn_log_group_reset_cnt";
static const std::string TEL36003_JRN_LOG_GROUP_RESET_DONE_CNT = "jrn_log_group_reset_done_cnt";
static const std::string TEL36004_JRN_LOAD_LOG_GROUP = "jrn_load_log_group";
static const std::string TEL36005_JRN_LOG_COUNT = "jrn_log_count";
static const std::string TEL36005_JRN_LOG_WRITE_LOG_SUCCESS = "jrn_log_write_log_success_count";
static const std::string TEL36005_JRN_LOG_FAILED_TO_WRITE = "jrn_log_failed_to_write_count";
static const std::string TEL36005_JRN_LOG_FAILED_TO_ALLOC_BUF = "jrn_log_failed_to_alloc_buf_count";
static const std::string TEL36006_JRN_LOG_DONE_COUNT = "jrn_log_done_count";
static const std::string TEL36006_JRN_LOG_DONE_COUNT_EASY = "jrn_log_done_count_easytel";
static const std::string TEL36006_JRN_LOG_DONE_WITH_ERR_COUNT_EASY = "jrn_log_done_with_err_count_easytel";
static const std::string TEL36006_JRN_LOG_DONE_NULLCTX_COUNT_EASY = "jrn_log_done_nullctx_count_easytel";
static const std::string TEL36007_JRN_LOG_WRITE_TIME_AVERAGE = "jrn_log_write_time_average";
static const std::string TEL36008_JRN_BLOCK_LOG_WRITE_FAILED = "jrn_gc_block_log_write_failed";
static const std::string TEL36009_JRN_STRIPE_LOG_WRITE_FAILED = "jrn_stripe_log_write_failed";
static const std::string TEL36010_JRN_GC_LOG_WRITE_FAILED = "jrn_gc_log_write_failed";
static const std::string TEL39999_JRN_ = "j_test_end";

static const std::string TEL40000_METAFS_NORMAL_SHUTDOWN = "normal_shutdown_npor";
static const std::string TEL40010_METAFS_USER_REQUEST = "user_request";
static const std::string TEL40011_METAFS_USER_REQUEST_CNT = "user_request_cnt";
static const std::string TEL40012_METAFS_USER_REQUEST_PUBLISH_CNT_PER_INTERVAL = "user_request_publish_cnt_per_interval";
static const std::string TEL40013_METAFS_FILE_CREATE_REQUEST = "meta_file_create_request";
static const std::string TEL40014_METAFS_FILE_OPEN_REQUEST = "meta_file_open_request";
static const std::string TEL40015_METAFS_FILE_CLOSE_REQUEST = "meta_file_close_request";
static const std::string TEL40016_METAFS_FILE_DELETE_REQUEST = "meta_file_delete_request";
static const std::string TEL40100_METAFS_SCHEDULER_ISSUE_COUNT_TO_SSD = "metafs_scheduler_issued_request_count_to_ssd";
static const std::string TEL40101_METAFS_SCHEDULER_ISSUE_COUNT_TO_NVRAM = "metafs_scheduler_issued_request_count_to_nvram";
static const std::string TEL40102_METAFS_SCHEDULER_ISSUE_COUNT_TO_JOURNAL_SSD = "metafs_scheduler_issued_request_count_to_journal_ssd";
static const std::string TEL40103_METAFS_WORKER_ISSUE_COUNT_PARTITION = "metafs_worker_issued_request_count_partition";
static const std::string TEL40104_METAFS_WORKER_DONE_COUNT_PARTITION = "metafs_worker_done_request_count_partition";
static const std::string TEL40105_METAFS_WORKER_ISSUE_COUNT_FILE_TYPE = "metafs_worker_issued_request_count_file_type";
static const std::string TEL40106_METAFS_WORKER_DONE_COUNT_FILE_TYPE = "metafs_worker_done_request_count_file_type";
static const std::string TEL40200_METAFS_FREE_MIO_CNT = "free_mio_count";
static const std::string TEL40201_METAFS_MPIO_TIME_SPENT_PROCESSING_ALL_STAGES = "sampled_mpio_time_spent_all_stages";
static const std::string TEL40202_METAFS_PROCESSED_MPIO_COUNT = "processed_mpio_count";
static const std::string TEL40203_METAFS_MIO_TIME_FROM_ISSUE_TO_COMPLETE = "sampled_mio_time_from_issue_to_complete";
static const std::string TEL40204_METAFS_MIO_SAMPLED_COUNT = "sampled_mio_count";
static const std::string TEL40205_METAFS_MIO_HANDLER_IS_WORKING = "mio_handler_is_working";
static const std::string TEL40300_METAFS_FREE_MPIO_CNT = "free_mpio_count";
static const std::string TEL40301_METAFS_MIO_TIME_SPENT_PROCESSING_ALL_STAGES = "sampled_mio_time_spent_all_stages";
static const std::string TEL40302_METAFS_PROCESSED_MIO_COUNT = "processed_mio_count";
static const std::string TEL40303_METAFS_MPIO_TIME_FROM_WRITE_TO_RELEASE = "sampled_mpio_time_from_write_to_release";
static const std::string TEL40304_METAFS_MPIO_TIME_FROM_PUSH_TO_POP = "sampled_mpio_time_from_push_to_pop";
static const std::string TEL40305_METAFS_MPIO_SAMPLED_COUNT = "sampled_mpio_count";

static const std::string TEL40306_METAFS_SCHEDULER_ENQUEUE_IOSQ_TYPE = "metafs_scheduler_enqueue_iosq";
static const std::string TEL40306_METAFS_SCHEDULER_DEQUEUE_IOSQ_TYPE = "metafs_scheduler_dequeue_iosq";
static const std::string TEL40306_METAFS_MIOHANDLER_ENQUEUE_IOSQ_TYPE = "metafs_miohandler_enqueue_iosq";
static const std::string TEL40306_METAFS_MIOHANDLER_DEQUEUE_IOSQ_TYPE = "metafs_miohandler_dequeue_iosq";
static const std::string TEL40306_METAFS_MIOHANDLER_ENQUEUE_IOCQ_TYPE = "metafs_miohandler_enqueue_iocq";
static const std::string TEL40306_METAFS_MIOHANDLER_DEQUEUE_IOCQ_TYPE = "metafs_miohandler_dequeue_iocq";
static const std::string TEL40306_METAFS_MPIOHANDLER_ENQUEUE_PARITIALQ_CORE = "metafs_mpiohandler_enqueue_partialq";
static const std::string TEL40306_METAFS_MPIOHANDLER_DEQUEUE_PARITIALQ_CORE = "metafs_mpiohandler_dequeue_partialq";

static const std::string TEL50000_READ_IOPS_VOLUME = "read_iops_volume";
static const std::string TEL50001_READ_BPS_VOLUME = "read_bps_volume";
static const std::string TEL50002_READ_AVG_LAT_VOLUME = "read_avg_lat_volume";
static const std::string TEL50010_WRITE_IOPS_VOLUME = "write_iops_volume";
static const std::string TEL50011_WRITE_BPS_VOLUME = "write_bps_volume";
static const std::string TEL50012_WRITE_AVG_LAT_VOLUME = "write_avg_lat_volume";
static const std::string TEL50020_VOL_VOLUME_STATE = "volume_state";
static const std::string TEL50021_VOL_VOLUME_TOTAL_CAPACITY= "volume_total_capacity";
static const std::string TEL50022_VOL_VOLUME_USED_CAPACITY = "volume_used_capacity";

static const std::string TEL60001_ARRAY_STATUS = "array_status";
static const std::string TEL60002_ARRAY_USAGE_BLK_CNT = "array_usage_cnt";
static const std::string TEL60003_VOL_USAGE_BLK_CNT = "volume_usage_cnt";
static const std::string TEL60004_ARRAY_CAPACITY_TOTAL = "array_capacity_total";
static const std::string TEL60005_ARRAY_CAPACITY_USED = "array_capacity_used";

static const std::string TEL70000_READ_IOPS_NETWORK = "read_iops_network";
static const std::string TEL70001_READ_BPS_NETWORK = "read_bps_network";
static const std::string TEL70010_WRITE_IOPS_NETWORK = "write_iops_network";
static const std::string TEL70011_WRITE_BPS_NETWORK = "write_bps_network";

static const std::string TEL80000_DEVICE_PENDING_IO_COUNT = "device_pending_io_count";
static const std::string TEL80001_DEVICE_PENDING_IO_COUNT_NEG = "device_pending_io_count_neg";

static const std::string TEL100000_RESOURCE_CHECKER_AVAILABLE_MEMORY = "available_memory_size";

static const std::string TEL110000_MEDIA_ERROR_COUNT_LOWER = "soft_media_error_lower";
static const std::string TEL110001_MEDIA_ERROR_COUNT_UPPER = "soft_media_error_upper";
static const std::string TEL110002_POWER_CYCLE_LOWER = "power_cycle_lower";
static const std::string TEL110003_POWER_CYCLE_UPPER = "power_cycle_upper";
static const std::string TEL110004_POWER_ON_HOUR_LOWER = "power_on_hour_lower";
static const std::string TEL110005_POWER_ON_HOUR_UPPER = "power_on_hour_upper";
static const std::string TEL110006_UNSAFE_SHUTDOWNS_LOWER = "unsafe_shutdowns_lower";
static const std::string TEL110007_UNSAFE_SHUTDOWNS_UPPER = "unsafe_shutdowns_upper";
static const std::string TEL110008_TEMPERATURE = "temperature";
static const std::string TEL110009_AVAILABLE_SPARE = "available_spare";
static const std::string TEL110010_AVAILABLE_SPARE_THRESHOLD = "available_spare_threshold";
static const std::string TEL110011_PERCENTAGE_USED = "percentage_used";
static const std::string TEL110012_CONTROLLER_BUSY_TIME_LOWER = "controller_busy_time_lower";
static const std::string TEL110013_CONTROLLER_BUSY_TIME_UPPER = "controller_busy_time_upper";
static const std::string TEL110014_WARNING_TEMP_TIME = "warning_temperature_time";
static const std::string TEL110015_CRITICAL_TEMP_TIME = "critical_temperature_time";
static const std::string TEL110020_LIFETIME_WAF = "lifetime_waf";
static const std::string TEL110021_HOUR_WAF = "trailing_hour_waf";
static const std::string TEL110022_TRIM_SECTOR_COUNT_LOWER = "trim_sector_count_lower";
static const std::string TEL110023_TRIM_SECTOR_COUNT_UPPER = "trim_sector_count_upper";
static const std::string TEL110024_HOST_WRITTEN_COUNT_LOWER = "host_written_count_lower";
static const std::string TEL110025_HOST_WRITTEN_COUNT_UPPER = "host_written_count_upper";
static const std::string TEL110026_NAND_WRITTEN_COUNT_LOWER = "nand_written_count_lower";
static const std::string TEL110027_NAND_WRITTEN_COUNT_UPPER = "nand_written_count_upper";
static const std::string TEL110028_THERMAL_THROTTLE_EVNET_COUNT = "thermal_throttle_event_count";
static const std::string TEL110029_HIGHEST_TEMPERATURE = "highest_temperature";
static const std::string TEL110030_LOWEST_TEMPERATURE = "lowest_temeperature";
static const std::string TEL110031_OVER_TEMPERATURE_COUNT = "over_temperature_count";
static const std::string TEL110032_UNDER_TEMPERATURE_COUNT = "under_temperature_count";

static const std::string TEL120001_READ_IOPS_PER_PORT = "read_iops_per_port";
static const std::string TEL120002_READ_RATE_BYTES_PER_SECOND_PER_PORT = "read_rate_bytes_per_second_per_port";
static const std::string TEL120011_WRITE_IOPS_PER_PORT = "write_iops_per_port";
static const std::string TEL120012_WRITE_RATE_BYTES_PER_SECOND_PER_PORT = "write_rate_bytes_per_second_per_port";

static const std::string TEL130001_COUNT_OF_VOLUME_IO_CONSTRUCTORS = "count_of_volume_io_constructors";
static const std::string TEL130002_COUNT_OF_VOLUME_IO_DESTRUCTORS = "count_of_volume_io_destructors";
static const std::string TEL130003_COUNT_OF_UBIO_CONSTRUCTORS = "count_of_ubio_constructors";
static const std::string TEL130004_COUNT_OF_UBIO_DESTRUCTORS = "count_of_ubio_destructors";
static const std::string TEL130005_SUBMISSION_COUNT_OF_SSD_IOS = "submission_count_of_ssd_ios";
static const std::string TEL130006_COMPLETION_COUNT_OF_SSD_IOS = "completion_count_of_ssd_ios";
static const std::string TEL130007_PUSHING_COUNT_OF_EVENT_QUEUE = "pushing_count_of_event_queue";
static const std::string TEL130008_PUSHING_COUNT_OF_WORKER_COMMON_QUEUE = "pushing_count_of_worker_common_queue";
static const std::string TEL130009_POPPING_COUNT_OF_WORKER_COMMON_QUEUE = "popping_count_of_worker_common_queue";
static const std::string TEL130010_COUNT_OF_CALLBACK_CONSTRUCTORS = "count_of_callback_contructors";
static const std::string TEL130011_COUNT_OF_CALLBACK_DESTRUCTORS = "count_of_callback_destructors";
static const std::string TEL130012_COUNT_OF_EVENT_CONSTRUCTORS = "count_of_event_contructors";
static const std::string TEL130013_COUNT_OF_EVENT_DESTRUCTORS = "count_of_event_destructors";
static const std::string TEL130014_SUBMISSION_COUNT_IN_IO_WORKER = "submission_count_in_io_worker";
static const std::string TEL130015_COMPLETION_COUNT_IN_IO_WORKER = "completion_count_in_io_worker";

static const std::string TEL130016_EVENTWORKER_RETRY_CNT = "eventworker_event_retry_cnt";
static const std::string TEL130016_EVENTWORKER_SUCCESS_CNT = "eventworker_event_success_cnt";
static const std::string TEL130017_BE_RATIO_POLICY_CURR_EVENT_CNT_GAUGE = "be_ratio_policy_curr_event_cnt";
static const std::string TEL130017_BE_RATIO_POLICY_ENQ_CNT = "be_ratio_policy_enqueue_cnt";
static const std::string TEL130018_BE_RATIO_POLICY_DEQ_CNT = "be_ratio_policy_dequeue_cnt";
static const std::string TEL130019_BE_RATIO_POLICY_QUEUE_OCCUPIED = "be_ratio_policy_queue_occupied";
static const std::string TEL130019_BE_RATIO_POLICY_INIT_LIMITS_ALLOWED_EVENTS = "be_ratio_policy_init_limits_allowed_event_cnt";
static const std::string TEL130019_BE_RATIO_POLICY_INIT_LIMITS_ALLOWED_IOS = "be_ratio_policy_init_limits_allowed_io_cnt";
static const std::string TEL130019_BE_RATIO_POLICY_SET_ALLOWED_EVENTS = "be_ratio_policy_set_allowed_event_cnt";
static const std::string TEL130019_BE_RATIO_POLICY_SET_ALLOWED_IOS = "be_ratio_policy_set_allowed_io_cnt";
static const std::string TEL130019_BE_RATIO_POLICY_QOS_FAILURE = "be_ratio_policy_qos_failure_return";
static const std::string TEL130019_BE_RATIO_POLICY_WORKER_COMMON_QUEUE_PUSH = "be_ratio_policy_worker_common_queue_push";
static const std::string TEL130019_BE_RATIO_POLICY_WORKER_COMMON_QUEUE_POP = "be_ratio_policy_worker_common_queue_pop";
static const std::string TEL130020_EVENT_SCHEDULER_POLICY_ENQ = "eventscheduler_policy_enqueue_event";
static const std::string TEL130020_EVENT_SCHEDULER_EVENT_REACTOR_ENQ = "eventscheduler_event_reactor_enqueue_event";

static const std::string TEL140000_COUNT_OF_REQUSTED_USER_READ = "count_of_requested_user_read";
static const std::string TEL140001_COUNT_OF_REQUSTED_USER_WRITE = "count_of_requested_user_write";
static const std::string TEL140002_COUNT_OF_REQUSTED_USER_ADMINIO = "count_of_requested_user_adminio";
static const std::string TEL140003_COUNT_OF_COMPLETE_USER_READ = "count_of_complete_user_read";
static const std::string TEL140004_COUNT_OF_COMPLETE_USER_WRITE = "count_of_complete_user_write";
static const std::string TEL140005_COUNT_OF_COMPLETE_USER_ADMINIO = "count_of_complete_user_adminio";
static const std::string TEL140006_COUNT_OF_USER_FLUSH_PROCESS = "count_of_user_flush_process";
static const std::string TEL140007_COUNT_OF_PARTIAL_WRITE_PROCESS = "count_of_partial_write_process";
static const std::string TEL140008_COUNT_OF_USER_FAIL_IO = "count_of_user_fail_io";
static const std::string TEL140009_COUNT_OF_USER_READ_PENDING_CNT = "count_of_user_read_pending_cnt";
static const std::string TEL140010_COUNT_OF_USER_WRITE_PENDING_CNT = "count_of_user_write_pending_cnt";
static const std::string TEL140011_COUNT_OF_INTERNAL_IO_PENDING_CNT = "count_of_internal_io_pending_cnt";
static const std::string TEL140012_EVENTQ_AGV_QD = "event_queue_average_qd";
static const std::string TEL140013_EVENTQ_MAX_QD = "event_queue_max_qd";
static const std::string TEL140014_IOQ_AGV_QD = "io_queue_average_qd";
static const std::string TEL140015_IOQ_MAX_QD = "io_queue_max_qd";
static const std::string TEL140016_COUNT_OF_INTERNAL_IO_PENDING_CNT_NEG = "count_of_internal_io_pending_cnt_neg";
static const std::string TEL140017_COUNT_OF_USER_READ_PENDING_CNT_NEG = "count_of_user_read_pending_cnt_neg";
static const std::string TEL140018_COUNT_OF_USER_WRITE_PENDING_CNT_NEG = "count_of_user_write_pending_cnt_neg";
static const std::string TEL140012_COUNT_OF_TIMEOUT_IO_CNT = "count_of_timeout_io_cnt";

} // namespace pos
