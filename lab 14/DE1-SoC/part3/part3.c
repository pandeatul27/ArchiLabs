#include "../address_map_arm.h"

int ONES(int), ZEROS(int), ALTERNATE(int);

int TEST_NUM[ ] = {0x0000e000, 0x3fabedef, 0x00000001, 0x00000002, 0x75a5a5a5,
                   0x01ffC000, 0x03ffC000, 0x55555555, 0x77777777, 0x08888888,
						 0x00000000};
char seg7[10] =	{0b00111111, 0b00000110, 0b01011011, 0b01001111, 0b01100110, 
						 0b01101101, 0b01111101, 0b00000111, 0b01111111, 0b01100111};

int main(void)
{
	int data, long_1s = 0, long_0s = 0, long_alt = 0, ret_val, i;
	volatile int * HEX3_HEX0_ptr = (int *) HEX3_HEX0_BASE;
	volatile int * HEX5_HEX4_ptr = (int *) HEX5_HEX4_BASE;

	data = TEST_NUM[0];
	for (i = 1; data != 0; i++)
	{
		ret_val = ONES(data);
		if (ret_val > long_1s)
			long_1s = ret_val;
		ret_val = ZEROS(data);
		if (ret_val > long_0s)
			long_0s = ret_val;
		ret_val = ALTERNATE(data);
		if (ret_val > long_alt)
			long_alt = ret_val;
		data = TEST_NUM[i];
	}
	/* display count of number of 1's */
	for (i = 0; long_1s > 9; i++)
		long_1s -= 10;
	*HEX3_HEX0_ptr = seg7[i] << 8;
	*HEX3_HEX0_ptr |= seg7[long_1s];

	/* display count of number of 0's */
	for (i = 0; long_0s > 9; i++)
		long_0s -= 10;
	*HEX3_HEX0_ptr |= seg7[i] << 24;
	*HEX3_HEX0_ptr |= seg7[long_0s] << 16;

	/* display count of number of alternating 1's and 0's */
	for (i = 0; long_alt > 9; i++)
		long_alt -= 10;
	*HEX5_HEX4_ptr = seg7[i] << 8;
	*HEX5_HEX4_ptr |= seg7[long_alt];
}

int ONES(int data)
{
	int i, shift;

	for (i = 0; data != 0; i++)
	{
		shift = (data >> 1) & 0x7FFFFFFF;	// shift right logical
		data = data & shift;
	}
	return (i);
}
int ZEROS(int data)
{
	return (ONES (data ^ 0xFFFFFFFF));
}
int ALTERNATE(int data)
{
	int ret_val1, ret_val0;
	
	data = data ^ 0x55555555;
	ret_val1 = ONES (data);
	ret_val0 = ZEROS (data);

	return (ret_val1 > ret_val0 ? ret_val1 : ret_val0);
}
