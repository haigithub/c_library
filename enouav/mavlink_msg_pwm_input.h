// MESSAGE PWM_INPUT PACKING

#define MAVLINK_MSG_ID_PWM_INPUT 180

typedef struct MAVLINK_PACKED __mavlink_pwm_input_t
{
 uint64_t error_count; /*< (uint64_t, 0...)*/
 uint32_t time_boot_ms; /*< Timestamp (milliseconds since system boot)*/
 uint32_t pulse_width; /*< (uint32_t, 0...)*/
 uint32_t period; /*< (uint32_t, 0...)*/
} mavlink_pwm_input_t;

#define MAVLINK_MSG_ID_PWM_INPUT_LEN 20
#define MAVLINK_MSG_ID_PWM_INPUT_MIN_LEN 20
#define MAVLINK_MSG_ID_180_LEN 20
#define MAVLINK_MSG_ID_180_MIN_LEN 20

#define MAVLINK_MSG_ID_PWM_INPUT_CRC 214
#define MAVLINK_MSG_ID_180_CRC 214



#if MAVLINK_COMMAND_24BIT
#define MAVLINK_MESSAGE_INFO_PWM_INPUT { \
	180, \
	"PWM_INPUT", \
	4, \
	{  { "error_count", NULL, MAVLINK_TYPE_UINT64_T, 0, 0, offsetof(mavlink_pwm_input_t, error_count) }, \
         { "time_boot_ms", NULL, MAVLINK_TYPE_UINT32_T, 0, 8, offsetof(mavlink_pwm_input_t, time_boot_ms) }, \
         { "pulse_width", NULL, MAVLINK_TYPE_UINT32_T, 0, 12, offsetof(mavlink_pwm_input_t, pulse_width) }, \
         { "period", NULL, MAVLINK_TYPE_UINT32_T, 0, 16, offsetof(mavlink_pwm_input_t, period) }, \
         } \
}
#else
#define MAVLINK_MESSAGE_INFO_PWM_INPUT { \
	"PWM_INPUT", \
	4, \
	{  { "error_count", NULL, MAVLINK_TYPE_UINT64_T, 0, 0, offsetof(mavlink_pwm_input_t, error_count) }, \
         { "time_boot_ms", NULL, MAVLINK_TYPE_UINT32_T, 0, 8, offsetof(mavlink_pwm_input_t, time_boot_ms) }, \
         { "pulse_width", NULL, MAVLINK_TYPE_UINT32_T, 0, 12, offsetof(mavlink_pwm_input_t, pulse_width) }, \
         { "period", NULL, MAVLINK_TYPE_UINT32_T, 0, 16, offsetof(mavlink_pwm_input_t, period) }, \
         } \
}
#endif

/**
 * @brief Pack a pwm_input message
 * @param system_id ID of this system
 * @param component_id ID of this component (e.g. 200 for IMU)
 * @param msg The MAVLink message to compress the data into
 *
 * @param error_count (uint64_t, 0...)
 * @param time_boot_ms Timestamp (milliseconds since system boot)
 * @param pulse_width (uint32_t, 0...)
 * @param period (uint32_t, 0...)
 * @return length of the message in bytes (excluding serial stream start sign)
 */
static inline uint16_t mavlink_msg_pwm_input_pack(uint8_t system_id, uint8_t component_id, mavlink_message_t* msg,
						       uint64_t error_count, uint32_t time_boot_ms, uint32_t pulse_width, uint32_t period)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
	char buf[MAVLINK_MSG_ID_PWM_INPUT_LEN];
	_mav_put_uint64_t(buf, 0, error_count);
	_mav_put_uint32_t(buf, 8, time_boot_ms);
	_mav_put_uint32_t(buf, 12, pulse_width);
	_mav_put_uint32_t(buf, 16, period);

        memcpy(_MAV_PAYLOAD_NON_CONST(msg), buf, MAVLINK_MSG_ID_PWM_INPUT_LEN);
#else
	mavlink_pwm_input_t packet;
	packet.error_count = error_count;
	packet.time_boot_ms = time_boot_ms;
	packet.pulse_width = pulse_width;
	packet.period = period;

        memcpy(_MAV_PAYLOAD_NON_CONST(msg), &packet, MAVLINK_MSG_ID_PWM_INPUT_LEN);
#endif

	msg->msgid = MAVLINK_MSG_ID_PWM_INPUT;
    return mavlink_finalize_message(msg, system_id, component_id, MAVLINK_MSG_ID_PWM_INPUT_MIN_LEN, MAVLINK_MSG_ID_PWM_INPUT_LEN, MAVLINK_MSG_ID_PWM_INPUT_CRC);
}

