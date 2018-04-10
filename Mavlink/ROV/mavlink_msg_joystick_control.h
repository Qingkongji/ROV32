#pragma once
// MESSAGE JOYSTICK_CONTROL PACKING

#define MAVLINK_MSG_ID_JOYSTICK_CONTROL 150

MAVPACKED(
typedef struct __mavlink_joystick_control_t {
 int16_t x_acc; /*< The x control signal from joystic.*/
 int16_t y_acc; /*< The y control signal from joystic.*/
 int16_t z_acc; /*< The z control signal from joystic.*/
 int16_t yaw_acc; /*< The yaw control signal from joystic.*/
 uint8_t lights_up; /*< The light turn up signal from joystick>.*/
 uint8_t lights_down; /*< The light turn down signal from joystick>.*/
}) mavlink_joystick_control_t;

#define MAVLINK_MSG_ID_JOYSTICK_CONTROL_LEN 10
#define MAVLINK_MSG_ID_JOYSTICK_CONTROL_MIN_LEN 10
#define MAVLINK_MSG_ID_150_LEN 10
#define MAVLINK_MSG_ID_150_MIN_LEN 10

#define MAVLINK_MSG_ID_JOYSTICK_CONTROL_CRC 24
#define MAVLINK_MSG_ID_150_CRC 24



#if MAVLINK_COMMAND_24BIT
#define MAVLINK_MESSAGE_INFO_JOYSTICK_CONTROL { \
    150, \
    "JOYSTICK_CONTROL", \
    6, \
    {  { "x_acc", NULL, MAVLINK_TYPE_INT16_T, 0, 0, offsetof(mavlink_joystick_control_t, x_acc) }, \
         { "y_acc", NULL, MAVLINK_TYPE_INT16_T, 0, 2, offsetof(mavlink_joystick_control_t, y_acc) }, \
         { "z_acc", NULL, MAVLINK_TYPE_INT16_T, 0, 4, offsetof(mavlink_joystick_control_t, z_acc) }, \
         { "yaw_acc", NULL, MAVLINK_TYPE_INT16_T, 0, 6, offsetof(mavlink_joystick_control_t, yaw_acc) }, \
         { "lights_up", NULL, MAVLINK_TYPE_UINT8_T, 0, 8, offsetof(mavlink_joystick_control_t, lights_up) }, \
         { "lights_down", NULL, MAVLINK_TYPE_UINT8_T, 0, 9, offsetof(mavlink_joystick_control_t, lights_down) }, \
         } \
}
#else
#define MAVLINK_MESSAGE_INFO_JOYSTICK_CONTROL { \
    "JOYSTICK_CONTROL", \
    6, \
    {  { "x_acc", NULL, MAVLINK_TYPE_INT16_T, 0, 0, offsetof(mavlink_joystick_control_t, x_acc) }, \
         { "y_acc", NULL, MAVLINK_TYPE_INT16_T, 0, 2, offsetof(mavlink_joystick_control_t, y_acc) }, \
         { "z_acc", NULL, MAVLINK_TYPE_INT16_T, 0, 4, offsetof(mavlink_joystick_control_t, z_acc) }, \
         { "yaw_acc", NULL, MAVLINK_TYPE_INT16_T, 0, 6, offsetof(mavlink_joystick_control_t, yaw_acc) }, \
         { "lights_up", NULL, MAVLINK_TYPE_UINT8_T, 0, 8, offsetof(mavlink_joystick_control_t, lights_up) }, \
         { "lights_down", NULL, MAVLINK_TYPE_UINT8_T, 0, 9, offsetof(mavlink_joystick_control_t, lights_down) }, \
         } \
}
#endif

/**
 * @brief Pack a joystick_control message
 * @param system_id ID of this system
 * @param component_id ID of this component (e.g. 200 for IMU)
 * @param msg The MAVLink message to compress the data into
 *
 * @param x_acc The x control signal from joystic.
 * @param y_acc The y control signal from joystic.
 * @param z_acc The z control signal from joystic.
 * @param yaw_acc The yaw control signal from joystic.
 * @param lights_up The light turn up signal from joystick>.
 * @param lights_down The light turn down signal from joystick>.
 * @return length of the message in bytes (excluding serial stream start sign)
 */
