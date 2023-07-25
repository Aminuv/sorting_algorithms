#include "sort.h"

/**
 * swap_int - the swaps two elements in array
 * @a: first element
 * @b: second element
 */

void swp_int(int *a, int *b)
{
	int temp;

	temp = *a;
	*a = *b;
	*b = temp;
}

/**
 * lomuto_partition - partition through an array of integers
 * @array: array of integers
 * @size: the size of the array
 * @l: first index of array
 * @h: last index of array
 *
 * Description: all values must be accurate
 * Return: index position
 */
int lomut_part(int *array, size_t size, int l, int h)
{
	int pvt = array[h], i = l, j;

	for (j = l; j <= h - 1; j++)
	{
		if (array[j] < pvt)
		{
			if (i != j)
			{
				swp_int(&array[i], &array[j]);
				print_array(array, size);
			}
			i++;
		}
	}
	if (pvt != array[i])
	{
		swp_int(&array[i], &array[h]);
		print_array(array, size);
	}
	return (i);
}

/**
 * lomuto_sort - the implement quick sorted algorithm using recursion
 * @array: the array
 * @size: the size of that array
 * @l: first index of that array
 * @h: the last index
 * Return: 0
 */

void lomuto_sorts(int *array, size_t size, int l, int h)
{
	int i;

	if (l < h)
	{
		i = lomut_part(array, size, l, h);
		lomuto_sorts(array, size, l, i - 1);
		lomuto_sorts(array, size, i + 1, h);
	}
}

/**
 * quick_sort - the sort of an array for integers in ascending order
 * @array: the array
 * @size: the size of that array
 * Return: 0
 */

void quick_sort(int *array, size_t size)
{
	if (!array || size < 2)
		return;
	lomuto_sorts(array, size, 0, size - 1);
}
