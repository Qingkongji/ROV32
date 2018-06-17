#pragma once
// MESSAGE JY901_DATA PACKING

#define MAVLINK_MSG_ID_JY901_DATA 152

MAVPACKED(
typedef struct __mavlink_jy901_data_t {
 float roll; /*< roll data of the ROV*/
 float yaw; /*< yaw data of the ROV*/
 float pitch; /*< pitch data of the ROV*/
 float roll_v; /*< roll velocity of the ROV*/
 float yaw_v; /*< yaw velocity of the ROV*/
 float pitch_v; /*< pitch velocity of the ROV*/
 float x_acc; /*< x acceleration of the ROV*/
 float y_acc; /*< y acceleration of the ROV*/
 float z_acc; /*< z acceleration of the ROV*/
 float x_m; /*< x magnetic field of the ROV*/
 float y_m; /*< y magnetic field of the ROV*/
 float z_m; /*< z magnetic field of the ROV*/
}) mavlink_jy901_data_t;

#define MAVLINK_MSG_ID_JY901_DATA_LEN 48
#define MAVLINK_MSG_ID_JY901_DATA_MIN_LEN 48
#define MAVLINK_MSG_ID_152_LEN 48
#define MAVLINK_MSG_ID_152_MIN_LEN 48

#define MAVLINK_MSG_ID_JY901_DATA_CRC 241
#define MAVLINK_MSG_ID_152_CRC 241



#if MAVLINK_COMMAND_24BIT
#define MAVLINK_MESSAGE_INFO_JY901_DATA { \
    152, \
    "JY901_DATA", \
    12, \
    {  { "roll", NULL, MAVLINK_TYPE_FLOAT, 0, 0, offsetof(mavlink_jy901_data_t, roll) }, \
         { "yaw", NULL, MAVLINK_TYPE_FLOAT, 0, 4, offsetof(mavlink_jy901_data_t, yaw) }, \
         { "pitch", NULL, MAVLINK_TYPE_FLOAT, 0, 8, offsetof(mavlink_jy901_data_t, pitch) }, \
         { "roll_v", NULL, MAVLINK_TYPE_FLOAT, 0, 12, offsetof(mavlink_jy901_data_t, roll_v) }, \
         { "yaw_v", NULL, MAVLINK_TYPE_FLOAT, 0, 16, offsetof(mavlink_jy901_data_t, yaw_v) }, \
         { "pitch_v", NULL, MAVLINK_TYPE_FLOAT, 0, 20, offsetof(mavlink_jy901_data_t, pitch_v) }, \
         { "x_acc", NULL, MAVLINK_TYPE_FLOAT, 0, 24, offsetof(mavlink_jy901_data_t, x_acc) }, \
         { "y_acc", NULL, MAVLINK_TYPE_FLOAT, 0, 28, offsetof(mavlink_jy901_data_t, y_acc) }, \
         { "z_acc", NULL, MAVLINK_TYPE_FLOAT, 0, 32, offsetof(mavlink_jy901_data_t, z_acc) }, \
         { "x_m", NULL, MAVLINK_TYPE_FLOAT, 0, 36, offsetof(mavlink_jy901_data_t, x_m) }, \
         { "y_m", NULL, MAVLINK_TYPE_FLOAT, 0, 40, offsetof(mavlink_jy901_data_t, y_m) }, \
         { "z_m", NULL, MAVLINK_TYPE_FLOAT, 0, 44, offsetof(mavlink_jy901_data_t, z_m) }, \
         } \
}
#else
#define MAVLINK_MESSAGE_INFO_JY901_DATA { \
    "JY901_DATA", \
    12, \
    {  { "roll", NULL, MAVLINK_TYPE_FLOAT, 0, 0, offsetof(mavlink_jy901_data_t, roll) }, \
         { "yaw", NULL, MAVLINK_TYPE_FLOAT, 0, 4, offsetof(mavlink_jy901_data_t, yaw) }, \
         { "pitch", NULL, MAVLINK_TYPE_FLOAT, 0, 8, offsetof(mavlink_jy901_data_t, pitch) }, \
         { "roll_v", NULL, MAVLINK_TYPE_FLOAT, 0, 12, offsetof(mavlink_jy901_data_t, roll_v) }, \
         { "yaw_v", NULL, MAVLINK_TYPE_FLOAT, 0, 16, offsetof(mavlink_jy901_data_t, yaw_v) }, \
         { "pitch_v", NULL, MAVLINK_TYPE_FLOAT, 0, 20, offsetof(mavlink_jy901_data_t, pitch_v) }, \
         { "x_acc", NULL, MAVLINK_TYPE_FLOAT, 0, 24, offsetof(mavlink_jy901_data_t, x_acc) }, \
         { "y_acc", NULL, MAVLINK_TYPE_FLOAT, 0, 28, offsetof(mavlink_jy901_data_t, y_acc) }, \
         { "z_acc", NULL, MAVLINK_TYPE_FLOAT, 0, 32, offsetof(mavlink_jy901_data_t, z_acc) }, \
         { "x_m", NULL, MAVLINK_TYPE_FLOAT, 0, 36, offsetof(mavlink_jy901_data_t, x_m) }, \
         { "y_m", NULL, MAVLINK_TYPE_FLOAT, 0, 40, offsetof(mavlink_jy901_data_t, y_m) }, \
         { "z_m", NULL, MAVLINK_TYPE_FLOAT, 0, 44, offsetof(mavlink_jy901_data_t, z_m) }, \
         } \
}
#endif

