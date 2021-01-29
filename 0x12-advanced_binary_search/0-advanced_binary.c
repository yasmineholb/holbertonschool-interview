#include "search_algos.h"

/**
 * binary_search - binrary search function
 * @array: array to search in
 * @frst: first position
 * @lst: last position
 * @val: value
 * Return: index of number, -1 if not found
 */
int binary_search(int *array, int frst, int lst, int val)
{
int mid, i;
printf("Searching in array: ");
for (i = frst; i < lst; i++)
printf("%i, ", array[i]);
printf("%i\n", array[i]);
mid = ((lst - frst) / 2) + frst;
if (array[mid] == val && array[mid - 1] != val)
{
return (mid);
}
if (frst == lst)
{
return (-1);
}
if (array[mid] >= val)
{
return (binary_search(array, frst, mid, val));
}
if (array[mid] < val)
{
return (binary_search(array, mid + 1, lst, val));
}
return (-1);
}


/**
 * advanced_binary - adv binary function
 * @array: the array
 * @size: the size of array
 * @value: the value
 * Return: index of number or -1 if not found
 */
int advanced_binary(int *array, size_t size, int value)
{
int siz = size;
if (array == NULL)
return (-1);
return (binary_search(array, 0, siz - 1, value));
}
