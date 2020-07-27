#include <stdlib.h>
#include <stdio.h>
#include "lists.h"

/**
 * main - check the code for Holberton School students.
 *
 * Return: Always 0.
 */

int find_data(int item, listint_t **head) {
   int pos = 0;
   listint_t *current;
   current = *head;
   while(current) {
      if(current->n > item) {
         return(pos);
      }
      current = current->next;
      pos++;
   }
   return(pos);
}

listint_t *insert_nodeint_at_index(listint_t **head, int idx, int n)
{
listint_t *m, *p;
int i = 0;
if (head == NULL)
return (NULL);
m = malloc(sizeof(listint_t));
if (m == NULL)
return (NULL);
m->n = n;
p = *head;
if (idx == 0)
{
m->next = *head;
*head = m;
return (m);
}
while (p)
{
if (i == idx - 1)
{
m->next = p->next;
p->next = m;
break;
}
p = p->next;
i++;
if (p == NULL)
return (NULL);
}
return (m);
}

listint_t *insert_node(listint_t **head, int number)
{
  int s;
  listint_t *p;
  s = find_data(number, head);
  p = insert_nodeint_at_index(head, s, number);
  return(p);
}