/**
 * @brief Pack a jy901_data message
 * @param system_id ID of this system
 * @param component_id ID of this component (e.g. 200 for IMU)
 * @param msg The MAVLink message to compress the data into
 *
 * @param roll roll data of the ROV
 * @param yaw yaw data of the ROV
 * @param pitch pitch data of the ROV
 * @param roll_v roll velocity of the ROV
 * @param yaw_v yaw velocity of the ROV
 * @param pitch_v pitch velocity of the ROV
 * @param x_acc x acceleration of the ROV
 * @param y_acc y acceleration of the ROV
 * @param z_acc z acceleration of the ROV
 * @param x_m x magnetic field of the ROV
 * @param y_m y magnetic field of the ROV
 * @param z_m z magnetic field of the ROV
 * @return length of the message in bytes (excluding serial stream start sign)
 */
static inline uint16_t mavlink_msg_jy901_data_pack(uint8_t system_id, uint8_t component_id, mavlink_message_t* msg,
                               float roll, float yaw, float pitch, float roll_v, float yaw_v, float pitch_v, float x_acc, float y_acc, float z_acc, float x_m, float y_m, float z_m)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
    char buf[MAVLINK_MSG_ID_JY901_DATA_LEN];
    _mav_put_float(buf, 0, roll);
    _mav_put_float(buf, 4, yaw);
    _mav_put_float(buf, 8, pitch);
    _mav_put_float(buf, 12, roll_v);
    _mav_put_float(buf, 16, yaw_v);
    _mav_put_float(buf, 20, pitch_v);
    _mav_put_float(buf, 24, x_acc);
    _mav_put_float(buf, 28, y_acc);
    _mav_put_float(buf, 32, z_acc);
    _mav_put_float(buf, 36, x_m);
    _mav_put_float(buf, 40, y_m);
    _mav_put_float(buf, 44, z_m);

        memcpy(_MAV_PAYLOAD_NON_CONST(msg), buf, MAVLINK_MSG_ID_JY901_DATA_LEN);
#else
    mavlink_jy901_data_t packet;
    packet.roll = roll;
    packet.yaw = yaw;
    packet.pitch = pitch;
    packet.roll_v = roll_v;
    packet.yaw_v = yaw_v;
    packet.pitch_v = pitch_v;
    packet.x_acc = x_acc;
    packet.y_acc = y_acc;
    packet.z_acc = z_acc;
    packet.x_m = x_m;
    packet.y_m = y_m;
    packet.z_m = z_m;

        memcpy(_MAV_PAYLOAD_NON_CONST(msg), &packet, MAVLINK_MSG_ID_JY901_DATA_LEN);
