#pragma once
// MESSAGE SENSOR_DATA PACKING

#define MAVLINK_MSG_ID_SENSOR_DATA 151

MAVPACKED(
typedef struct __mavlink_sensor_data_t {
 float depth; /*< Depth of the ROV*/
 float temperature; /*< Temperature of the ROV*/
 float pressure; /*< pressure of the ROV*/
 float roll; /*< roll data of the ROV*/
 float yaw; /*< yaw data of the ROV*/
 float pitch; /*< pitch data of the ROV*/
 float roll_acc; /*< roll acceleration of the ROV*/
 float yaw_acc; /*< yaw acceleration of the ROV*/
 float pitch_acc; /*< pitch acceleration of the ROV*/
}) mavlink_sensor_data_t;

#define MAVLINK_MSG_ID_SENSOR_DATA_LEN 36
#define MAVLINK_MSG_ID_SENSOR_DATA_MIN_LEN 36
#define MAVLINK_MSG_ID_151_LEN 36
#define MAVLINK_MSG_ID_151_MIN_LEN 36

#define MAVLINK_MSG_ID_SENSOR_DATA_CRC 178
#define MAVLINK_MSG_ID_151_CRC 178



#if MAVLINK_COMMAND_24BIT
#define MAVLINK_MESSAGE_INFO_SENSOR_DATA { \
    151, \
    "SENSOR_DATA", \
    9, \
    {  { "depth", NULL, MAVLINK_TYPE_FLOAT, 0, 0, offsetof(mavlink_sensor_data_t, depth) }, \
         { "temperature", NULL, MAVLINK_TYPE_FLOAT, 0, 4, offsetof(mavlink_sensor_data_t, temperature) }, \
         { "pressure", NULL, MAVLINK_TYPE_FLOAT, 0, 8, offsetof(mavlink_sensor_data_t, pressure) }, \
         { "roll", NULL, MAVLINK_TYPE_FLOAT, 0, 12, offsetof(mavlink_sensor_data_t, roll) }, \
         { "yaw", NULL, MAVLINK_TYPE_FLOAT, 0, 16, offsetof(mavlink_sensor_data_t, yaw) }, \
         { "pitch", NULL, MAVLINK_TYPE_FLOAT, 0, 20, offsetof(mavlink_sensor_data_t, pitch) }, \
         { "roll_acc", NULL, MAVLINK_TYPE_FLOAT, 0, 24, offsetof(mavlink_sensor_data_t, roll_acc) }, \
         { "yaw_acc", NULL, MAVLINK_TYPE_FLOAT, 0, 28, offsetof(mavlink_sensor_data_t, yaw_acc) }, \
         { "pitch_acc", NULL, MAVLINK_TYPE_FLOAT, 0, 32, offsetof(mavlink_sensor_data_t, pitch_acc) }, \
         } \
}
#else
#define MAVLINK_MESSAGE_INFO_SENSOR_DATA { \
    "SENSOR_DATA", \
    9, \
    {  { "depth", NULL, MAVLINK_TYPE_FLOAT, 0, 0, offsetof(mavlink_sensor_data_t, depth) }, \
         { "temperature", NULL, MAVLINK_TYPE_FLOAT, 0, 4, offsetof(mavlink_sensor_data_t, temperature) }, \
         { "pressure", NULL, MAVLINK_TYPE_FLOAT, 0, 8, offsetof(mavlink_sensor_data_t, pressure) }, \
         { "roll", NULL, MAVLINK_TYPE_FLOAT, 0, 12, offsetof(mavlink_sensor_data_t, roll) }, \
         { "yaw", NULL, MAVLINK_TYPE_FLOAT, 0, 16, offsetof(mavlink_sensor_data_t, yaw) }, \
         { "pitch", NULL, MAVLINK_TYPE_FLOAT, 0, 20, offsetof(mavlink_sensor_data_t, pitch) }, \
         { "roll_acc", NULL, MAVLINK_TYPE_FLOAT, 0, 24, offsetof(mavlink_sensor_data_t, roll_acc) }, \
         { "yaw_acc", NULL, MAVLINK_TYPE_FLOAT, 0, 28, offsetof(mavlink_sensor_data_t, yaw_acc) }, \
         { "pitch_acc", NULL, MAVLINK_TYPE_FLOAT, 0, 32, offsetof(mavlink_sensor_data_t, pitch_acc) }, \
         } \
}
#endif

