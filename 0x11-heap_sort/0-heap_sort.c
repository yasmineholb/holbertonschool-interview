#include <stdio.h>
#include "sort.h"

/**
 * heap_fn - Function that sorts
 * @array: an array
 * @size: the size
 * @it: the position
 * @tot: the total size
 */

void heap_fn(int *array, size_t size, size_t it, size_t tot)
{
size_t mx;
size_t lf;
size_t rgt;
int z;
lf = 2 * it + 1;
rgt = 2 * it + 2;
mx = it;
if (lf < size && array[lf] > array[mx])
mx = lf;
if (rgt < size && array[rgt] > array[mx])
mx = rgt;
if (mx != it)
{
z = array[it];
array[it] = array[mx];
array[mx] = z;
print_array(array, tot);
heap_fn(array, size, mx, tot);
}
}

/**
 * heap_sort - Function that sorts
 * @array: an array
 * @size: the size
 */
void heap_sort(int *array, size_t size)
{
size_t i;
size_t tot = size;
int z;
if (array)
{
for (i = size / 2 - 1; (int)i >= 0; i--)
heap_fn(array, size, i, tot);
for (i = size - 1; i > 0; i--)
{
z = array[0];
array[0] = array[i];
array[i] = z;
print_array(array, size);
heap_fn(array, i, 0, tot);
}
}
}