#endif

    msg->msgid = MAVLINK_MSG_ID_JY901_DATA;
    return mavlink_finalize_message(msg, system_id, component_id, MAVLINK_MSG_ID_JY901_DATA_MIN_LEN, MAVLINK_MSG_ID_JY901_DATA_LEN, MAVLINK_MSG_ID_JY901_DATA_CRC);
}

/**
 * @brief Pack a jy901_data message on a channel
 * @param system_id ID of this system
 * @param component_id ID of this component (e.g. 200 for IMU)
 * @param chan The MAVLink channel this message will be sent over
 * @param msg The MAVLink message to compress the data into
 * @param roll roll data of the ROV
 * @param yaw yaw data of the ROV
 * @param pitch pitch data of the ROV
 * @param roll_v roll velocity of the ROV
 * @param yaw_v yaw velocity of the ROV
 * @param pitch_v pitch velocity of the ROV
 * @param x_acc x acceleration of the ROV
 * @param y_acc y acceleration of the ROV
 * @param z_acc z acceleration of the ROV
 * @param x_m x magnetic field of the ROV
 * @param y_m y magnetic field of the ROV
 * @param z_m z magnetic field of the ROV
 * @return length of the message in bytes (excluding serial stream start sign)
 */
static inline uint16_t mavlink_msg_jy901_data_pack_chan(uint8_t system_id, uint8_t component_id, uint8_t chan,
                               mavlink_message_t* msg,
                                   float roll,float yaw,float pitch,float roll_v,float yaw_v,float pitch_v,float x_acc,float y_acc,float z_acc,float x_m,float y_m,float z_m)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
    char buf[MAVLINK_MSG_ID_JY901_DATA_LEN];
    _mav_put_float(buf, 0, roll);
    _mav_put_float(buf, 4, yaw);
    _mav_put_float(buf, 8, pitch);
    _mav_put_float(buf, 12, roll_v);
    _mav_put_float(buf, 16, yaw_v);
    _mav_put_float(buf, 20, pitch_v);
    _mav_put_float(buf, 24, x_acc);
    _mav_put_float(buf, 28, y_acc);
    _mav_put_float(buf, 32, z_acc);
    _mav_put_float(buf, 36, x_m);
    _mav_put_float(buf, 40, y_m);
    _mav_put_float(buf, 44, z_m);

        memcpy(_MAV_PAYLOAD_NON_CONST(msg), buf, MAVLINK_MSG_ID_JY901_DATA_LEN);
#else
    mavlink_jy901_data_t packet;
    packet.roll = roll;
    packet.yaw = yaw;
    packet.pitch = pitch;
    packet.roll_v = roll_v;
    packet.yaw_v = yaw_v;
    packet.pitch_v = pitch_v;
    packet.x_acc = x_acc;
    packet.y_acc = y_acc;
    packet.z_acc = z_acc;
    packet.x_m = x_m;
    packet.y_m = y_m;
    packet.z_m = z_m;

        memcpy(_MAV_PAYLOAD_NON_CONST(msg), &packet, MAVLINK_MSG_ID_JY901_DATA_LEN);
#endif

    msg->msgid = MAVLINK_MSG_ID_JY901_DATA;
    return mavlink_finalize_message_chan(msg, system_id, component_id, chan, MAVLINK_MSG_ID_JY901_DATA_MIN_LEN, MAVLINK_MSG_ID_JY901_DATA_LEN, MAVLINK_MSG_ID_JY901_DATA_CRC);
}

/**
 * @brief Encode a jy901_data struct
 *
 * @param system_id ID of this system
 * @param component_id ID of this component (e.g. 200 for IMU)
 * @param msg The MAVLink message to compress the data into
 * @param jy901_data C-struct to read the message contents from
 */
static inline uint16_t mavlink_msg_jy901_data_encode(uint8_t system_id, uint8_t component_id, mavlink_message_t* msg, const mavlink_jy901_data_t* jy901_data)
{
    return mavlink_msg_jy901_data_pack(system_id, component_id, msg, jy901_data->roll, jy901_data->yaw, jy901_data->pitch, jy901_data->roll_v, jy901_data->yaw_v, jy901_data->pitch_v, jy901_data->x_acc, jy901_data->y_acc, jy901_data->z_acc, jy901_data->x_m, jy901_data->y_m, jy901_data->z_m);
}

