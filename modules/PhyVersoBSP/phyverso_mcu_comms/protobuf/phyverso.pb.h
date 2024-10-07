/* Automatically generated nanopb header */
/* Generated by nanopb-0.4.9 */

#ifndef PB_PHYVERSO_PB_H_INCLUDED
#define PB_PHYVERSO_PB_H_INCLUDED
#include <everest/3rd_party/nanopb/pb.h>

#if PB_PROTO_HEADER_VERSION != 40
#error Regenerate this file with the current version of nanopb generator.
#endif

/* Enum definitions */
typedef enum _CpState {
    CpState_STATE_A = 0,
    CpState_STATE_B = 1,
    CpState_STATE_C = 2,
    CpState_STATE_D = 3,
    CpState_STATE_E = 4,
    CpState_STATE_F = 5
} CpState;

typedef enum _ResetReason {
    ResetReason_USER = 0,
    ResetReason_WATCHDOG = 1
} ResetReason;

typedef enum _PpState {
    PpState_STATE_NC = 0,
    PpState_STATE_13A = 1,
    PpState_STATE_20A = 2,
    PpState_STATE_32A = 3,
    PpState_STATE_70A = 4,
    PpState_STATE_FAULT = 5
} PpState;

typedef enum _LockState {
    LockState_UNDEFINED = 0,
    LockState_UNLOCKED = 1,
    LockState_LOCKED = 2
} LockState;

typedef enum _CoilType {
    CoilType_COIL_UNKNOWN = 0,
    CoilType_COIL_AC = 1,
    CoilType_COIL_DC1 = 2,
    /* add precharge and discharge coils here later */
    CoilType_COIL_DC2 = 3,
    CoilType_COIL_DC3 = 4
} CoilType;

typedef enum _ConfigHardwareRevision {
    ConfigHardwareRevision_HW_REV_UNKNOWN = 0,
    ConfigHardwareRevision_HW_REV_A = 1,
    ConfigHardwareRevision_HW_REV_B = 2
} ConfigHardwareRevision;

typedef enum _MotorLockType {
    MotorLockType_MOTOR_LOCK_UNKNOWN = 0,
    MotorLockType_MOTOR_LOCK_QWELLO = 1,
    MotorLockType_MOTOR_LOCK_DEBUG_VALEO_HVAC = 2
} MotorLockType;

/* Struct definitions */
typedef struct _ErrorFlags {
    bool diode_fault;
    bool rcd_selftest_failed;
    bool rcd_triggered;
    bool ventilation_not_available;
    bool connector_lock_failed;
    bool cp_signal_fault;
    bool contactor_error;
} ErrorFlags;

typedef struct _KeepAlive {
    uint32_t time_stamp;
    uint32_t hw_type;
    uint32_t hw_revision;
    char sw_version_string[51];
} KeepAlive;

typedef struct _Telemetry {
    uint32_t cp_voltage_hi;
    uint32_t cp_voltage_lo;
} Telemetry;

typedef struct _FanState {
    uint8_t fan_id;
    bool enabled;
    uint32_t duty; /* in 0.1%, 1000 = 100% */
    uint16_t rpm;
} FanState;

typedef struct _CoilState {
    CoilType coil_type;
    bool coil_state; /* true -> on; false -> off */
} CoilState;

typedef struct _BootConfigRequest { /* TODO */
    char dummy_field;
} BootConfigRequest;

typedef struct _ConfigMotorLockType {
    MotorLockType type;
} ConfigMotorLockType;

typedef struct _BootConfigResponse {
    ConfigHardwareRevision hw_rev;
    bool has_lock_1;
    ConfigMotorLockType lock_1;
    bool has_lock_2;
    ConfigMotorLockType lock_2;
} BootConfigResponse;

typedef struct _Temperature {
    /* The temperature readings */
    pb_size_t temp_count;
    uint16_t temp[6];
} Temperature;

