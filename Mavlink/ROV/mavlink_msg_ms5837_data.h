#pragma once
// MESSAGE MS5837_DATA PACKING

#define MAVLINK_MSG_ID_MS5837_DATA 151

MAVPACKED(
typedef struct __mavlink_ms5837_data_t {
 float depth; /*< Depth of the ROV*/
 float temperature; /*< Temperature of the ROV*/
 float pressure; /*< pressure of the ROV*/
}) mavlink_ms5837_data_t;

#define MAVLINK_MSG_ID_MS5837_DATA_LEN 12
#define MAVLINK_MSG_ID_MS5837_DATA_MIN_LEN 12
#define MAVLINK_MSG_ID_151_LEN 12
#define MAVLINK_MSG_ID_151_MIN_LEN 12

#define MAVLINK_MSG_ID_MS5837_DATA_CRC 92
#define MAVLINK_MSG_ID_151_CRC 92



#if MAVLINK_COMMAND_24BIT
#define MAVLINK_MESSAGE_INFO_MS5837_DATA { \
    151, \
    "MS5837_DATA", \
    3, \
    {  { "depth", NULL, MAVLINK_TYPE_FLOAT, 0, 0, offsetof(mavlink_ms5837_data_t, depth) }, \
         { "temperature", NULL, MAVLINK_TYPE_FLOAT, 0, 4, offsetof(mavlink_ms5837_data_t, temperature) }, \
         { "pressure", NULL, MAVLINK_TYPE_FLOAT, 0, 8, offsetof(mavlink_ms5837_data_t, pressure) }, \
         } \
}
#else
#define MAVLINK_MESSAGE_INFO_MS5837_DATA { \
    "MS5837_DATA", \
    3, \
    {  { "depth", NULL, MAVLINK_TYPE_FLOAT, 0, 0, offsetof(mavlink_ms5837_data_t, depth) }, \
         { "temperature", NULL, MAVLINK_TYPE_FLOAT, 0, 4, offsetof(mavlink_ms5837_data_t, temperature) }, \
         { "pressure", NULL, MAVLINK_TYPE_FLOAT, 0, 8, offsetof(mavlink_ms5837_data_t, pressure) }, \
         } \
}
#endif

/**
 * @brief Pack a ms5837_data message
 * @param system_id ID of this system
 * @param component_id ID of this component (e.g. 200 for IMU)
 * @param msg The MAVLink message to compress the data into
 *
 * @param depth Depth of the ROV
 * @param temperature Temperature of the ROV
 * @param pressure pressure of the ROV
 * @return length of the message in bytes (excluding serial stream start sign)
 */
static inline uint16_t mavlink_msg_ms5837_data_pack(uint8_t system_id, uint8_t component_id, mavlink_message_t* msg,
                               float depth, float temperature, float pressure)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
    char buf[MAVLINK_MSG_ID_MS5837_DATA_LEN];
    _mav_put_float(buf, 0, depth);
    _mav_put_float(buf, 4, temperature);
    _mav_put_float(buf, 8, pressure);

        memcpy(_MAV_PAYLOAD_NON_CONST(msg), buf, MAVLINK_MSG_ID_MS5837_DATA_LEN);
#else
    mavlink_ms5837_data_t packet;
    packet.depth = depth;
    packet.temperature = temperature;
    packet.pressure = pressure;

        memcpy(_MAV_PAYLOAD_NON_CONST(msg), &packet, MAVLINK_MSG_ID_MS5837_DATA_LEN);
#endif

    msg->msgid = MAVLINK_MSG_ID_MS5837_DATA;
    return mavlink_finalize_message(msg, system_id, component_id, MAVLINK_MSG_ID_MS5837_DATA_MIN_LEN, MAVLINK_MSG_ID_MS5837_DATA_LEN, MAVLINK_MSG_ID_MS5837_DATA_CRC);
}

/**
 * @brief Pack a ms5837_data message on a channel
 * @param system_id ID of this system
 * @param component_id ID of this component (e.g. 200 for IMU)
 * @param chan The MAVLink channel this message will be sent over
 * @param msg The MAVLink message to compress the data into
 * @param depth Depth of the ROV
 * @param temperature Temperature of the ROV
 * @param pressure pressure of the ROV
 * @return length of the message in bytes (excluding serial stream start sign)
 */
