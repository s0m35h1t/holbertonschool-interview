#include "search_algos.h"

/**
 * binary_search - Searches for a value in a sorted array
 *
 * @array: A pointer to the first element of the sorted array
 * @beg: the start index of the array.
 * @end: the end index of the array.
 * @value: the value to search for.
 *
 * Return: the index of the value if it exists. otherwise -1.
*/
int binary_search(int *array, int beg, int end, int value)
{
	int mid = (beg + end) / 2;
	int i = beg;

	if (end >= beg)
	{
		if (array[mid] == value && end == beg)
			return (mid);

		printf("Searching in array: ");
		while (i <= end)
		{
			printf("%d", array[i]);
			if (i != end)
				printf(", ");
			else
				printf("\n");
			i += 1;
		}

		if (array[mid] >= value)
			return (binary_search(array, beg, mid, value));
		return (binary_search(array, mid + 1, end, value));
	}
	return (-1);
}

/**
 * advanced_binary - Searches for a value in a sorted array.
 *
 * @array: A ptr to the first element of the sorted array
 * @size: size of the array.
 * @value: the value to search for.
 *
 * Return: the index of the value if it exists. otherwise -1.
*/
int advanced_binary(int *array, size_t size, int value)
{
	if (!array)
		return (-1);

	return (binary_search(array, 0, ((int)size) - 1, value));
}
