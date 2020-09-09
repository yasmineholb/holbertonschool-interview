#include <stdio.h>
#include <stdlib.h>
#include "lists.h"
/**
 *check_cycle - check function
 *@list: list
 *Return: int
 */
int check_cycle(listint_t *list)
{
listint_t *i, *j;
i = list;
j = list;
while (j && j->next)
{
i = i->next;
j = j->next->next;
if (j == i)
return (1);
}
return (0);
}