/* This container message is send from MCU to EVerest and may contain any allowed message in that direction. */
typedef struct _McuToEverest {
    pb_size_t which_payload;
    union {
        KeepAlive keep_alive;
        ResetReason reset;
        CpState cp_state;
        CoilState set_coil_state_response;
        ErrorFlags error_flags;
        Telemetry telemetry;
        PpState pp_state;
        FanState fan_state;
        LockState lock_state;
        BootConfigRequest config_request;
        Temperature temperature;
    } payload;
    int32_t connector; /* 0: None, 1: Connector 1, 2: Connector 2 */
} McuToEverest;

/* Message for parking sensor data. */
typedef struct _OpaqueData {
    /* The data itself. */
    pb_size_t data_count;
    uint16_t data[64];
    /* The id of the message - this allows the receiver to assemble chunks of the
 same message. */
    uint32_t id;
    /* The total number of chunks belonging to the `id`. */
    uint32_t chunks_total;
    /* The current chunk. */
    uint32_t chunk_current;
    /* The connector or parking sensor. */
    int32_t connector;
} OpaqueData;

typedef struct _RcdCommand {
    bool test; /* true -> set TEST pin high, false -> set TEST pin low */
    bool reset; /* reset RCD/emergency off if set to true */
} RcdCommand;

/* This container message is send from EVerest to MCU and may contain any allowed message in that direction. */
typedef struct _EverestToMcu {
    pb_size_t which_payload;
    union {
        KeepAlive keep_alive;
        bool firmware_update;
        bool connector_lock; /* false: unlock, true: lock */
        uint32_t pwm_duty_cycle; /* in 0.01 %, 0 = State F, 10000 = X1 */
        CoilState set_coil_state_request;
        bool reset;
        BootConfigResponse config_response;
        FanState set_fan_state;
        RcdCommand rcd_cmd;
    } payload;
    int32_t connector; /* 0: None, 1: Connector 1, 2: Connector 2 */
} EverestToMcu;


