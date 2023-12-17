#include "sort.h"
/**
 * shell_sort - Function for shell sort knuth sequence
 * @array: array to sort
 * @size: size of the array
 */
void shell_sort(int *array, size_t size)
{
	size_t gap = 1;
	size_t i, j;

	if (array == NULL || size < 2)
		return;

	while (gap <= size / 3)
		gap = gap * 3 + 1;

	while (gap >= 1)
	{
		for (i = 0; i < gap; i++)
		{
			for (j = i; j < size - gap; j += gap)
			{
				while (array[j] > array[j + gap])
				{
					swap(&array[j], &array[j + gap]);
					if (j >= gap)
						j = j -	gap;
					else
						break;
				}
			}
		}
		gap = (gap - 1) / 3;
		print_array(array, size);
	}
}
/**
 * swap - function that swaps integers
 * @a: first integer
 * @b: second integer
 */

void swap(int *a, int *b)
{
	int tmp = *a;
	*a = *b;
	*b = tmp;
}