#include "search.h"
#include <stdio.h>
/**
 * find - searches in the linked list to find the value
 * @pv: previous pointer
 * @act: actual pointer
 * @value: value to search
 * Return: the node
 */
skiplist_t *find(skiplist_t *pv, skiplist_t *act, int value)
{
while (pv && pv->index <= act->index)
{
printf("Value checked at index [%lu] = [%i]\n", pv->index, pv->n);
if (pv->n == value)
{
return (pv);
}
pv = pv->next;
}
return (NULL);
}

/**
 * linear_skip - function that searches for a value
 * @list: the list of search
 * @value: the value
 * Return: pointer or NULL
 */
skiplist_t *linear_skip(skiplist_t *list, int value)
{
skiplist_t *act, *pv;
size_t actt, pvv;
if (!list)
return (NULL);
act = list;
while (act->express != NULL)
{
pv = act;
act = act->express;
actt = act->index;
pvv = pv->index;
printf("Value checked at index [%lu] = [%i]\n", actt, act->n);
if (pv->n > value && pv->index == 0)
return (NULL);
if (act->n >= value)
{
break;
}
}
if (!act->express && act->n < value)
{
pv = act;
pvv = pv->index;
while (act->next)
act = act->next;
actt = act->index;
}
printf("Value found between indexes [%lu] and [%lu]\n", pvv, actt);
return (find(pv, act, value));
}