#ifdef __cplusplus
extern "C" {
#endif

/* Helper constants for enums */
#define _CpState_MIN CpState_STATE_A
#define _CpState_MAX CpState_STATE_F
#define _CpState_ARRAYSIZE ((CpState)(CpState_STATE_F+1))

#define _ResetReason_MIN ResetReason_USER
#define _ResetReason_MAX ResetReason_WATCHDOG
#define _ResetReason_ARRAYSIZE ((ResetReason)(ResetReason_WATCHDOG+1))

#define _PpState_MIN PpState_STATE_NC
#define _PpState_MAX PpState_STATE_FAULT
#define _PpState_ARRAYSIZE ((PpState)(PpState_STATE_FAULT+1))

#define _LockState_MIN LockState_UNDEFINED
#define _LockState_MAX LockState_LOCKED
#define _LockState_ARRAYSIZE ((LockState)(LockState_LOCKED+1))

#define _CoilType_MIN CoilType_COIL_UNKNOWN
#define _CoilType_MAX CoilType_COIL_DC3
#define _CoilType_ARRAYSIZE ((CoilType)(CoilType_COIL_DC3+1))

#define _ConfigHardwareRevision_MIN ConfigHardwareRevision_HW_REV_UNKNOWN
#define _ConfigHardwareRevision_MAX ConfigHardwareRevision_HW_REV_B
#define _ConfigHardwareRevision_ARRAYSIZE ((ConfigHardwareRevision)(ConfigHardwareRevision_HW_REV_B+1))

#define _MotorLockType_MIN MotorLockType_MOTOR_LOCK_UNKNOWN
#define _MotorLockType_MAX MotorLockType_MOTOR_LOCK_DEBUG_VALEO_HVAC
#define _MotorLockType_ARRAYSIZE ((MotorLockType)(MotorLockType_MOTOR_LOCK_DEBUG_VALEO_HVAC+1))


#define McuToEverest_payload_reset_ENUMTYPE ResetReason
#define McuToEverest_payload_cp_state_ENUMTYPE CpState
#define McuToEverest_payload_pp_state_ENUMTYPE PpState
#define McuToEverest_payload_lock_state_ENUMTYPE LockState





#define CoilState_coil_type_ENUMTYPE CoilType


#define BootConfigResponse_hw_rev_ENUMTYPE ConfigHardwareRevision

#define ConfigMotorLockType_type_ENUMTYPE MotorLockType





/* Initializer values for message structs */
#define EverestToMcu_init_default                {0, {KeepAlive_init_default}, 0}
#define McuToEverest_init_default                {0, {KeepAlive_init_default}, 0}
#define ErrorFlags_init_default                  {0, 0, 0, 0, 0, 0, 0}
#define KeepAlive_init_default                   {0, 0, 0, ""}
#define Telemetry_init_default                   {0, 0}
#define FanState_init_default                    {0, 0, 0, 0}
#define CoilState_init_default                   {_CoilType_MIN, 0}
#define BootConfigRequest_init_default           {0}
#define BootConfigResponse_init_default          {_ConfigHardwareRevision_MIN, false, ConfigMotorLockType_init_default, false, ConfigMotorLockType_init_default}
#define ConfigMotorLockType_init_default         {_MotorLockType_MIN}
#define Temperature_init_default                 {0, {0, 0, 0, 0, 0, 0}}
#define OpaqueData_init_default                  {0, {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0}, 0, 0, 0, 0}
#define RcdCommand_init_default                  {0, 0}
#define EverestToMcu_init_zero                   {0, {KeepAlive_init_zero}, 0}
#define McuToEverest_init_zero                   {0, {KeepAlive_init_zero}, 0}
#define ErrorFlags_init_zero                     {0, 0, 0, 0, 0, 0, 0}
#define KeepAlive_init_zero                      {0, 0, 0, ""}
#define Telemetry_init_zero                      {0, 0}
#define FanState_init_zero                       {0, 0, 0, 0}
#define CoilState_init_zero                      {_CoilType_MIN, 0}
#define BootConfigRequest_init_zero              {0}
#define BootConfigResponse_init_zero             {_ConfigHardwareRevision_MIN, false, ConfigMotorLockType_init_zero, false, ConfigMotorLockType_init_zero}
#define ConfigMotorLockType_init_zero            {_MotorLockType_MIN}
#define Temperature_init_zero                    {0, {0, 0, 0, 0, 0, 0}}
#define OpaqueData_init_zero                     {0, {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0}, 0, 0, 0, 0}
#define RcdCommand_init_zero                     {0, 0}

/* Field tags (for use in manual encoding/decoding) */
#define ErrorFlags_diode_fault_tag               1
#define ErrorFlags_rcd_selftest_failed_tag       2
#define ErrorFlags_rcd_triggered_tag             3
#define ErrorFlags_ventilation_not_available_tag 4
#define ErrorFlags_connector_lock_failed_tag     5
#define ErrorFlags_cp_signal_fault_tag           6
#define ErrorFlags_contactor_error_tag           7
#define KeepAlive_time_stamp_tag                 1
#define KeepAlive_hw_type_tag                    2
#define KeepAlive_hw_revision_tag                3
#define KeepAlive_sw_version_string_tag          6
#define Telemetry_cp_voltage_hi_tag              1
#define Telemetry_cp_voltage_lo_tag              2
#define FanState_fan_id_tag                      1
#define FanState_enabled_tag                     2
#define FanState_duty_tag                        3
#define FanState_rpm_tag                         4
#define CoilState_coil_type_tag                  1
#define CoilState_coil_state_tag                 2
#define ConfigMotorLockType_type_tag             1
#define BootConfigResponse_hw_rev_tag            1
#define BootConfigResponse_lock_1_tag            2
#define BootConfigResponse_lock_2_tag            3
#define Temperature_temp_tag                     1
#define McuToEverest_keep_alive_tag              1
#define McuToEverest_reset_tag                   2
#define McuToEverest_cp_state_tag                3
#define McuToEverest_set_coil_state_response_tag 4
#define McuToEverest_error_flags_tag             5
#define McuToEverest_telemetry_tag               7
#define McuToEverest_pp_state_tag                8
#define McuToEverest_fan_state_tag               9
#define McuToEverest_lock_state_tag              10
#define McuToEverest_config_request_tag          11
#define McuToEverest_temperature_tag             12
#define McuToEverest_connector_tag               6
#define OpaqueData_data_tag                      1
#define OpaqueData_id_tag                        2
#define OpaqueData_chunks_total_tag              3
#define OpaqueData_chunk_current_tag             4
#define OpaqueData_connector_tag                 5
#define RcdCommand_test_tag                      1
#define RcdCommand_reset_tag                     2
#define EverestToMcu_keep_alive_tag              1
#define EverestToMcu_firmware_update_tag         2
#define EverestToMcu_connector_lock_tag          3
#define EverestToMcu_pwm_duty_cycle_tag          4
#define EverestToMcu_set_coil_state_request_tag  5
#define EverestToMcu_reset_tag                   6
#define EverestToMcu_config_response_tag         8
#define EverestToMcu_set_fan_state_tag           9
#define EverestToMcu_rcd_cmd_tag                 10
#define EverestToMcu_connector_tag               7

/* Struct field encoding specification for nanopb */
#define EverestToMcu_FIELDLIST(X, a) \
X(a, STATIC,   ONEOF,    MESSAGE,  (payload,keep_alive,payload.keep_alive),   1) \
X(a, STATIC,   ONEOF,    BOOL,     (payload,firmware_update,payload.firmware_update),   2) \
X(a, STATIC,   ONEOF,    BOOL,     (payload,connector_lock,payload.connector_lock),   3) \
X(a, STATIC,   ONEOF,    UINT32,   (payload,pwm_duty_cycle,payload.pwm_duty_cycle),   4) \
X(a, STATIC,   ONEOF,    MESSAGE,  (payload,set_coil_state_request,payload.set_coil_state_request),   5) \
X(a, STATIC,   ONEOF,    BOOL,     (payload,reset,payload.reset),   6) \
X(a, STATIC,   SINGULAR, INT32,    connector,         7) \
X(a, STATIC,   ONEOF,    MESSAGE,  (payload,config_response,payload.config_response),   8) \
X(a, STATIC,   ONEOF,    MESSAGE,  (payload,set_fan_state,payload.set_fan_state),   9) \
X(a, STATIC,   ONEOF,    MESSAGE,  (payload,rcd_cmd,payload.rcd_cmd),  10)
#define EverestToMcu_CALLBACK NULL
#define EverestToMcu_DEFAULT NULL
#define EverestToMcu_payload_keep_alive_MSGTYPE KeepAlive
#define EverestToMcu_payload_set_coil_state_request_MSGTYPE CoilState
#define EverestToMcu_payload_config_response_MSGTYPE BootConfigResponse
#define EverestToMcu_payload_set_fan_state_MSGTYPE FanState
#define EverestToMcu_payload_rcd_cmd_MSGTYPE RcdCommand

#define McuToEverest_FIELDLIST(X, a) \
X(a, STATIC,   ONEOF,    MESSAGE,  (payload,keep_alive,payload.keep_alive),   1) \
X(a, STATIC,   ONEOF,    UENUM,    (payload,reset,payload.reset),   2) \
X(a, STATIC,   ONEOF,    UENUM,    (payload,cp_state,payload.cp_state),   3) \
X(a, STATIC,   ONEOF,    MESSAGE,  (payload,set_coil_state_response,payload.set_coil_state_response),   4) \
X(a, STATIC,   ONEOF,    MESSAGE,  (payload,error_flags,payload.error_flags),   5) \
X(a, STATIC,   SINGULAR, INT32,    connector,         6) \
X(a, STATIC,   ONEOF,    MESSAGE,  (payload,telemetry,payload.telemetry),   7) \
X(a, STATIC,   ONEOF,    UENUM,    (payload,pp_state,payload.pp_state),   8) \
X(a, STATIC,   ONEOF,    MESSAGE,  (payload,fan_state,payload.fan_state),   9) \
X(a, STATIC,   ONEOF,    UENUM,    (payload,lock_state,payload.lock_state),  10) \
X(a, STATIC,   ONEOF,    MESSAGE,  (payload,config_request,payload.config_request),  11) \
X(a, STATIC,   ONEOF,    MESSAGE,  (payload,temperature,payload.temperature),  12)
#define McuToEverest_CALLBACK NULL
#define McuToEverest_DEFAULT NULL
#define McuToEverest_payload_keep_alive_MSGTYPE KeepAlive
#define McuToEverest_payload_set_coil_state_response_MSGTYPE CoilState
#define McuToEverest_payload_error_flags_MSGTYPE ErrorFlags
#define McuToEverest_payload_telemetry_MSGTYPE Telemetry
#define McuToEverest_payload_fan_state_MSGTYPE FanState
#define McuToEverest_payload_config_request_MSGTYPE BootConfigRequest
#define McuToEverest_payload_temperature_MSGTYPE Temperature

#define ErrorFlags_FIELDLIST(X, a) \
X(a, STATIC,   SINGULAR, BOOL,     diode_fault,       1) \
X(a, STATIC,   SINGULAR, BOOL,     rcd_selftest_failed,   2) \
X(a, STATIC,   SINGULAR, BOOL,     rcd_triggered,     3) \
X(a, STATIC,   SINGULAR, BOOL,     ventilation_not_available,   4) \
X(a, STATIC,   SINGULAR, BOOL,     connector_lock_failed,   5) \
X(a, STATIC,   SINGULAR, BOOL,     cp_signal_fault,   6) \
X(a, STATIC,   SINGULAR, BOOL,     contactor_error,   7)
#define ErrorFlags_CALLBACK NULL
#define ErrorFlags_DEFAULT NULL

#define KeepAlive_FIELDLIST(X, a) \
X(a, STATIC,   SINGULAR, UINT32,   time_stamp,        1) \
X(a, STATIC,   SINGULAR, UINT32,   hw_type,           2) \
X(a, STATIC,   SINGULAR, UINT32,   hw_revision,       3) \
X(a, STATIC,   SINGULAR, STRING,   sw_version_string,   6)
#define KeepAlive_CALLBACK NULL
#define KeepAlive_DEFAULT NULL

#define Telemetry_FIELDLIST(X, a) \
X(a, STATIC,   SINGULAR, UINT32,   cp_voltage_hi,     1) \
X(a, STATIC,   SINGULAR, UINT32,   cp_voltage_lo,     2)
#define Telemetry_CALLBACK NULL
#define Telemetry_DEFAULT NULL

#define FanState_FIELDLIST(X, a) \
X(a, STATIC,   SINGULAR, UINT32,   fan_id,            1) \
X(a, STATIC,   SINGULAR, BOOL,     enabled,           2) \
X(a, STATIC,   SINGULAR, UINT32,   duty,              3) \
X(a, STATIC,   SINGULAR, UINT32,   rpm,               4)
#define FanState_CALLBACK NULL
#define FanState_DEFAULT NULL

#define CoilState_FIELDLIST(X, a) \
X(a, STATIC,   SINGULAR, UENUM,    coil_type,         1) \
X(a, STATIC,   SINGULAR, BOOL,     coil_state,        2)
#define CoilState_CALLBACK NULL
#define CoilState_DEFAULT NULL

#define BootConfigRequest_FIELDLIST(X, a) \

#define BootConfigRequest_CALLBACK NULL
#define BootConfigRequest_DEFAULT NULL

#define BootConfigResponse_FIELDLIST(X, a) \
X(a, STATIC,   SINGULAR, UENUM,    hw_rev,            1) \
X(a, STATIC,   OPTIONAL, MESSAGE,  lock_1,            2) \
X(a, STATIC,   OPTIONAL, MESSAGE,  lock_2,            3)
#define BootConfigResponse_CALLBACK NULL
#define BootConfigResponse_DEFAULT NULL
#define BootConfigResponse_lock_1_MSGTYPE ConfigMotorLockType
#define BootConfigResponse_lock_2_MSGTYPE ConfigMotorLockType

#define ConfigMotorLockType_FIELDLIST(X, a) \
X(a, STATIC,   SINGULAR, UENUM,    type,              1)
#define ConfigMotorLockType_CALLBACK NULL
#define ConfigMotorLockType_DEFAULT NULL

#define Temperature_FIELDLIST(X, a) \
X(a, STATIC,   REPEATED, UINT32,   temp,              1)
#define Temperature_CALLBACK NULL
#define Temperature_DEFAULT NULL

#define OpaqueData_FIELDLIST(X, a) \
X(a, STATIC,   REPEATED, UINT32,   data,              1) \
X(a, STATIC,   SINGULAR, UINT32,   id,                2) \
X(a, STATIC,   SINGULAR, UINT32,   chunks_total,      3) \
X(a, STATIC,   SINGULAR, UINT32,   chunk_current,     4) \
X(a, STATIC,   SINGULAR, INT32,    connector,         5)
#define OpaqueData_CALLBACK NULL
#define OpaqueData_DEFAULT NULL

#define RcdCommand_FIELDLIST(X, a) \
X(a, STATIC,   SINGULAR, BOOL,     test,              1) \
X(a, STATIC,   SINGULAR, BOOL,     reset,             2)
#define RcdCommand_CALLBACK NULL
#define RcdCommand_DEFAULT NULL

extern const pb_msgdesc_t EverestToMcu_msg;
extern const pb_msgdesc_t McuToEverest_msg;
extern const pb_msgdesc_t ErrorFlags_msg;
extern const pb_msgdesc_t KeepAlive_msg;
extern const pb_msgdesc_t Telemetry_msg;
extern const pb_msgdesc_t FanState_msg;
extern const pb_msgdesc_t CoilState_msg;
extern const pb_msgdesc_t BootConfigRequest_msg;
extern const pb_msgdesc_t BootConfigResponse_msg;
extern const pb_msgdesc_t ConfigMotorLockType_msg;
extern const pb_msgdesc_t Temperature_msg;
extern const pb_msgdesc_t OpaqueData_msg;
extern const pb_msgdesc_t RcdCommand_msg;

/* Defines for backwards compatibility with code written before nanopb-0.4.0 */
#define EverestToMcu_fields &EverestToMcu_msg
#define McuToEverest_fields &McuToEverest_msg
#define ErrorFlags_fields &ErrorFlags_msg
#define KeepAlive_fields &KeepAlive_msg
#define Telemetry_fields &Telemetry_msg
#define FanState_fields &FanState_msg
#define CoilState_fields &CoilState_msg
#define BootConfigRequest_fields &BootConfigRequest_msg
#define BootConfigResponse_fields &BootConfigResponse_msg
#define ConfigMotorLockType_fields &ConfigMotorLockType_msg
#define Temperature_fields &Temperature_msg
#define OpaqueData_fields &OpaqueData_msg
#define RcdCommand_fields &RcdCommand_msg

/* Maximum encoded size of messages (where known) */
#define BootConfigRequest_size                   0
#define BootConfigResponse_size                  10
#define CoilState_size                           4
#define ConfigMotorLockType_size                 2
#define ErrorFlags_size                          14
#define EverestToMcu_size                        83
#define FanState_size                            15
#define KeepAlive_size                           70
#define McuToEverest_size                        83
#define OpaqueData_size                          285
#define PHYVERSO_PB_H_MAX_SIZE                   OpaqueData_size
#define RcdCommand_size                          4
#define Telemetry_size                           12
#define Temperature_size                         24

#ifdef __cplusplus
} /* extern "C" */
#endif

#endif
