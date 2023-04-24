#include "sort.h"

/**
 * selection_sort - sorts an array of integers in
 * ascending order using the Selection sort algorithm
 *
 * @array: the array
 * @size: num of array elements
 */
void selection_sort(int *array, size_t size)
{
	size_t i, j, min;

	for (i = 0; i < size - 1; i++)
	{
		min = i;
		for (j = i + 1; j < size; j++)
		{
			if (array[j] < array[min])
			{
				min = j;
			}
		}

		if (min != i)
		{
			int temp = array[i];

			array[i] = array[min];

			array[min] = temp;

			print_array(array, size);
		}
	}
}
