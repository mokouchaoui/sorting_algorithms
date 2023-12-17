#include "sort.h"

/**
 * shell_sort - uses knuths sequence to sort array
 * @array: ref to array
 * @size: size of array
 * Return: nothing
 */

void shell_sort(int *array, size_t size)
{
	size_t in;
	size_t out;
	int val;
	size_t  interval;
	int i = 0;

	while (interval <= size / 3)
		interval = interval * 3 + 1;

	while (interval > 0)
	{

		for (out = interval; out < size; out++)
		{
			val = array[out];
			in = out;

			while (in > interval - 1 && array[in - interval] >= val)
			{
				array[in] = array[in - interval];
				in -= interval;
			}
			array[in] = val;

		}
		interval = (interval - 1) / 3;
		i++;
	}
	print_array(array, size);
}