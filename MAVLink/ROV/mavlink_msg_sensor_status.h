#pragma once
// MESSAGE SENSOR_STATUS PACKING

#define MAVLINK_MSG_ID_SENSOR_STATUS 153

MAVPACKED(
typedef struct __mavlink_sensor_status_t {
 uint8_t MS5837_status; /*< working status of the MS5837 sensor*/
 uint8_t JY901_status; /*< working status of the JY901 sensor*/
}) mavlink_sensor_status_t;

#define MAVLINK_MSG_ID_SENSOR_STATUS_LEN 2
#define MAVLINK_MSG_ID_SENSOR_STATUS_MIN_LEN 2
#define MAVLINK_MSG_ID_153_LEN 2
#define MAVLINK_MSG_ID_153_MIN_LEN 2

#define MAVLINK_MSG_ID_SENSOR_STATUS_CRC 111
#define MAVLINK_MSG_ID_153_CRC 111



#if MAVLINK_COMMAND_24BIT
#define MAVLINK_MESSAGE_INFO_SENSOR_STATUS { \
    153, \
    "SENSOR_STATUS", \
    2, \
    {  { "MS5837_status", NULL, MAVLINK_TYPE_UINT8_T, 0, 0, offsetof(mavlink_sensor_status_t, MS5837_status) }, \
         { "JY901_status", NULL, MAVLINK_TYPE_UINT8_T, 0, 1, offsetof(mavlink_sensor_status_t, JY901_status) }, \
         } \
}
#else
#define MAVLINK_MESSAGE_INFO_SENSOR_STATUS { \
    "SENSOR_STATUS", \
    2, \
    {  { "MS5837_status", NULL, MAVLINK_TYPE_UINT8_T, 0, 0, offsetof(mavlink_sensor_status_t, MS5837_status) }, \
         { "JY901_status", NULL, MAVLINK_TYPE_UINT8_T, 0, 1, offsetof(mavlink_sensor_status_t, JY901_status) }, \
         } \
}
#endif

/**
 * @brief Pack a sensor_status message
 * @param system_id ID of this system
 * @param component_id ID of this component (e.g. 200 for IMU)
 * @param msg The MAVLink message to compress the data into
 *
 * @param MS5837_status working status of the MS5837 sensor
 * @param JY901_status working status of the JY901 sensor
 * @return length of the message in bytes (excluding serial stream start sign)
 */
static inline uint16_t mavlink_msg_sensor_status_pack(uint8_t system_id, uint8_t component_id, mavlink_message_t* msg,
                               uint8_t MS5837_status, uint8_t JY901_status)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
    char buf[MAVLINK_MSG_ID_SENSOR_STATUS_LEN];
    _mav_put_uint8_t(buf, 0, MS5837_status);
    _mav_put_uint8_t(buf, 1, JY901_status);

        memcpy(_MAV_PAYLOAD_NON_CONST(msg), buf, MAVLINK_MSG_ID_SENSOR_STATUS_LEN);
#else
    mavlink_sensor_status_t packet;
    packet.MS5837_status = MS5837_status;
    packet.JY901_status = JY901_status;

        memcpy(_MAV_PAYLOAD_NON_CONST(msg), &packet, MAVLINK_MSG_ID_SENSOR_STATUS_LEN);
#endif

    msg->msgid = MAVLINK_MSG_ID_SENSOR_STATUS;
    return mavlink_finalize_message(msg, system_id, component_id, MAVLINK_MSG_ID_SENSOR_STATUS_MIN_LEN, MAVLINK_MSG_ID_SENSOR_STATUS_LEN, MAVLINK_MSG_ID_SENSOR_STATUS_CRC);
}

/**
 * @brief Pack a sensor_status message on a channel
 * @param system_id ID of this system
 * @param component_id ID of this component (e.g. 200 for IMU)
 * @param chan The MAVLink channel this message will be sent over
 * @param msg The MAVLink message to compress the data into
 * @param MS5837_status working status of the MS5837 sensor
 * @param JY901_status working status of the JY901 sensor
 * @return length of the message in bytes (excluding serial stream start sign)
 */
