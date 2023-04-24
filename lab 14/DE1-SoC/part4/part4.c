#include "../address_map_arm.h"

/* program that displays a real-time clock on the 7-seg displays. The time is displayed
 * as MM SS DD, where MM is minutes, SS is seconds, and DD is hundredths of a second.
 * The clock can be stopped/started by any pressing pushbutton KEY.
 */

char seg7[10] =	{0b00111111, 0b00000110, 0b01011011, 0b01001111, 0b01100110, 
						 0b01101101, 0b01111101, 0b00000111, 0b01111111, 0b01100111};

int main(void)
{
	int i, time, min, sec, tmp, flag, edge_capture, status;
	volatile int * A9_priv_timer_ptr = (int *) MPCORE_PRIV_TIMER;
	volatile int * HEX3_HEX0_ptr = (int *) HEX3_HEX0_BASE;
	volatile int * HEX5_HEX4_ptr = (int *) HEX5_HEX4_BASE;
	volatile int * KEYS_ptr = (int *) KEY_BASE;

	*A9_priv_timer_ptr =   2000000;				// timeout = 1/(200 MHz) x 2x10^6 = 0.01 sec
	*(A9_priv_timer_ptr+2) = 0b011;				// set bits: mode = 1 (auto), enable = 1
	*HEX3_HEX0_ptr = 0;								// clear the display
	*HEX5_HEX4_ptr = 0;								// clear the display

	time = 0;											// start time at 00:00:00
	flag = 0;											// clear flag for KEY pressed
	while (1)
	{
		edge_capture = *(KEYS_ptr+3);				// read the KEYs edge capture register
		if (edge_capture)
		{
			*(KEYS_ptr+3) = edge_capture;			// clear edge capture register
			flag ^= 1;									// toggle flag for stopping
		}
		/* display the time */
		tmp = time;
		min = tmp / 6000;
		*HEX5_HEX4_ptr = seg7[min/10] << 8;
		*HEX5_HEX4_ptr |= seg7[min%10];

		tmp = tmp % 6000;
		sec = tmp / 100;
		*HEX3_HEX0_ptr = seg7[sec/10] << 24;
		*HEX3_HEX0_ptr |= seg7[sec%10] << 16;

		tmp = tmp % 100;
		*HEX3_HEX0_ptr |= seg7[tmp/10] << 8;
		*HEX3_HEX0_ptr |= seg7[tmp%10];

		if (!flag)
			++time;
		if (time == 360000) time = 0;

		/* wait for timer */
		do
			status = *(A9_priv_timer_ptr+3);	// read timer status
		while (status == 0);
		*(A9_priv_timer_ptr+3) = status;		// reset timer flag bit
	}
}
