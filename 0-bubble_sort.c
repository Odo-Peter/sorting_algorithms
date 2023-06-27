#include "sort.h"
/**
 * bubble_sort - fsorts an array using bubble sorting
 * @array: array to sort
 * @size: size of the array
 * Return: a void function
 * Nothing is returned
 */

void bubble_sort(int *array, size_t size)
{
	int contd = 1, aux = 0;
	size_t i, j;

	for (j = 0; j < size; j++)
	{
		contd = 0;
		for (i = 0; i < size - 1; i++)
		{
			if (array[i] > array[i + 1])
			{
				contd++;
				aux = array[i];
				array[i] = array[i + 1];
				array[i + 1] = aux;
				print_array(array, size);
			}
		}
		if (contd == 0)
			break;
	}
}
