#include "../address_map_arm.h"

/* Program that scrolls the message dE1-SoC across the 7-segment displays.  Scrolling can
 * be stopped/started by pressing any pushbutton KEY.
 */

char seg7[] =	{0b01011100, 0b00000110, 0b01000000, 0b00000000, 0b00000000, 
					 0b01101101, 0b00000000, 0b00000000, 0b00000000, 0b00000000,
					 0b00000000, 0b00000000, 0b00111001, 0b01011110, 0b01111001};
/* below, 0xD is used for d, 5 for S, 0 for o, 0xB for blank, and 2 for - */
int message[] = {0xD, 0xE, 1, 2, 5, 0, 0xC, 0xB, 0xB, 0xB, 0xB, 0xB, 0xB, 0xD, 0xE, 1, 2, 5};

int main(void)
{
	int flag, edge_capture, status;
	int *pmessage;
	volatile int * A9_priv_timer_ptr = (int *) MPCORE_PRIV_TIMER;
	volatile int * HEX3_HEX0_ptr = (int *) HEX3_HEX0_BASE;
	volatile int * HEX5_HEX4_ptr = (int *) HEX5_HEX4_BASE;
	volatile int * KEYS_ptr = (int *) KEY_BASE;

	*A9_priv_timer_ptr =   40000000;				// timeout = 1/(200 MHz) x 40x10^6 = 0.2 sec
	*(A9_priv_timer_ptr+2) = 0b011;				// set bits: mode = 1 (auto), enable = 1
	*HEX3_HEX0_ptr = 0;								// clear the display
	*HEX5_HEX4_ptr = 0;								// clear the display

	pmessage = message;								// point to start of message
	flag = 0;											// clear flag for KEY pressed
	while (1)						
	{
		edge_capture = *(KEYS_ptr+3);				// read the KEYs edge capture register
		if (edge_capture)
		{
			*(KEYS_ptr+3) = edge_capture;			// clear edge capture register
			flag ^= 1;									// toggle flag for stopping
		}
		/* display scrolling message */
		*HEX5_HEX4_ptr =  seg7[*pmessage] << 8;
		*HEX5_HEX4_ptr |= seg7[*(pmessage+1)];
		*HEX3_HEX0_ptr =  seg7[*(pmessage+2)] << 24;
		*HEX3_HEX0_ptr |= seg7[*(pmessage+3)] << 16;
		*HEX3_HEX0_ptr |= seg7[*(pmessage+4)] << 8;
		*HEX3_HEX0_ptr |= seg7[*(pmessage+5)];

		if (!flag)
		{
			if (pmessage == message + 12)			// check when message has "wrapped around"
				pmessage = message;
			else
				++pmessage;
		}
		/* wait for timer */
		do
			status = *(A9_priv_timer_ptr+3);	// read timer status
		while (status == 0);
		*(A9_priv_timer_ptr+3) = status;		// reset timer flag bit
	}
}
