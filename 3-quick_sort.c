#include "sort.h"

/**
 * quick_sort -  function that sorts an array of integers in ascending
 * order using the Quick sort algorithm
 * @array: pointer to the array
 * @size: the size
 */
void quick_sort(int *array, size_t size)
{
	quicksort(array, 0, size - 1, size);
}

/**
 * quicksort - recursive sort function
 * @array: pointer to the array
 * @size: array size
 * @hi: the hi
 * @lo: the hish limit
 */
void quicksort(int *array, int hi, int lo, size_t size)
{
	int piv;

	if (hi < lo)
	{
		piv = partition(array, hi, lo, size);
		quicksort(array, hi, piv - 1, size);
		quicksort(array, piv + 1, lo, size);
	}
}

/**
 * partition - function tha creates a partition and order the array
 * @array: the array
 * @size: the size
 * @hi: the hi limit
 * @lo: the hish limit
 * Return: return the pivot piv
 */
size_t partition(int *array, int hi, int lo, size_t size)
{
	int piv, i, j, k;

	piv = array[lo];

	i = hi - 1;
	for (j = hi; j < lo; j++)
	{
		if (array[j] <= piv)
		{
			i++;
			if (i != j)
			{
				k = array[i];
				array[i] = array[j];
				array[j] = k;
				print_array(array, size);
			}
		}
	}
	i++;
	if (i != j)
	{
		k = array[i];
		array[i] = array[lo];
		array[lo] = k;
		print_array(array, size);
	}
	return (i);
}
