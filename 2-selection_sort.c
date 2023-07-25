#include "sort.h"

/**
 * selection_sort - sorts the array of int in order using the
 * Selection sort the algorithm
 * @array: The array in to sort
 * @size: The size of array
 *
 *
 */
void selection_sort(int *array, size_t size)
{
	size_t i, j, m;
	int swp;

	if (array == NULL || size < 2)
		return;

	for (i = 0; i < size - 1; i++)
	{
		m = i;
		for (j = i + 1; j < size; j++)
		{
			if (array[j] < array[m])
				m = j;
		}
		if (i != m)
		{
			swp = array[i];
			array[i] = array[m];
			array[m] = swp;
			print_array(array, size);
		}
	}
}