static inline uint16_t mavlink_msg_sensor_status_pack_chan(uint8_t system_id, uint8_t component_id, uint8_t chan,
                               mavlink_message_t* msg,
                                   uint8_t MS5837_status,uint8_t JY901_status)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
    char buf[MAVLINK_MSG_ID_SENSOR_STATUS_LEN];
    _mav_put_uint8_t(buf, 0, MS5837_status);
    _mav_put_uint8_t(buf, 1, JY901_status);

        memcpy(_MAV_PAYLOAD_NON_CONST(msg), buf, MAVLINK_MSG_ID_SENSOR_STATUS_LEN);
#else
    mavlink_sensor_status_t packet;
    packet.MS5837_status = MS5837_status;
    packet.JY901_status = JY901_status;

        memcpy(_MAV_PAYLOAD_NON_CONST(msg), &packet, MAVLINK_MSG_ID_SENSOR_STATUS_LEN);
#endif

    msg->msgid = MAVLINK_MSG_ID_SENSOR_STATUS;
    return mavlink_finalize_message_chan(msg, system_id, component_id, chan, MAVLINK_MSG_ID_SENSOR_STATUS_MIN_LEN, MAVLINK_MSG_ID_SENSOR_STATUS_LEN, MAVLINK_MSG_ID_SENSOR_STATUS_CRC);
}

/**
 * @brief Encode a sensor_status struct
 *
 * @param system_id ID of this system
 * @param component_id ID of this component (e.g. 200 for IMU)
 * @param msg The MAVLink message to compress the data into
 * @param sensor_status C-struct to read the message contents from
 */
static inline uint16_t mavlink_msg_sensor_status_encode(uint8_t system_id, uint8_t component_id, mavlink_message_t* msg, const mavlink_sensor_status_t* sensor_status)
{
    return mavlink_msg_sensor_status_pack(system_id, component_id, msg, sensor_status->MS5837_status, sensor_status->JY901_status);
}

/**
 * @brief Encode a sensor_status struct on a channel
 *
 * @param system_id ID of this system
 * @param component_id ID of this component (e.g. 200 for IMU)
 * @param chan The MAVLink channel this message will be sent over
 * @param msg The MAVLink message to compress the data into
 * @param sensor_status C-struct to read the message contents from
 */
static inline uint16_t mavlink_msg_sensor_status_encode_chan(uint8_t system_id, uint8_t component_id, uint8_t chan, mavlink_message_t* msg, const mavlink_sensor_status_t* sensor_status)
{
    return mavlink_msg_sensor_status_pack_chan(system_id, component_id, chan, msg, sensor_status->MS5837_status, sensor_status->JY901_status);
}

/**
 * @brief Send a sensor_status message
 * @param chan MAVLink channel to send the message
 *
 * @param MS5837_status working status of the MS5837 sensor
 * @param JY901_status working status of the JY901 sensor
 */
#ifdef MAVLINK_USE_CONVENIENCE_FUNCTIONS

static inline void mavlink_msg_sensor_status_send(mavlink_channel_t chan, uint8_t MS5837_status, uint8_t JY901_status)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
    char buf[MAVLINK_MSG_ID_SENSOR_STATUS_LEN];
    _mav_put_uint8_t(buf, 0, MS5837_status);
    _mav_put_uint8_t(buf, 1, JY901_status);

    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_SENSOR_STATUS, buf, MAVLINK_MSG_ID_SENSOR_STATUS_MIN_LEN, MAVLINK_MSG_ID_SENSOR_STATUS_LEN, MAVLINK_MSG_ID_SENSOR_STATUS_CRC);
#else
    mavlink_sensor_status_t packet;
    packet.MS5837_status = MS5837_status;
    packet.JY901_status = JY901_status;

    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_SENSOR_STATUS, (const char *)&packet, MAVLINK_MSG_ID_SENSOR_STATUS_MIN_LEN, MAVLINK_MSG_ID_SENSOR_STATUS_LEN, MAVLINK_MSG_ID_SENSOR_STATUS_CRC);