/**
 * @brief Pack a sensor_data message
 * @param system_id ID of this system
 * @param component_id ID of this component (e.g. 200 for IMU)
 * @param msg The MAVLink message to compress the data into
 *
 * @param depth Depth of the ROV
 * @param temperature Temperature of the ROV
 * @param pressure pressure of the ROV
 * @param roll roll data of the ROV
 * @param yaw yaw data of the ROV
 * @param pitch pitch data of the ROV
 * @param roll_acc roll acceleration of the ROV
 * @param yaw_acc yaw acceleration of the ROV
 * @param pitch_acc pitch acceleration of the ROV
 * @return length of the message in bytes (excluding serial stream start sign)
 */
static inline uint16_t mavlink_msg_sensor_data_pack(uint8_t system_id, uint8_t component_id, mavlink_message_t* msg,
                               float depth, float temperature, float pressure, float roll, float yaw, float pitch, float roll_acc, float yaw_acc, float pitch_acc)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
    char buf[MAVLINK_MSG_ID_SENSOR_DATA_LEN];
    _mav_put_float(buf, 0, depth);
    _mav_put_float(buf, 4, temperature);
    _mav_put_float(buf, 8, pressure);
    _mav_put_float(buf, 12, roll);
    _mav_put_float(buf, 16, yaw);
    _mav_put_float(buf, 20, pitch);
    _mav_put_float(buf, 24, roll_acc);
    _mav_put_float(buf, 28, yaw_acc);
    _mav_put_float(buf, 32, pitch_acc);

        memcpy(_MAV_PAYLOAD_NON_CONST(msg), buf, MAVLINK_MSG_ID_SENSOR_DATA_LEN);
#else
    mavlink_sensor_data_t packet;
    packet.depth = depth;
    packet.temperature = temperature;
    packet.pressure = pressure;
    packet.roll = roll;
    packet.yaw = yaw;
    packet.pitch = pitch;
    packet.roll_acc = roll_acc;
    packet.yaw_acc = yaw_acc;
    packet.pitch_acc = pitch_acc;

        memcpy(_MAV_PAYLOAD_NON_CONST(msg), &packet, MAVLINK_MSG_ID_SENSOR_DATA_LEN);
#endif

    msg->msgid = MAVLINK_MSG_ID_SENSOR_DATA;
    return mavlink_finalize_message(msg, system_id, component_id, MAVLINK_MSG_ID_SENSOR_DATA_MIN_LEN, MAVLINK_MSG_ID_SENSOR_DATA_LEN, MAVLINK_MSG_ID_SENSOR_DATA_CRC);
}

/**
 * @brief Pack a sensor_data message on a channel
 * @param system_id ID of this system
 * @param component_id ID of this component (e.g. 200 for IMU)
 * @param chan The MAVLink channel this message will be sent over
 * @param msg The MAVLink message to compress the data into
 * @param depth Depth of the ROV
 * @param temperature Temperature of the ROV
 * @param pressure pressure of the ROV
 * @param roll roll data of the ROV
 * @param yaw yaw data of the ROV
 * @param pitch pitch data of the ROV
 * @param roll_acc roll acceleration of the ROV
 * @param yaw_acc yaw acceleration of the ROV
 * @param pitch_acc pitch acceleration of the ROV
 * @return length of the message in bytes (excluding serial stream start sign)
 */
static inline uint16_t mavlink_msg_sensor_data_pack_chan(uint8_t system_id, uint8_t component_id, uint8_t chan,
                               mavlink_message_t* msg,
                                   float depth,float temperature,float pressure,float roll,float yaw,float pitch,float roll_acc,float yaw_acc,float pitch_acc)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
    char buf[MAVLINK_MSG_ID_SENSOR_DATA_LEN];
    _mav_put_float(buf, 0, depth);
    _mav_put_float(buf, 4, temperature);
    _mav_put_float(buf, 8, pressure);
    _mav_put_float(buf, 12, roll);
    _mav_put_float(buf, 16, yaw);
    _mav_put_float(buf, 20, pitch);
    _mav_put_float(buf, 24, roll_acc);
    _mav_put_float(buf, 28, yaw_acc);
    _mav_put_float(buf, 32, pitch_acc);

        memcpy(_MAV_PAYLOAD_NON_CONST(msg), buf, MAVLINK_MSG_ID_SENSOR_DATA_LEN);