static inline uint16_t mavlink_msg_joystick_control_pack(uint8_t system_id, uint8_t component_id, mavlink_message_t* msg,
                               int16_t x_acc, int16_t y_acc, int16_t z_acc, int16_t yaw_acc, uint8_t lights_up, uint8_t lights_down)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
    char buf[MAVLINK_MSG_ID_JOYSTICK_CONTROL_LEN];
    _mav_put_int16_t(buf, 0, x_acc);
    _mav_put_int16_t(buf, 2, y_acc);
    _mav_put_int16_t(buf, 4, z_acc);
    _mav_put_int16_t(buf, 6, yaw_acc);
    _mav_put_uint8_t(buf, 8, lights_up);
    _mav_put_uint8_t(buf, 9, lights_down);

        memcpy(_MAV_PAYLOAD_NON_CONST(msg), buf, MAVLINK_MSG_ID_JOYSTICK_CONTROL_LEN);
#else
    mavlink_joystick_control_t packet;
    packet.x_acc = x_acc;
    packet.y_acc = y_acc;
    packet.z_acc = z_acc;
    packet.yaw_acc = yaw_acc;
    packet.lights_up = lights_up;
    packet.lights_down = lights_down;

        memcpy(_MAV_PAYLOAD_NON_CONST(msg), &packet, MAVLINK_MSG_ID_JOYSTICK_CONTROL_LEN);
#endif

    msg->msgid = MAVLINK_MSG_ID_JOYSTICK_CONTROL;
    return mavlink_finalize_message(msg, system_id, component_id, MAVLINK_MSG_ID_JOYSTICK_CONTROL_MIN_LEN, MAVLINK_MSG_ID_JOYSTICK_CONTROL_LEN, MAVLINK_MSG_ID_JOYSTICK_CONTROL_CRC);
}

/**
 * @brief Pack a joystick_control message on a channel
 * @param system_id ID of this system
 * @param component_id ID of this component (e.g. 200 for IMU)
 * @param chan The MAVLink channel this message will be sent over
 * @param msg The MAVLink message to compress the data into
 * @param x_acc The x control signal from joystic.
 * @param y_acc The y control signal from joystic.
 * @param z_acc The z control signal from joystic.
 * @param yaw_acc The yaw control signal from joystic.
 * @param lights_up The light turn up signal from joystick>.
 * @param lights_down The light turn down signal from joystick>.
 * @return length of the message in bytes (excluding serial stream start sign)
 */
static inline uint16_t mavlink_msg_joystick_control_pack_chan(uint8_t system_id, uint8_t component_id, uint8_t chan,
                               mavlink_message_t* msg,
                                   int16_t x_acc,int16_t y_acc,int16_t z_acc,int16_t yaw_acc,uint8_t lights_up,uint8_t lights_down)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
    char buf[MAVLINK_MSG_ID_JOYSTICK_CONTROL_LEN];
    _mav_put_int16_t(buf, 0, x_acc);
    _mav_put_int16_t(buf, 2, y_acc);
    _mav_put_int16_t(buf, 4, z_acc);
    _mav_put_int16_t(buf, 6, yaw_acc);
    _mav_put_uint8_t(buf, 8, lights_up);
    _mav_put_uint8_t(buf, 9, lights_down);

        memcpy(_MAV_PAYLOAD_NON_CONST(msg), buf, MAVLINK_MSG_ID_JOYSTICK_CONTROL_LEN);
#else
    mavlink_joystick_control_t packet;
    packet.x_acc = x_acc;
    packet.y_acc = y_acc;
    packet.z_acc = z_acc;
    packet.yaw_acc = yaw_acc;
    packet.lights_up = lights_up;
    packet.lights_down = lights_down;

        memcpy(_MAV_PAYLOAD_NON_CONST(msg), &packet, MAVLINK_MSG_ID_JOYSTICK_CONTROL_LEN);
#endif

    msg->msgid = MAVLINK_MSG_ID_JOYSTICK_CONTROL;
    return mavlink_finalize_message_chan(msg, system_id, component_id, chan, MAVLINK_MSG_ID_JOYSTICK_CONTROL_MIN_LEN, MAVLINK_MSG_ID_JOYSTICK_CONTROL_LEN, MAVLINK_MSG_ID_JOYSTICK_CONTROL_CRC);
}

/**
 * @brief Encode a joystick_control struct
 *
 * @param system_id ID of this system
 * @param component_id ID of this component (e.g. 200 for IMU)
 * @param msg The MAVLink message to compress the data into
 * @param joystick_control C-struct to read the message contents from
 */
static inline uint16_t mavlink_msg_joystick_control_encode(uint8_t system_id, uint8_t component_id, mavlink_message_t* msg, const mavlink_joystick_control_t* joystick_control)
{
    return mavlink_msg_joystick_control_pack(system_id, component_id, msg, joystick_control->x_acc, joystick_control->y_acc, joystick_control->z_acc, joystick_control->yaw_acc, joystick_control->lights_up, joystick_control->lights_down);
}