/**
 * @brief Pack a pwm_input message on a channel
 * @param system_id ID of this system
 * @param component_id ID of this component (e.g. 200 for IMU)
 * @param chan The MAVLink channel this message will be sent over
 * @param msg The MAVLink message to compress the data into
 * @param error_count (uint64_t, 0...)
 * @param time_boot_ms Timestamp (milliseconds since system boot)
 * @param pulse_width (uint32_t, 0...)
 * @param period (uint32_t, 0...)
 * @return length of the message in bytes (excluding serial stream start sign)
 */
static inline uint16_t mavlink_msg_pwm_input_pack_chan(uint8_t system_id, uint8_t component_id, uint8_t chan,
							   mavlink_message_t* msg,
						           uint64_t error_count,uint32_t time_boot_ms,uint32_t pulse_width,uint32_t period)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
	char buf[MAVLINK_MSG_ID_PWM_INPUT_LEN];
	_mav_put_uint64_t(buf, 0, error_count);
	_mav_put_uint32_t(buf, 8, time_boot_ms);
	_mav_put_uint32_t(buf, 12, pulse_width);
	_mav_put_uint32_t(buf, 16, period);

        memcpy(_MAV_PAYLOAD_NON_CONST(msg), buf, MAVLINK_MSG_ID_PWM_INPUT_LEN);
#else
	mavlink_pwm_input_t packet;
	packet.error_count = error_count;
	packet.time_boot_ms = time_boot_ms;
	packet.pulse_width = pulse_width;
	packet.period = period;

        memcpy(_MAV_PAYLOAD_NON_CONST(msg), &packet, MAVLINK_MSG_ID_PWM_INPUT_LEN);
#endif

	msg->msgid = MAVLINK_MSG_ID_PWM_INPUT;
    return mavlink_finalize_message_chan(msg, system_id, component_id, chan, MAVLINK_MSG_ID_PWM_INPUT_MIN_LEN, MAVLINK_MSG_ID_PWM_INPUT_LEN, MAVLINK_MSG_ID_PWM_INPUT_CRC);
}

/**
 * @brief Encode a pwm_input struct
 *
 * @param system_id ID of this system
 * @param component_id ID of this component (e.g. 200 for IMU)
 * @param msg The MAVLink message to compress the data into
 * @param pwm_input C-struct to read the message contents from
 */
static inline uint16_t mavlink_msg_pwm_input_encode(uint8_t system_id, uint8_t component_id, mavlink_message_t* msg, const mavlink_pwm_input_t* pwm_input)
{
	return mavlink_msg_pwm_input_pack(system_id, component_id, msg, pwm_input->error_count, pwm_input->time_boot_ms, pwm_input->pulse_width, pwm_input->period);
}

/**
 * @brief Encode a pwm_input struct on a channel
 *
 * @param system_id ID of this system
 * @param component_id ID of this component (e.g. 200 for IMU)
 * @param chan The MAVLink channel this message will be sent over
 * @param msg The MAVLink message to compress the data into
 * @param pwm_input C-struct to read the message contents from
 */
static inline uint16_t mavlink_msg_pwm_input_encode_chan(uint8_t system_id, uint8_t component_id, uint8_t chan, mavlink_message_t* msg, const mavlink_pwm_input_t* pwm_input)
{
	return mavlink_msg_pwm_input_pack_chan(system_id, component_id, chan, msg, pwm_input->error_count, pwm_input->time_boot_ms, pwm_input->pulse_width, pwm_input->period);
}

/**
 * @brief Send a pwm_input message
 * @param chan MAVLink channel to send the message
 *
 * @param error_count (uint64_t, 0...)
 * @param time_boot_ms Timestamp (milliseconds since system boot)
 * @param pulse_width (uint32_t, 0...)
 * @param period (uint32_t, 0...)
 */
#ifdef MAVLINK_USE_CONVENIENCE_FUNCTIONS

static inline void mavlink_msg_pwm_input_send(mavlink_channel_t chan, uint64_t error_count, uint32_t time_boot_ms, uint32_t pulse_width, uint32_t period)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
	char buf[MAVLINK_MSG_ID_PWM_INPUT_LEN];
	_mav_put_uint64_t(buf, 0, error_count);
	_mav_put_uint32_t(buf, 8, time_boot_ms);
	_mav_put_uint32_t(buf, 12, pulse_width);
	_mav_put_uint32_t(buf, 16, period);

    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_PWM_INPUT, buf, MAVLINK_MSG_ID_PWM_INPUT_MIN_LEN, MAVLINK_MSG_ID_PWM_INPUT_LEN, MAVLINK_MSG_ID_PWM_INPUT_CRC);
#else
	mavlink_pwm_input_t packet;
	packet.error_count = error_count;
	packet.time_boot_ms = time_boot_ms;
	packet.pulse_width = pulse_width;
	packet.period = period;

    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_PWM_INPUT, (const char *)&packet, MAVLINK_MSG_ID_PWM_INPUT_MIN_LEN, MAVLINK_MSG_ID_PWM_INPUT_LEN, MAVLINK_MSG_ID_PWM_INPUT_CRC);