#else
    mavlink_sensor_data_t packet;
    packet.depth = depth;
    packet.temperature = temperature;
    packet.pressure = pressure;
    packet.roll = roll;
    packet.yaw = yaw;
    packet.pitch = pitch;
    packet.roll_acc = roll_acc;
    packet.yaw_acc = yaw_acc;
    packet.pitch_acc = pitch_acc;

        memcpy(_MAV_PAYLOAD_NON_CONST(msg), &packet, MAVLINK_MSG_ID_SENSOR_DATA_LEN);
#endif

    msg->msgid = MAVLINK_MSG_ID_SENSOR_DATA;
    return mavlink_finalize_message_chan(msg, system_id, component_id, chan, MAVLINK_MSG_ID_SENSOR_DATA_MIN_LEN, MAVLINK_MSG_ID_SENSOR_DATA_LEN, MAVLINK_MSG_ID_SENSOR_DATA_CRC);
}

/**
 * @brief Encode a sensor_data struct
 *
 * @param system_id ID of this system
 * @param component_id ID of this component (e.g. 200 for IMU)
 * @param msg The MAVLink message to compress the data into
 * @param sensor_data C-struct to read the message contents from
 */
static inline uint16_t mavlink_msg_sensor_data_encode(uint8_t system_id, uint8_t component_id, mavlink_message_t* msg, const mavlink_sensor_data_t* sensor_data)
{
    return mavlink_msg_sensor_data_pack(system_id, component_id, msg, sensor_data->depth, sensor_data->temperature, sensor_data->pressure, sensor_data->roll, sensor_data->yaw, sensor_data->pitch, sensor_data->roll_acc, sensor_data->yaw_acc, sensor_data->pitch_acc);
}

/**
 * @brief Encode a sensor_data struct on a channel
 *
 * @param system_id ID of this system
 * @param component_id ID of this component (e.g. 200 for IMU)
 * @param chan The MAVLink channel this message will be sent over
 * @param msg The MAVLink message to compress the data into
 * @param sensor_data C-struct to read the message contents from
 */
static inline uint16_t mavlink_msg_sensor_data_encode_chan(uint8_t system_id, uint8_t component_id, uint8_t chan, mavlink_message_t* msg, const mavlink_sensor_data_t* sensor_data)
{
    return mavlink_msg_sensor_data_pack_chan(system_id, component_id, chan, msg, sensor_data->depth, sensor_data->temperature, sensor_data->pressure, sensor_data->roll, sensor_data->yaw, sensor_data->pitch, sensor_data->roll_acc, sensor_data->yaw_acc, sensor_data->pitch_acc);
}

/**
 * @brief Send a sensor_data message
 * @param chan MAVLink channel to send the message
 *
 * @param depth Depth of the ROV
 * @param temperature Temperature of the ROV
 * @param pressure pressure of the ROV
 * @param roll roll data of the ROV
 * @param yaw yaw data of the ROV
 * @param pitch pitch data of the ROV
 * @param roll_acc roll acceleration of the ROV
 * @param yaw_acc yaw acceleration of the ROV
 * @param pitch_acc pitch acceleration of the ROV
 */
#ifdef MAVLINK_USE_CONVENIENCE_FUNCTIONS

