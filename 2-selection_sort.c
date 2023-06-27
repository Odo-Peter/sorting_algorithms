#include "sort.h"
/**
 * selection_sort - Algorithm that sorts in selection form
 * @array: array to sort
 * @size: size of array
 * Return: Nothing
 */

void selection_sort(int *array, size_t size)
{
	size_t j, contd = 0, position;
	int aux, flag = 0, val;

	while (contd < size)
	{
		position = contd;
		val = array[contd];
		for (j = contd; j < size; j++)
		{
			if (val > array[j])
			{
				flag = 1;
				val = array[j];
				position = j;
			}
		}
		if (flag == 1)
		{
			aux = array[contd];
			array[contd] = val;
			array[position] = aux;
			print_array(array, size);
		}
		contd++;
		flag = 0;
	}
}