/**
 * @brief Encode a joystick_control struct on a channel
 *
 * @param system_id ID of this system
 * @param component_id ID of this component (e.g. 200 for IMU)
 * @param chan The MAVLink channel this message will be sent over
 * @param msg The MAVLink message to compress the data into
 * @param joystick_control C-struct to read the message contents from
 */
static inline uint16_t mavlink_msg_joystick_control_encode_chan(uint8_t system_id, uint8_t component_id, uint8_t chan, mavlink_message_t* msg, const mavlink_joystick_control_t* joystick_control)
{
    return mavlink_msg_joystick_control_pack_chan(system_id, component_id, chan, msg, joystick_control->x_acc, joystick_control->y_acc, joystick_control->z_acc, joystick_control->yaw_acc, joystick_control->lights_up, joystick_control->lights_down);
}

/**
 * @brief Send a joystick_control message
 * @param chan MAVLink channel to send the message
 *
 * @param x_acc The x control signal from joystic.
 * @param y_acc The y control signal from joystic.
 * @param z_acc The z control signal from joystic.
 * @param yaw_acc The yaw control signal from joystic.
 * @param lights_up The light turn up signal from joystick>.
 * @param lights_down The light turn down signal from joystick>.
 */
#ifdef MAVLINK_USE_CONVENIENCE_FUNCTIONS

static inline void mavlink_msg_joystick_control_send(mavlink_channel_t chan, int16_t x_acc, int16_t y_acc, int16_t z_acc, int16_t yaw_acc, uint8_t lights_up, uint8_t lights_down)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
    char buf[MAVLINK_MSG_ID_JOYSTICK_CONTROL_LEN];
    _mav_put_int16_t(buf, 0, x_acc);
    _mav_put_int16_t(buf, 2, y_acc);
    _mav_put_int16_t(buf, 4, z_acc);
    _mav_put_int16_t(buf, 6, yaw_acc);
    _mav_put_uint8_t(buf, 8, lights_up);
    _mav_put_uint8_t(buf, 9, lights_down);

    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_JOYSTICK_CONTROL, buf, MAVLINK_MSG_ID_JOYSTICK_CONTROL_MIN_LEN, MAVLINK_MSG_ID_JOYSTICK_CONTROL_LEN, MAVLINK_MSG_ID_JOYSTICK_CONTROL_CRC);
#else
    mavlink_joystick_control_t packet;
    packet.x_acc = x_acc;
    packet.y_acc = y_acc;
    packet.z_acc = z_acc;
    packet.yaw_acc = yaw_acc;
    packet.lights_up = lights_up;
    packet.lights_down = lights_down;

    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_JOYSTICK_CONTROL, (const char *)&packet, MAVLINK_MSG_ID_JOYSTICK_CONTROL_MIN_LEN, MAVLINK_MSG_ID_JOYSTICK_CONTROL_LEN, MAVLINK_MSG_ID_JOYSTICK_CONTROL_CRC);
#endif
}

/**
 * @brief Send a joystick_control message
 * @param chan MAVLink channel to send the message
 * @param struct The MAVLink struct to serialize
 */
static inline void mavlink_msg_joystick_control_send_struct(mavlink_channel_t chan, const mavlink_joystick_control_t* joystick_control)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
    mavlink_msg_joystick_control_send(chan, joystick_control->x_acc, joystick_control->y_acc, joystick_control->z_acc, joystick_control->yaw_acc, joystick_control->lights_up, joystick_control->lights_down);
#else
    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_JOYSTICK_CONTROL, (const char *)joystick_control, MAVLINK_MSG_ID_JOYSTICK_CONTROL_MIN_LEN, MAVLINK_MSG_ID_JOYSTICK_CONTROL_LEN, MAVLINK_MSG_ID_JOYSTICK_CONTROL_CRC);
#endif
}

#if MAVLINK_MSG_ID_JOYSTICK_CONTROL_LEN <= MAVLINK_MAX_PAYLOAD_LEN
/*
  This varient of _send() can be used to save stack space by re-using
  memory from the receive buffer.  The caller provides a
  mavlink_message_t which is the size of a full mavlink message. This
  is usually the receive buffer for the channel, and allows a reply to an
  incoming message with minimum stack space usage.
 */