static inline uint16_t mavlink_msg_ms5837_data_pack_chan(uint8_t system_id, uint8_t component_id, uint8_t chan,
                               mavlink_message_t* msg,
                                   float depth,float temperature,float pressure)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
    char buf[MAVLINK_MSG_ID_MS5837_DATA_LEN];
    _mav_put_float(buf, 0, depth);
    _mav_put_float(buf, 4, temperature);
    _mav_put_float(buf, 8, pressure);

        memcpy(_MAV_PAYLOAD_NON_CONST(msg), buf, MAVLINK_MSG_ID_MS5837_DATA_LEN);
#else
    mavlink_ms5837_data_t packet;
    packet.depth = depth;
    packet.temperature = temperature;
    packet.pressure = pressure;

        memcpy(_MAV_PAYLOAD_NON_CONST(msg), &packet, MAVLINK_MSG_ID_MS5837_DATA_LEN);
#endif

    msg->msgid = MAVLINK_MSG_ID_MS5837_DATA;
    return mavlink_finalize_message_chan(msg, system_id, component_id, chan, MAVLINK_MSG_ID_MS5837_DATA_MIN_LEN, MAVLINK_MSG_ID_MS5837_DATA_LEN, MAVLINK_MSG_ID_MS5837_DATA_CRC);
}

/**
 * @brief Encode a ms5837_data struct
 *
 * @param system_id ID of this system
 * @param component_id ID of this component (e.g. 200 for IMU)
 * @param msg The MAVLink message to compress the data into
 * @param ms5837_data C-struct to read the message contents from
 */
static inline uint16_t mavlink_msg_ms5837_data_encode(uint8_t system_id, uint8_t component_id, mavlink_message_t* msg, const mavlink_ms5837_data_t* ms5837_data)
{
    return mavlink_msg_ms5837_data_pack(system_id, component_id, msg, ms5837_data->depth, ms5837_data->temperature, ms5837_data->pressure);
}

/**
 * @brief Encode a ms5837_data struct on a channel
 *
 * @param system_id ID of this system
 * @param component_id ID of this component (e.g. 200 for IMU)
 * @param chan The MAVLink channel this message will be sent over
 * @param msg The MAVLink message to compress the data into
 * @param ms5837_data C-struct to read the message contents from
 */
static inline uint16_t mavlink_msg_ms5837_data_encode_chan(uint8_t system_id, uint8_t component_id, uint8_t chan, mavlink_message_t* msg, const mavlink_ms5837_data_t* ms5837_data)
{
    return mavlink_msg_ms5837_data_pack_chan(system_id, component_id, chan, msg, ms5837_data->depth, ms5837_data->temperature, ms5837_data->pressure);
}

/**
 * @brief Send a ms5837_data message
 * @param chan MAVLink channel to send the message
 *
 * @param depth Depth of the ROV
 * @param temperature Temperature of the ROV
 * @param pressure pressure of the ROV
 */
#ifdef MAVLINK_USE_CONVENIENCE_FUNCTIONS

static inline void mavlink_msg_ms5837_data_send(mavlink_channel_t chan, float depth, float temperature, float pressure)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
    char buf[MAVLINK_MSG_ID_MS5837_DATA_LEN];
    _mav_put_float(buf, 0, depth);
    _mav_put_float(buf, 4, temperature);
    _mav_put_float(buf, 8, pressure);

    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_MS5837_DATA, buf, MAVLINK_MSG_ID_MS5837_DATA_MIN_LEN, MAVLINK_MSG_ID_MS5837_DATA_LEN, MAVLINK_MSG_ID_MS5837_DATA_CRC);
#else
    mavlink_ms5837_data_t packet;
    packet.depth = depth;
    packet.temperature = temperature;
    packet.pressure = pressure;

    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_MS5837_DATA, (const char *)&packet, MAVLINK_MSG_ID_MS5837_DATA_MIN_LEN, MAVLINK_MSG_ID_MS5837_DATA_LEN, MAVLINK_MSG_ID_MS5837_DATA_CRC);