#endif
}

/**
 * @brief Send a sensor_status message
 * @param chan MAVLink channel to send the message
 * @param struct The MAVLink struct to serialize
 */
static inline void mavlink_msg_sensor_status_send_struct(mavlink_channel_t chan, const mavlink_sensor_status_t* sensor_status)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
    mavlink_msg_sensor_status_send(chan, sensor_status->MS5837_status, sensor_status->JY901_status);
#else
    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_SENSOR_STATUS, (const char *)sensor_status, MAVLINK_MSG_ID_SENSOR_STATUS_MIN_LEN, MAVLINK_MSG_ID_SENSOR_STATUS_LEN, MAVLINK_MSG_ID_SENSOR_STATUS_CRC);
#endif
}

#if MAVLINK_MSG_ID_SENSOR_STATUS_LEN <= MAVLINK_MAX_PAYLOAD_LEN
/*
  This varient of _send() can be used to save stack space by re-using
  memory from the receive buffer.  The caller provides a
  mavlink_message_t which is the size of a full mavlink message. This
  is usually the receive buffer for the channel, and allows a reply to an
  incoming message with minimum stack space usage.
 */
static inline void mavlink_msg_sensor_status_send_buf(mavlink_message_t *msgbuf, mavlink_channel_t chan,  uint8_t MS5837_status, uint8_t JY901_status)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
    char *buf = (char *)msgbuf;
    _mav_put_uint8_t(buf, 0, MS5837_status);
    _mav_put_uint8_t(buf, 1, JY901_status);

    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_SENSOR_STATUS, buf, MAVLINK_MSG_ID_SENSOR_STATUS_MIN_LEN, MAVLINK_MSG_ID_SENSOR_STATUS_LEN, MAVLINK_MSG_ID_SENSOR_STATUS_CRC);
#else
    mavlink_sensor_status_t *packet = (mavlink_sensor_status_t *)msgbuf;
    packet->MS5837_status = MS5837_status;
    packet->JY901_status = JY901_status;

    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_SENSOR_STATUS, (const char *)packet, MAVLINK_MSG_ID_SENSOR_STATUS_MIN_LEN, MAVLINK_MSG_ID_SENSOR_STATUS_LEN, MAVLINK_MSG_ID_SENSOR_STATUS_CRC);
#endif
}
#endif

#endif

// MESSAGE SENSOR_STATUS UNPACKING


/**
 * @brief Get field MS5837_status from sensor_status message
 *
 * @return working status of the MS5837 sensor
 */
static inline uint8_t mavlink_msg_sensor_status_get_MS5837_status(const mavlink_message_t* msg)
{
    return _MAV_RETURN_uint8_t(msg,  0);
}

/**
 * @brief Get field JY901_status from sensor_status message
 *
 * @return working status of the JY901 sensor
 */
static inline uint8_t mavlink_msg_sensor_status_get_JY901_status(const mavlink_message_t* msg)
{
    return _MAV_RETURN_uint8_t(msg,  1);
}

/**
 * @brief Decode a sensor_status message into a struct
 *
 * @param msg The message to decode
 * @param sensor_status C-struct to decode the message contents into
 */
static inline void mavlink_msg_sensor_status_decode(const mavlink_message_t* msg, mavlink_sensor_status_t* sensor_status)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
    sensor_status->MS5837_status = mavlink_msg_sensor_status_get_MS5837_status(msg);
    sensor_status->JY901_status = mavlink_msg_sensor_status_get_JY901_status(msg);
#else
        uint8_t len = msg->len < MAVLINK_MSG_ID_SENSOR_STATUS_LEN? msg->len : MAVLINK_MSG_ID_SENSOR_STATUS_LEN;
        memset(sensor_status, 0, MAVLINK_MSG_ID_SENSOR_STATUS_LEN);
    memcpy(sensor_status, _MAV_PAYLOAD(msg), len);
#endif
}
