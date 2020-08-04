#include <stdio.h>
#include <stdlib.h>
#include "binary_trees.h"
/**
*binary_tree_insert_left - a function that inserts a node
*@parent: is a pointer to the node to insert the left-child in
*@value: is the value to store in the new node
*Return: return a pointer to the created node
*/
int binary_tree_size(heap_t *tree)
{
int x;
if (tree == NULL)
return (0);
else
x = binary_tree_size(tree->right) + 1 + binary_tree_size(tree->left);
return (x);
}
heap_t *binary_tree_insert_left(heap_t *parent, int value)
{
binary_tree_t *newnode;
if (parent == NULL)
{
return (NULL);
}
newnode = malloc(sizeof(binary_tree_t));
if (!newnode)
{
return (NULL);
}
newnode->left = parent->left;
parent->left = newnode;
newnode->parent = parent;
newnode->n = value;
newnode->right = NULL;
if (newnode->left)
newnode->left->parent = newnode;
return (newnode);
}
char *decimalToBinary(int val)
{
int bi = 0;
int rem, temp = 1;
static char m[999];
while (val!=0)
{
rem = val%2;
val = val / 2;
bi = bi + rem*temp;
temp = temp * 10;
}
sprintf(m, "%i", bi);
return (m);
 printf("%s hhhhhh", m);
}
heap_t *gotoval( char *val, heap_t *root, int value)
{
int i, t;
 heap_t *newnode, *k, *b = root;
 i = 0;
while(val[i])
{
i += 1;
}
 printf("%d", i);
for (t = 1; t<= i-1; i++)
  {
    while(k)
      {
if (val[t] == 0)
  if(k->left)
k = k->left;
else if (val[t] == 1)
  if (k->right)
k = k->right;
  binary_tree_print(k);
      }
}
if (val[i-1] > 0)
  {
  b = (binary_tree_insert_left(root, value));
 return b;
  }
 else
   return root;
/*root->right = newnode;*/
 /*if (val[i] == 0)
   if(root->left )
     return(binary_tree_insert_left(root, value));
   else
   return b;*/
/* return newnode;*/
}
void *swap(heap_t *m, heap_t *t)
{
  int z;
  z = m->n;
  m->n = t->n;
  t->n = z;  
}
heap_t *heap_insert(heap_t **root, int value)
{
    char *p;
    int m = 0;
heap_t *new;
heap_t *y;
  new = malloc(sizeof(heap_t));
    new->n = value;
    new->left = NULL;
    new->right = NULL;
if (!*root){
    *root = new;
    return *root;
}
 else
   {
    m = binary_tree_size(*root);
/*printf(m);*/
p = decimalToBinary(m);
 y= gotoval(p, *root, value);
 /*y->n = value;*/
 /*while(y->n > y->parent->n)
   swap(y->n, y->parent->n);*/
   }
 return(y);
}
