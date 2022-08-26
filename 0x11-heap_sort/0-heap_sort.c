#include "sort.h"


/**
 * heapify - recersive sort an array
 * @array: array to sort
 * @size: size of array
 * @i: index of list to check
 * @printsize: the true size of the list to print out
 * Return: void
 */
void heapify(int *array, size_t size, int i, size_t printsize)
{
	int largest = i;
	int left = 2 * i + 1;
	int right = 2 * i + 2;
	int ph;

	if (left < (int)size && array[left] > array[largest])
		largest = left;
	if (right < (int)size && array[right] > array[largest])
		largest = right;
	if (largest != i)
	{
		ph = array[i];
		array[i] = array[largest];
		array[largest] = ph;
		print_array(array, printsize);
		heapify(array, size, largest, printsize);
	}
}

/**
 * heap_sort - sort an array with heap sort order
 * @array: array to sort
 * @size: size of array
 * Return: void
 */
void heap_sort(int *array, size_t size)
{
	int i, ph;

	for (i = (int)size / 2 - 1; i >= 0; i--)
		heapify(array, size, i, size);
	for (i = (int)size - 1; i > 0; i--)
	{
		ph = array[0];
		array[0] = array[i];
		array[i] = ph;
		print_array(array, size);
		heapify(array, (size_t)i, 0, size);
	}
}