/**
 * @brief Encode a jy901_data struct on a channel
 *
 * @param system_id ID of this system
 * @param component_id ID of this component (e.g. 200 for IMU)
 * @param chan The MAVLink channel this message will be sent over
 * @param msg The MAVLink message to compress the data into
 * @param jy901_data C-struct to read the message contents from
 */
static inline uint16_t mavlink_msg_jy901_data_encode_chan(uint8_t system_id, uint8_t component_id, uint8_t chan, mavlink_message_t* msg, const mavlink_jy901_data_t* jy901_data)
{
    return mavlink_msg_jy901_data_pack_chan(system_id, component_id, chan, msg, jy901_data->roll, jy901_data->yaw, jy901_data->pitch, jy901_data->roll_v, jy901_data->yaw_v, jy901_data->pitch_v, jy901_data->x_acc, jy901_data->y_acc, jy901_data->z_acc, jy901_data->x_m, jy901_data->y_m, jy901_data->z_m);
}

/**
 * @brief Send a jy901_data message
 * @param chan MAVLink channel to send the message
 *
 * @param roll roll data of the ROV
 * @param yaw yaw data of the ROV
 * @param pitch pitch data of the ROV
 * @param roll_v roll velocity of the ROV
 * @param yaw_v yaw velocity of the ROV
 * @param pitch_v pitch velocity of the ROV
 * @param x_acc x acceleration of the ROV
 * @param y_acc y acceleration of the ROV
 * @param z_acc z acceleration of the ROV
 * @param x_m x magnetic field of the ROV
 * @param y_m y magnetic field of the ROV
 * @param z_m z magnetic field of the ROV
 */
#ifdef MAVLINK_USE_CONVENIENCE_FUNCTIONS

static inline void mavlink_msg_jy901_data_send(mavlink_channel_t chan, float roll, float yaw, float pitch, float roll_v, float yaw_v, float pitch_v, float x_acc, float y_acc, float z_acc, float x_m, float y_m, float z_m)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
    char buf[MAVLINK_MSG_ID_JY901_DATA_LEN];
    _mav_put_float(buf, 0, roll);
    _mav_put_float(buf, 4, yaw);
    _mav_put_float(buf, 8, pitch);
    _mav_put_float(buf, 12, roll_v);
    _mav_put_float(buf, 16, yaw_v);
    _mav_put_float(buf, 20, pitch_v);
    _mav_put_float(buf, 24, x_acc);
    _mav_put_float(buf, 28, y_acc);
    _mav_put_float(buf, 32, z_acc);
    _mav_put_float(buf, 36, x_m);
    _mav_put_float(buf, 40, y_m);
    _mav_put_float(buf, 44, z_m);

    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_JY901_DATA, buf, MAVLINK_MSG_ID_JY901_DATA_MIN_LEN, MAVLINK_MSG_ID_JY901_DATA_LEN, MAVLINK_MSG_ID_JY901_DATA_CRC);
#else
    mavlink_jy901_data_t packet;
    packet.roll = roll;
    packet.yaw = yaw;
    packet.pitch = pitch;
    packet.roll_v = roll_v;
    packet.yaw_v = yaw_v;
    packet.pitch_v = pitch_v;
    packet.x_acc = x_acc;
    packet.y_acc = y_acc;
    packet.z_acc = z_acc;
    packet.x_m = x_m;
    packet.y_m = y_m;
    packet.z_m = z_m;

    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_JY901_DATA, (const char *)&packet, MAVLINK_MSG_ID_JY901_DATA_MIN_LEN, MAVLINK_MSG_ID_JY901_DATA_LEN, MAVLINK_MSG_ID_JY901_DATA_CRC);
#endif
}

/**
 * @brief Send a jy901_data message
 * @param chan MAVLink channel to send the message
 * @param struct The MAVLink struct to serialize
 */