static inline void mavlink_msg_sensor_data_send(mavlink_channel_t chan, float depth, float temperature, float pressure, float roll, float yaw, float pitch, float roll_acc, float yaw_acc, float pitch_acc)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
    char buf[MAVLINK_MSG_ID_SENSOR_DATA_LEN];
    _mav_put_float(buf, 0, depth);
    _mav_put_float(buf, 4, temperature);
    _mav_put_float(buf, 8, pressure);
    _mav_put_float(buf, 12, roll);
    _mav_put_float(buf, 16, yaw);
    _mav_put_float(buf, 20, pitch);
    _mav_put_float(buf, 24, roll_acc);
    _mav_put_float(buf, 28, yaw_acc);
    _mav_put_float(buf, 32, pitch_acc);

    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_SENSOR_DATA, buf, MAVLINK_MSG_ID_SENSOR_DATA_MIN_LEN, MAVLINK_MSG_ID_SENSOR_DATA_LEN, MAVLINK_MSG_ID_SENSOR_DATA_CRC);
#else
    mavlink_sensor_data_t packet;
    packet.depth = depth;
    packet.temperature = temperature;
    packet.pressure = pressure;
    packet.roll = roll;
    packet.yaw = yaw;
    packet.pitch = pitch;
    packet.roll_acc = roll_acc;
    packet.yaw_acc = yaw_acc;
    packet.pitch_acc = pitch_acc;

    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_SENSOR_DATA, (const char *)&packet, MAVLINK_MSG_ID_SENSOR_DATA_MIN_LEN, MAVLINK_MSG_ID_SENSOR_DATA_LEN, MAVLINK_MSG_ID_SENSOR_DATA_CRC);
#endif
}

/**
 * @brief Send a sensor_data message
 * @param chan MAVLink channel to send the message
 * @param struct The MAVLink struct to serialize
 */
static inline void mavlink_msg_sensor_data_send_struct(mavlink_channel_t chan, const mavlink_sensor_data_t* sensor_data)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
    mavlink_msg_sensor_data_send(chan, sensor_data->depth, sensor_data->temperature, sensor_data->pressure, sensor_data->roll, sensor_data->yaw, sensor_data->pitch, sensor_data->roll_acc, sensor_data->yaw_acc, sensor_data->pitch_acc);
#else
    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_SENSOR_DATA, (const char *)sensor_data, MAVLINK_MSG_ID_SENSOR_DATA_MIN_LEN, MAVLINK_MSG_ID_SENSOR_DATA_LEN, MAVLINK_MSG_ID_SENSOR_DATA_CRC);
#endif
}

#if MAVLINK_MSG_ID_SENSOR_DATA_LEN <= MAVLINK_MAX_PAYLOAD_LEN
/*
  This varient of _send() can be used to save stack space by re-using
  memory from the receive buffer.  The caller provides a
  mavlink_message_t which is the size of a full mavlink message. This
  is usually the receive buffer for the channel, and allows a reply to an
  incoming message with minimum stack space usage.
 */
static inline void mavlink_msg_sensor_data_send_buf(mavlink_message_t *msgbuf, mavlink_channel_t chan,  float depth, float temperature, float pressure, float roll, float yaw, float pitch, float roll_acc, float yaw_acc, float pitch_acc)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
    char *buf = (char *)msgbuf;
    _mav_put_float(buf, 0, depth);
    _mav_put_float(buf, 4, temperature);
    _mav_put_float(buf, 8, pressure);
    _mav_put_float(buf, 12, roll);
    _mav_put_float(buf, 16, yaw);
    _mav_put_float(buf, 20, pitch);
    _mav_put_float(buf, 24, roll_acc);
    _mav_put_float(buf, 28, yaw_acc);
    _mav_put_float(buf, 32, pitch_acc);

    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_SENSOR_DATA, buf, MAVLINK_MSG_ID_SENSOR_DATA_MIN_LEN, MAVLINK_MSG_ID_SENSOR_DATA_LEN, MAVLINK_MSG_ID_SENSOR_DATA_CRC);
#else
    mavlink_sensor_data_t *packet = (mavlink_sensor_data_t *)msgbuf;
    packet->depth = depth;
    packet->temperature = temperature;
    packet->pressure = pressure;
    packet->roll = roll;
    packet->yaw = yaw;
    packet->pitch = pitch;
    packet->roll_acc = roll_acc;
    packet->yaw_acc = yaw_acc;
    packet->pitch_acc = pitch_acc;

    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_SENSOR_DATA, (const char *)packet, MAVLINK_MSG_ID_SENSOR_DATA_MIN_LEN, MAVLINK_MSG_ID_SENSOR_DATA_LEN, MAVLINK_MSG_ID_SENSOR_DATA_CRC);
