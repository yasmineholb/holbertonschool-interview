#include "lists.h"
/**
 * find_listint_loop - function that finds the loop
 * @head: the head
 * Return: The address of the node where the loop starts
 */
listint_t *find_listint_loop(listint_t *head)
{
listint_t *fast_p, *slow_p;
if (head)
{
slow_p = head;
fast_p = head->next->next;
while (fast_p && fast_p->next)
{
if (fast_p == slow_p)
break;
slow_p = slow_p->next;
fast_p = fast_p->next->next;
}
if (slow_p == fast_p)
{
fast_p = fast_p->next;
while (fast_p != head)
{
fast_p = fast_p->next;
if (fast_p == slow_p)
head = head->next;
}
return (head);
}
}
return (0);
}