static inline void mavlink_msg_jy901_data_send_struct(mavlink_channel_t chan, const mavlink_jy901_data_t* jy901_data)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
    mavlink_msg_jy901_data_send(chan, jy901_data->roll, jy901_data->yaw, jy901_data->pitch, jy901_data->roll_v, jy901_data->yaw_v, jy901_data->pitch_v, jy901_data->x_acc, jy901_data->y_acc, jy901_data->z_acc, jy901_data->x_m, jy901_data->y_m, jy901_data->z_m);
#else
    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_JY901_DATA, (const char *)jy901_data, MAVLINK_MSG_ID_JY901_DATA_MIN_LEN, MAVLINK_MSG_ID_JY901_DATA_LEN, MAVLINK_MSG_ID_JY901_DATA_CRC);
#endif
}

#if MAVLINK_MSG_ID_JY901_DATA_LEN <= MAVLINK_MAX_PAYLOAD_LEN
/*
  This varient of _send() can be used to save stack space by re-using
  memory from the receive buffer.  The caller provides a
  mavlink_message_t which is the size of a full mavlink message. This
  is usually the receive buffer for the channel, and allows a reply to an
  incoming message with minimum stack space usage.
 */
static inline void mavlink_msg_jy901_data_send_buf(mavlink_message_t *msgbuf, mavlink_channel_t chan,  float roll, float yaw, float pitch, float roll_v, float yaw_v, float pitch_v, float x_acc, float y_acc, float z_acc, float x_m, float y_m, float z_m)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
    char *buf = (char *)msgbuf;
    _mav_put_float(buf, 0, roll);
    _mav_put_float(buf, 4, yaw);
    _mav_put_float(buf, 8, pitch);
    _mav_put_float(buf, 12, roll_v);
    _mav_put_float(buf, 16, yaw_v);
    _mav_put_float(buf, 20, pitch_v);
    _mav_put_float(buf, 24, x_acc);
    _mav_put_float(buf, 28, y_acc);
    _mav_put_float(buf, 32, z_acc);
    _mav_put_float(buf, 36, x_m);
    _mav_put_float(buf, 40, y_m);
    _mav_put_float(buf, 44, z_m);

    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_JY901_DATA, buf, MAVLINK_MSG_ID_JY901_DATA_MIN_LEN, MAVLINK_MSG_ID_JY901_DATA_LEN, MAVLINK_MSG_ID_JY901_DATA_CRC);
#else
    mavlink_jy901_data_t *packet = (mavlink_jy901_data_t *)msgbuf;
    packet->roll = roll;
    packet->yaw = yaw;
    packet->pitch = pitch;
    packet->roll_v = roll_v;
    packet->yaw_v = yaw_v;
    packet->pitch_v = pitch_v;
    packet->x_acc = x_acc;
    packet->y_acc = y_acc;
    packet->z_acc = z_acc;
    packet->x_m = x_m;
    packet->y_m = y_m;
    packet->z_m = z_m;

    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_JY901_DATA, (const char *)packet, MAVLINK_MSG_ID_JY901_DATA_MIN_LEN, MAVLINK_MSG_ID_JY901_DATA_LEN, MAVLINK_MSG_ID_JY901_DATA_CRC);
#endif
}
#endif

#endif

// MESSAGE JY901_DATA UNPACKING


/**
 * @brief Get field roll from jy901_data message
 *
 * @return roll data of the ROV
 */
static inline float mavlink_msg_jy901_data_get_roll(const mavlink_message_t* msg)
{
    return _MAV_RETURN_float(msg,  0);
}

/**
 * @brief Get field yaw from jy901_data message
 *
 * @return yaw data of the ROV
 */
static inline float mavlink_msg_jy901_data_get_yaw(const mavlink_message_t* msg)
{
    return _MAV_RETURN_float(msg,  4);
}

/**
 * @brief Get field pitch from jy901_data message
 *
 * @return pitch data of the ROV
 */
static inline float mavlink_msg_jy901_data_get_pitch(const mavlink_message_t* msg)
{
    return _MAV_RETURN_float(msg,  8);
}

/**
 * @brief Get field roll_v from jy901_data message
 *
 * @return roll velocity of the ROV
 */