#endif
}

/**
 * @brief Send a pwm_input message
 * @param chan MAVLink channel to send the message
 * @param struct The MAVLink struct to serialize
 */
static inline void mavlink_msg_pwm_input_send_struct(mavlink_channel_t chan, const mavlink_pwm_input_t* pwm_input)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
    mavlink_msg_pwm_input_send(chan, pwm_input->error_count, pwm_input->time_boot_ms, pwm_input->pulse_width, pwm_input->period);
#else
    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_PWM_INPUT, (const char *)pwm_input, MAVLINK_MSG_ID_PWM_INPUT_MIN_LEN, MAVLINK_MSG_ID_PWM_INPUT_LEN, MAVLINK_MSG_ID_PWM_INPUT_CRC);
#endif
}

#if MAVLINK_MSG_ID_PWM_INPUT_LEN <= MAVLINK_MAX_PAYLOAD_LEN
/*
  This varient of _send() can be used to save stack space by re-using
  memory from the receive buffer.  The caller provides a
  mavlink_message_t which is the size of a full mavlink message. This
  is usually the receive buffer for the channel, and allows a reply to an
  incoming message with minimum stack space usage.
 */
static inline void mavlink_msg_pwm_input_send_buf(mavlink_message_t *msgbuf, mavlink_channel_t chan,  uint64_t error_count, uint32_t time_boot_ms, uint32_t pulse_width, uint32_t period)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
	char *buf = (char *)msgbuf;
	_mav_put_uint64_t(buf, 0, error_count);
	_mav_put_uint32_t(buf, 8, time_boot_ms);
	_mav_put_uint32_t(buf, 12, pulse_width);
	_mav_put_uint32_t(buf, 16, period);

    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_PWM_INPUT, buf, MAVLINK_MSG_ID_PWM_INPUT_MIN_LEN, MAVLINK_MSG_ID_PWM_INPUT_LEN, MAVLINK_MSG_ID_PWM_INPUT_CRC);
#else
	mavlink_pwm_input_t *packet = (mavlink_pwm_input_t *)msgbuf;
	packet->error_count = error_count;
	packet->time_boot_ms = time_boot_ms;
	packet->pulse_width = pulse_width;
	packet->period = period;

    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_PWM_INPUT, (const char *)packet, MAVLINK_MSG_ID_PWM_INPUT_MIN_LEN, MAVLINK_MSG_ID_PWM_INPUT_LEN, MAVLINK_MSG_ID_PWM_INPUT_CRC);
#endif
}
#endif

#endif

// MESSAGE PWM_INPUT UNPACKING


/**
 * @brief Get field error_count from pwm_input message
 *
 * @return (uint64_t, 0...)
 */
static inline uint64_t mavlink_msg_pwm_input_get_error_count(const mavlink_message_t* msg)
{
	return _MAV_RETURN_uint64_t(msg,  0);
}

/**
 * @brief Get field time_boot_ms from pwm_input message
 *
 * @return Timestamp (milliseconds since system boot)
 */
static inline uint32_t mavlink_msg_pwm_input_get_time_boot_ms(const mavlink_message_t* msg)
{
	return _MAV_RETURN_uint32_t(msg,  8);
}

/**
 * @brief Get field pulse_width from pwm_input message
 *
 * @return (uint32_t, 0...)
 */
static inline uint32_t mavlink_msg_pwm_input_get_pulse_width(const mavlink_message_t* msg)
{
	return _MAV_RETURN_uint32_t(msg,  12);
}

/**
 * @brief Get field period from pwm_input message
 *
 * @return (uint32_t, 0...)
 */
static inline uint32_t mavlink_msg_pwm_input_get_period(const mavlink_message_t* msg)
{
	return _MAV_RETURN_uint32_t(msg,  16);
}

/**
 * @brief Decode a pwm_input message into a struct
 *
 * @param msg The message to decode
 * @param pwm_input C-struct to decode the message contents into
 */
static inline void mavlink_msg_pwm_input_decode(const mavlink_message_t* msg, mavlink_pwm_input_t* pwm_input)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
	pwm_input->error_count = mavlink_msg_pwm_input_get_error_count(msg);
	pwm_input->time_boot_ms = mavlink_msg_pwm_input_get_time_boot_ms(msg);
	pwm_input->pulse_width = mavlink_msg_pwm_input_get_pulse_width(msg);
	pwm_input->period = mavlink_msg_pwm_input_get_period(msg);
#else
        uint8_t len = msg->len < MAVLINK_MSG_ID_PWM_INPUT_LEN? msg->len : MAVLINK_MSG_ID_PWM_INPUT_LEN;
        memset(pwm_input, 0, MAVLINK_MSG_ID_PWM_INPUT_LEN);
	memcpy(pwm_input, _MAV_PAYLOAD(msg), len);
#endif
}
