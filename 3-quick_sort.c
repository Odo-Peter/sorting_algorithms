#include "sort.h"

/**
 * swap_values - change position between values of an array
 * and prints out the array
 * @array: array to be sorted
 * @first_val: initial low bound position
 * @last_val: next high bound position
 * @size: size of array
 */

void swap_values(int *array, int first_val, int last_val, size_t size)
{
	int aux, value;

	value = array[first_val];
	aux = array[last_val];
	array[last_val] = value;
	array[first_val] = aux;
	print_array(array, size);
}


/**
 * array_partition - Locates the partition position of the array
 * @array: array to be sorted
 * @first_val: low bound position
 * @last_val: high bound position
 * @size: size of array
 * Return: partitioned point index
 */

int array_partition(int *array, int first_val, int last_val, size_t size)
{
	int partition = array[last_val];
	int i = first_val - 1;
	int j;

	for (j = first_val; j <= last_val - 1; j++)
	{
		if (array[j] < partition)
		{
			i++;
			if (i < j)
				swap_values(array, i, j, size);
		}
	}
	if (array[i + 1] > array[last_val])
		swap_values(array, i + 1, last_val, size);
	return (i + 1);
}

/**
 * sorting - sorts an array in ascending order
 * @array: array to sort
 * @first: lowest position
 * @last: highest position
 * @size: size of array
 */
void sorting(int *array, int first, int last, size_t size)
{
	int pivot;

	if (first < last)
	{
		pivot = array_partition(array, first, last, size);
		sorting(array, first, pivot - 1, size);
		sorting(array, pivot + 1, last, size);
	}
}

/**
 * quick_sort - sorts an array of integers in ascending order
 * @array: array to sort
 * @size: size of array
 */

void quick_sort(int *array, size_t size)
{
	int last = size - 1;

	sorting(array, 0, last, size);
}