static inline float mavlink_msg_jy901_data_get_roll_v(const mavlink_message_t* msg)
{
    return _MAV_RETURN_float(msg,  12);
}

/**
 * @brief Get field yaw_v from jy901_data message
 *
 * @return yaw velocity of the ROV
 */
static inline float mavlink_msg_jy901_data_get_yaw_v(const mavlink_message_t* msg)
{
    return _MAV_RETURN_float(msg,  16);
}

/**
 * @brief Get field pitch_v from jy901_data message
 *
 * @return pitch velocity of the ROV
 */
static inline float mavlink_msg_jy901_data_get_pitch_v(const mavlink_message_t* msg)
{
    return _MAV_RETURN_float(msg,  20);
}

/**
 * @brief Get field x_acc from jy901_data message
 *
 * @return x acceleration of the ROV
 */
static inline float mavlink_msg_jy901_data_get_x_acc(const mavlink_message_t* msg)
{
    return _MAV_RETURN_float(msg,  24);
}

/**
 * @brief Get field y_acc from jy901_data message
 *
 * @return y acceleration of the ROV
 */
static inline float mavlink_msg_jy901_data_get_y_acc(const mavlink_message_t* msg)
{
    return _MAV_RETURN_float(msg,  28);
}

/**
 * @brief Get field z_acc from jy901_data message
 *
 * @return z acceleration of the ROV
 */
static inline float mavlink_msg_jy901_data_get_z_acc(const mavlink_message_t* msg)
{
    return _MAV_RETURN_float(msg,  32);
}

/**
 * @brief Get field x_m from jy901_data message
 *
 * @return x magnetic field of the ROV
 */
static inline float mavlink_msg_jy901_data_get_x_m(const mavlink_message_t* msg)
{
    return _MAV_RETURN_float(msg,  36);
}

/**
 * @brief Get field y_m from jy901_data message
 *
 * @return y magnetic field of the ROV
 */
static inline float mavlink_msg_jy901_data_get_y_m(const mavlink_message_t* msg)
{
    return _MAV_RETURN_float(msg,  40);
}

/**
 * @brief Get field z_m from jy901_data message
 *
 * @return z magnetic field of the ROV
 */
static inline float mavlink_msg_jy901_data_get_z_m(const mavlink_message_t* msg)
{
    return _MAV_RETURN_float(msg,  44);
}

/**
 * @brief Decode a jy901_data message into a struct
 *
 * @param msg The message to decode
 * @param jy901_data C-struct to decode the message contents into
 */
static inline void mavlink_msg_jy901_data_decode(const mavlink_message_t* msg, mavlink_jy901_data_t* jy901_data)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
    jy901_data->roll = mavlink_msg_jy901_data_get_roll(msg);
    jy901_data->yaw = mavlink_msg_jy901_data_get_yaw(msg);
    jy901_data->pitch = mavlink_msg_jy901_data_get_pitch(msg);
    jy901_data->roll_v = mavlink_msg_jy901_data_get_roll_v(msg);
    jy901_data->yaw_v = mavlink_msg_jy901_data_get_yaw_v(msg);
    jy901_data->pitch_v = mavlink_msg_jy901_data_get_pitch_v(msg);
    jy901_data->x_acc = mavlink_msg_jy901_data_get_x_acc(msg);
    jy901_data->y_acc = mavlink_msg_jy901_data_get_y_acc(msg);
    jy901_data->z_acc = mavlink_msg_jy901_data_get_z_acc(msg);
    jy901_data->x_m = mavlink_msg_jy901_data_get_x_m(msg);
    jy901_data->y_m = mavlink_msg_jy901_data_get_y_m(msg);
    jy901_data->z_m = mavlink_msg_jy901_data_get_z_m(msg);
#else
        uint8_t len = msg->len < MAVLINK_MSG_ID_JY901_DATA_LEN? msg->len : MAVLINK_MSG_ID_JY901_DATA_LEN;
        memset(jy901_data, 0, MAVLINK_MSG_ID_JY901_DATA_LEN);
    memcpy(jy901_data, _MAV_PAYLOAD(msg), len);
#endif
}
