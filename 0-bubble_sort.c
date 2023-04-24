#include "sort.h"

/**
 * bubble_sort - sorts an array of integers in ascending
 * order using the Bubble sort algorithm
 *
 * @array: the array
 * @size: num of array elements
 */
void bubble_sort(int *array, size_t size)
{
	size_t i, j;
	int temp;
	int swap;

	if (!array || size < 2)
		return;

	for (i = 0; i < size - 1; i++)
	{
		swap = 0;

		for (j = 0; j < size - 1 - i; j++)
		{
			if (array[j] > array[j + 1])
			{
				temp = array[j];
				array[j] = array[j + 1];
				array[j + 1] = temp;

				swap = 1;
				print_array(array, size);
			}
		}

		if (!swap)
			break;
	}
}
