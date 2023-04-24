#define LEDR_BASE 0xFF200000

int LIST[8] = {7, 4, 5, 3, 6, 1, 15, 2};	// number of elements, element 1, element 2, ...

int main(void)
{
	int n, largest, i;
	volatile int * LEDR_ptr = (int *) LEDR_BASE;

	n = LIST[0];
	largest = LIST[1];
	for (i = 2; i <= n; i++)
	{
		if (LIST[i] > largest)
			largest = LIST[i];
	}
	*LEDR_ptr = largest;
}