static inline void mavlink_msg_joystick_control_send_buf(mavlink_message_t *msgbuf, mavlink_channel_t chan,  int16_t x_acc, int16_t y_acc, int16_t z_acc, int16_t yaw_acc, uint8_t lights_up, uint8_t lights_down)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
    char *buf = (char *)msgbuf;
    _mav_put_int16_t(buf, 0, x_acc);
    _mav_put_int16_t(buf, 2, y_acc);
    _mav_put_int16_t(buf, 4, z_acc);
    _mav_put_int16_t(buf, 6, yaw_acc);
    _mav_put_uint8_t(buf, 8, lights_up);
    _mav_put_uint8_t(buf, 9, lights_down);

    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_JOYSTICK_CONTROL, buf, MAVLINK_MSG_ID_JOYSTICK_CONTROL_MIN_LEN, MAVLINK_MSG_ID_JOYSTICK_CONTROL_LEN, MAVLINK_MSG_ID_JOYSTICK_CONTROL_CRC);
#else
    mavlink_joystick_control_t *packet = (mavlink_joystick_control_t *)msgbuf;
    packet->x_acc = x_acc;
    packet->y_acc = y_acc;
    packet->z_acc = z_acc;
    packet->yaw_acc = yaw_acc;
    packet->lights_up = lights_up;
    packet->lights_down = lights_down;

    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_JOYSTICK_CONTROL, (const char *)packet, MAVLINK_MSG_ID_JOYSTICK_CONTROL_MIN_LEN, MAVLINK_MSG_ID_JOYSTICK_CONTROL_LEN, MAVLINK_MSG_ID_JOYSTICK_CONTROL_CRC);
#endif
}
#endif

#endif

// MESSAGE JOYSTICK_CONTROL UNPACKING


/**
 * @brief Get field x_acc from joystick_control message
 *
 * @return The x control signal from joystic.
 */
static inline int16_t mavlink_msg_joystick_control_get_x_acc(const mavlink_message_t* msg)
{
    return _MAV_RETURN_int16_t(msg,  0);
}

/**
 * @brief Get field y_acc from joystick_control message
 *
 * @return The y control signal from joystic.
 */
static inline int16_t mavlink_msg_joystick_control_get_y_acc(const mavlink_message_t* msg)
{
    return _MAV_RETURN_int16_t(msg,  2);
}

/**
 * @brief Get field z_acc from joystick_control message
 *
 * @return The z control signal from joystic.
 */
static inline int16_t mavlink_msg_joystick_control_get_z_acc(const mavlink_message_t* msg)
{
    return _MAV_RETURN_int16_t(msg,  4);
}

/**
 * @brief Get field yaw_acc from joystick_control message
 *
 * @return The yaw control signal from joystic.
 */
static inline int16_t mavlink_msg_joystick_control_get_yaw_acc(const mavlink_message_t* msg)
{
    return _MAV_RETURN_int16_t(msg,  6);
}

/**
 * @brief Get field lights_up from joystick_control message
 *
 * @return The light turn up signal from joystick>.
 */
static inline uint8_t mavlink_msg_joystick_control_get_lights_up(const mavlink_message_t* msg)
{
    return _MAV_RETURN_uint8_t(msg,  8);
}

/**
 * @brief Get field lights_down from joystick_control message
 *
 * @return The light turn down signal from joystick>.
 */
static inline uint8_t mavlink_msg_joystick_control_get_lights_down(const mavlink_message_t* msg)
{
    return _MAV_RETURN_uint8_t(msg,  9);
}

/**
 * @brief Decode a joystick_control message into a struct
 *
 * @param msg The message to decode
 * @param joystick_control C-struct to decode the message contents into
 */
static inline void mavlink_msg_joystick_control_decode(const mavlink_message_t* msg, mavlink_joystick_control_t* joystick_control)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
    joystick_control->x_acc = mavlink_msg_joystick_control_get_x_acc(msg);
    joystick_control->y_acc = mavlink_msg_joystick_control_get_y_acc(msg);
    joystick_control->z_acc = mavlink_msg_joystick_control_get_z_acc(msg);
    joystick_control->yaw_acc = mavlink_msg_joystick_control_get_yaw_acc(msg);
    joystick_control->lights_up = mavlink_msg_joystick_control_get_lights_up(msg);
    joystick_control->lights_down = mavlink_msg_joystick_control_get_lights_down(msg);
#else
        uint8_t len = msg->len < MAVLINK_MSG_ID_JOYSTICK_CONTROL_LEN? msg->len : MAVLINK_MSG_ID_JOYSTICK_CONTROL_LEN;
        memset(joystick_control, 0, MAVLINK_MSG_ID_JOYSTICK_CONTROL_LEN);
    memcpy(joystick_control, _MAV_PAYLOAD(msg), len);
#endif
}
