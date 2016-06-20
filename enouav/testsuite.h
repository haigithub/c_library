/** @file
 *	@brief MAVLink comm protocol testsuite generated from enouav.xml
 *	@see http://qgroundcontrol.org/mavlink/
 */
#ifndef ENOUAV_TESTSUITE_H
#define ENOUAV_TESTSUITE_H

#ifdef __cplusplus
extern "C" {
#endif

#ifndef MAVLINK_TEST_ALL
#define MAVLINK_TEST_ALL
static void mavlink_test_common(uint8_t, uint8_t, mavlink_message_t *last_msg);
static void mavlink_test_enouav(uint8_t, uint8_t, mavlink_message_t *last_msg);

static void mavlink_test_all(uint8_t system_id, uint8_t component_id, mavlink_message_t *last_msg)
{
	mavlink_test_common(system_id, component_id, last_msg);
	mavlink_test_enouav(system_id, component_id, last_msg);
}
#endif

#include "../common/testsuite.h"


static void mavlink_test_pwm_input(uint8_t system_id, uint8_t component_id, mavlink_message_t *last_msg)
{
#ifdef MAVLINK_STATUS_FLAG_OUT_MAVLINK1
	mavlink_status_t *status = mavlink_get_channel_status(MAVLINK_COMM_0);
        if ((status->flags & MAVLINK_STATUS_FLAG_OUT_MAVLINK1) && MAVLINK_MSG_ID_PWM_INPUT >= 256) {
        	return;
        }
#endif
	mavlink_message_t msg;
        uint8_t buffer[MAVLINK_MAX_PACKET_LEN];
        uint16_t i;
	mavlink_pwm_input_t packet_in = {
		93372036854775807ULL,963497880,963498088,963498296
    };
	mavlink_pwm_input_t packet1, packet2;
        memset(&packet1, 0, sizeof(packet1));
        packet1.error_count = packet_in.error_count;
        packet1.time_boot_ms = packet_in.time_boot_ms;
        packet1.pulse_width = packet_in.pulse_width;
        packet1.period = packet_in.period;
        
        
#ifdef MAVLINK_STATUS_FLAG_OUT_MAVLINK1
        if (status->flags & MAVLINK_STATUS_FLAG_OUT_MAVLINK1) {
           // cope with extensions
           memset(MAVLINK_MSG_ID_PWM_INPUT_MIN_LEN + (char *)&packet1, 0, sizeof(packet1)-MAVLINK_MSG_ID_PWM_INPUT_MIN_LEN);
        }
#endif
        memset(&packet2, 0, sizeof(packet2));
	mavlink_msg_pwm_input_encode(system_id, component_id, &msg, &packet1);
	mavlink_msg_pwm_input_decode(&msg, &packet2);
        MAVLINK_ASSERT(memcmp(&packet1, &packet2, sizeof(packet1)) == 0);

        memset(&packet2, 0, sizeof(packet2));
	mavlink_msg_pwm_input_pack(system_id, component_id, &msg , packet1.error_count , packet1.time_boot_ms , packet1.pulse_width , packet1.period );
	mavlink_msg_pwm_input_decode(&msg, &packet2);
        MAVLINK_ASSERT(memcmp(&packet1, &packet2, sizeof(packet1)) == 0);

        memset(&packet2, 0, sizeof(packet2));
	mavlink_msg_pwm_input_pack_chan(system_id, component_id, MAVLINK_COMM_0, &msg , packet1.error_count , packet1.time_boot_ms , packet1.pulse_width , packet1.period );
	mavlink_msg_pwm_input_decode(&msg, &packet2);
        MAVLINK_ASSERT(memcmp(&packet1, &packet2, sizeof(packet1)) == 0);

        memset(&packet2, 0, sizeof(packet2));
        mavlink_msg_to_send_buffer(buffer, &msg);
        for (i=0; i<mavlink_msg_get_send_buffer_length(&msg); i++) {
        	comm_send_ch(MAVLINK_COMM_0, buffer[i]);
        }
	mavlink_msg_pwm_input_decode(last_msg, &packet2);
        MAVLINK_ASSERT(memcmp(&packet1, &packet2, sizeof(packet1)) == 0);
        
        memset(&packet2, 0, sizeof(packet2));
	mavlink_msg_pwm_input_send(MAVLINK_COMM_1 , packet1.error_count , packet1.time_boot_ms , packet1.pulse_width , packet1.period );
	mavlink_msg_pwm_input_decode(last_msg, &packet2);
        MAVLINK_ASSERT(memcmp(&packet1, &packet2, sizeof(packet1)) == 0);
}

static void mavlink_test_enouav(uint8_t system_id, uint8_t component_id, mavlink_message_t *last_msg)
{
	mavlink_test_pwm_input(system_id, component_id, last_msg);
}

#ifdef __cplusplus
}
#endif // __cplusplus
#endif // ENOUAV_TESTSUITE_H