#endif
}
#endif

#endif

// MESSAGE SENSOR_DATA UNPACKING


/**
 * @brief Get field depth from sensor_data message
 *
 * @return Depth of the ROV
 */
static inline float mavlink_msg_sensor_data_get_depth(const mavlink_message_t* msg)
{
    return _MAV_RETURN_float(msg,  0);
}

/**
 * @brief Get field temperature from sensor_data message
 *
 * @return Temperature of the ROV
 */
static inline float mavlink_msg_sensor_data_get_temperature(const mavlink_message_t* msg)
{
    return _MAV_RETURN_float(msg,  4);
}

/**
 * @brief Get field pressure from sensor_data message
 *
 * @return pressure of the ROV
 */
static inline float mavlink_msg_sensor_data_get_pressure(const mavlink_message_t* msg)
{
    return _MAV_RETURN_float(msg,  8);
}

/**
 * @brief Get field roll from sensor_data message
 *
 * @return roll data of the ROV
 */
static inline float mavlink_msg_sensor_data_get_roll(const mavlink_message_t* msg)
{
    return _MAV_RETURN_float(msg,  12);
}

/**
 * @brief Get field yaw from sensor_data message
 *
 * @return yaw data of the ROV
 */
static inline float mavlink_msg_sensor_data_get_yaw(const mavlink_message_t* msg)
{
    return _MAV_RETURN_float(msg,  16);
}

/**
 * @brief Get field pitch from sensor_data message
 *
 * @return pitch data of the ROV
 */
static inline float mavlink_msg_sensor_data_get_pitch(const mavlink_message_t* msg)
{
    return _MAV_RETURN_float(msg,  20);
}

/**
 * @brief Get field roll_acc from sensor_data message
 *
 * @return roll acceleration of the ROV
 */
static inline float mavlink_msg_sensor_data_get_roll_acc(const mavlink_message_t* msg)
{
    return _MAV_RETURN_float(msg,  24);
}

/**
 * @brief Get field yaw_acc from sensor_data message
 *
 * @return yaw acceleration of the ROV
 */
static inline float mavlink_msg_sensor_data_get_yaw_acc(const mavlink_message_t* msg)
{
    return _MAV_RETURN_float(msg,  28);
}

/**
 * @brief Get field pitch_acc from sensor_data message
 *
 * @return pitch acceleration of the ROV
 */
static inline float mavlink_msg_sensor_data_get_pitch_acc(const mavlink_message_t* msg)
{
    return _MAV_RETURN_float(msg,  32);
}

/**
 * @brief Decode a sensor_data message into a struct
 *
 * @param msg The message to decode
 * @param sensor_data C-struct to decode the message contents into
 */
static inline void mavlink_msg_sensor_data_decode(const mavlink_message_t* msg, mavlink_sensor_data_t* sensor_data)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
    sensor_data->depth = mavlink_msg_sensor_data_get_depth(msg);
    sensor_data->temperature = mavlink_msg_sensor_data_get_temperature(msg);
    sensor_data->pressure = mavlink_msg_sensor_data_get_pressure(msg);
    sensor_data->roll = mavlink_msg_sensor_data_get_roll(msg);
    sensor_data->yaw = mavlink_msg_sensor_data_get_yaw(msg);
    sensor_data->pitch = mavlink_msg_sensor_data_get_pitch(msg);
    sensor_data->roll_acc = mavlink_msg_sensor_data_get_roll_acc(msg);
    sensor_data->yaw_acc = mavlink_msg_sensor_data_get_yaw_acc(msg);
    sensor_data->pitch_acc = mavlink_msg_sensor_data_get_pitch_acc(msg);
#else
        uint8_t len = msg->len < MAVLINK_MSG_ID_SENSOR_DATA_LEN? msg->len : MAVLINK_MSG_ID_SENSOR_DATA_LEN;
        memset(sensor_data, 0, MAVLINK_MSG_ID_SENSOR_DATA_LEN);
    memcpy(sensor_data, _MAV_PAYLOAD(msg), len);
#endif
}
