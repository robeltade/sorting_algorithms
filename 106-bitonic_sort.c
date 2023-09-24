#include "sort.h"

/**
* bitonic_sort - Implements bitonic sort
* @array: pointer
* @size: zu size of array
*/

void bitonic_sort(int *array, size_t size)
{
	/* guard */
	if (array == NULL || size < 2)
	{
		return;
	}
	dohalf(array, 1, size, size);
}

/**
* dohalf - Split array
* @array: pointer
* @flag: int 0 or 1
* @size: zu
* @initsize: full size of array
*/

void dohalf(int *array, int flag, size_t size, size_t initsize)
{
	size_t half = (size / 2);

	if (size < 2)
	{
		return;
	}

	/* Merging operation up or down according to flag */
	printf("Merging [%lu/%lu] (%s):\n", size, initsize,
		(flag == 1) ? "UP" : "DOWN");
	print_array(array, size);
	/* recursion up */
	dohalf(array, 1, half, initsize);
	/* recusrsion down */
	dohalf((array + half), 0, half, initsize);
	/* join in recursion */
	merge(array, flag, size);
	/* show result */
	printf("Result [%lu/%lu] (%s):\n", size, initsize,
		(flag == 1) ? "UP" : "DOWN");
	print_array(array, size);
}

/**
* merge - do the merge
* @array: pointer
* @flag: set up or down
* @size: array max
*/

void merge(int *array, int flag, size_t size)
{
	size_t i, gap;
	int aux;

	/* split again */
	size_t half = size / 2;

	if (size < 2)
	{
		return;
	}

	gap = size / 2;

	for (i = 0; i < gap; i++)
	{
		if ((array[i] > array[i + gap]) == flag)
		{
			/* do the swap */
			aux = array[i];
			array[i] = array[i + gap];
			array[i + gap] = aux;
		}
	}

	/* recursion merge */
	merge(array, flag, half);
	merge((array + half), flag, half);
}
