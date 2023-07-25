#include "sort.h"

/**
 * swap_ints - to Swap in the integers of array.
 * @a: first integer swap.
 * @b: second integer swap.
 */
void swap_ints(int *a, int *b)
{
	int temp;

	temp = *a;
	*a = *b;
	*b = temp;
}


/**
 * bubble_sort - the sorts in bubbly
 * @array: array for sort
 * @size: the size
 *
 */
void bubble_sort(int *array, size_t size)
{
	size_t i, new_size = size;
	int swap;

	if (array == NULL || size < 2)
		return;

	while (new_size)
	{
		swap = 0;
		for (i = 0; i < (size - 1); i++)
		{
			if (array[i] > array[i + 1])
			{
				swap_ints(&array[i], &array[i + 1]);
				print_array(array, size);
				swap = 1;
			}
		}
		new_size--;
		if (swap == 0)
			break;
	}
}