#endif
}

/**
 * @brief Send a ms5837_data message
 * @param chan MAVLink channel to send the message
 * @param struct The MAVLink struct to serialize
 */
static inline void mavlink_msg_ms5837_data_send_struct(mavlink_channel_t chan, const mavlink_ms5837_data_t* ms5837_data)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
    mavlink_msg_ms5837_data_send(chan, ms5837_data->depth, ms5837_data->temperature, ms5837_data->pressure);
#else
    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_MS5837_DATA, (const char *)ms5837_data, MAVLINK_MSG_ID_MS5837_DATA_MIN_LEN, MAVLINK_MSG_ID_MS5837_DATA_LEN, MAVLINK_MSG_ID_MS5837_DATA_CRC);
#endif
}

#if MAVLINK_MSG_ID_MS5837_DATA_LEN <= MAVLINK_MAX_PAYLOAD_LEN
/*
  This varient of _send() can be used to save stack space by re-using
  memory from the receive buffer.  The caller provides a
  mavlink_message_t which is the size of a full mavlink message. This
  is usually the receive buffer for the channel, and allows a reply to an
  incoming message with minimum stack space usage.
 */
static inline void mavlink_msg_ms5837_data_send_buf(mavlink_message_t *msgbuf, mavlink_channel_t chan,  float depth, float temperature, float pressure)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
    char *buf = (char *)msgbuf;
    _mav_put_float(buf, 0, depth);
    _mav_put_float(buf, 4, temperature);
    _mav_put_float(buf, 8, pressure);

    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_MS5837_DATA, buf, MAVLINK_MSG_ID_MS5837_DATA_MIN_LEN, MAVLINK_MSG_ID_MS5837_DATA_LEN, MAVLINK_MSG_ID_MS5837_DATA_CRC);
#else
    mavlink_ms5837_data_t *packet = (mavlink_ms5837_data_t *)msgbuf;
    packet->depth = depth;
    packet->temperature = temperature;
    packet->pressure = pressure;

    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_MS5837_DATA, (const char *)packet, MAVLINK_MSG_ID_MS5837_DATA_MIN_LEN, MAVLINK_MSG_ID_MS5837_DATA_LEN, MAVLINK_MSG_ID_MS5837_DATA_CRC);
#endif
}
#endif

#endif

// MESSAGE MS5837_DATA UNPACKING


/**
 * @brief Get field depth from ms5837_data message
 *
 * @return Depth of the ROV
 */
static inline float mavlink_msg_ms5837_data_get_depth(const mavlink_message_t* msg)
{
    return _MAV_RETURN_float(msg,  0);
}

/**
 * @brief Get field temperature from ms5837_data message
 *
 * @return Temperature of the ROV
 */
static inline float mavlink_msg_ms5837_data_get_temperature(const mavlink_message_t* msg)
{
    return _MAV_RETURN_float(msg,  4);
}

/**
 * @brief Get field pressure from ms5837_data message
 *
 * @return pressure of the ROV
 */
static inline float mavlink_msg_ms5837_data_get_pressure(const mavlink_message_t* msg)
{
    return _MAV_RETURN_float(msg,  8);
}

/**
 * @brief Decode a ms5837_data message into a struct
 *
 * @param msg The message to decode
 * @param ms5837_data C-struct to decode the message contents into
 */
static inline void mavlink_msg_ms5837_data_decode(const mavlink_message_t* msg, mavlink_ms5837_data_t* ms5837_data)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
    ms5837_data->depth = mavlink_msg_ms5837_data_get_depth(msg);
    ms5837_data->temperature = mavlink_msg_ms5837_data_get_temperature(msg);
    ms5837_data->pressure = mavlink_msg_ms5837_data_get_pressure(msg);
#else
        uint8_t len = msg->len < MAVLINK_MSG_ID_MS5837_DATA_LEN? msg->len : MAVLINK_MSG_ID_MS5837_DATA_LEN;
        memset(ms5837_data, 0, MAVLINK_MSG_ID_MS5837_DATA_LEN);
    memcpy(ms5837_data, _MAV_PAYLOAD(msg), len);
#endif
}
