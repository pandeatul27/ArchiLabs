#include <stdio.h>

int LIST[8] = {7, 4, 5, 3, 6, 1, 8, 2};	// number of elements, element 1, element 2, ...
int main(void)
{
	int n, largest, i;

	n = LIST[0];
	largest = LIST[1];
	for (i = 2; i <= n; i++)
	{
		if (LIST[i] > largest)
			largest = LIST[i];
	}
	printf ("Largest number is: %d \n", largest);
}
