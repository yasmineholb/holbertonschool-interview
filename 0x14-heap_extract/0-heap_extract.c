#include "binary_trees.h"
#include <stdlib.h>
/**
 * binary_tree_order - function order
 * @tree: tree
 * @node: node
 * @lev: level of tree
 * @haut: height
 * Return: void
 **/
void binary_tree_order(heap_t *tree, heap_t **node, size_t lev, size_t haut)
{
if (tree == NULL)
return;
if (haut == lev)
*node = tree;
lev++;
if (tree->right != NULL)
binary_tree_order(tree->right, node, lev, haut);
if (tree->left != NULL)
binary_tree_order(tree->left, node, lev, haut);
}
/**
 * binary_tree_height - function height
 * @tree: tree pointer
 * Return: size_t
 **/
size_t binary_tree_height(const heap_t *tree)
{
size_t left, right;
if (tree == NULL)
return (0);
if (tree->left == NULL && tree->right == NULL)
return (0);
right = binary_tree_height(tree->right) + 1;
left = binary_tree_height(tree->left) + 1;
if (right > left)
return (right);
else
return (left);
}
/**
 * heap_extract - extracts heap
 * @root: the root
 * Return: an int
 **/
int heap_extract(heap_t **root)
{
int value, value_aux;
size_t lev = 0;
heap_t *aux, *node;
if (root == NULL || *root == NULL)
return (0);
aux = *root;
value = aux->n;
if (aux->left == NULL && aux->right == NULL)
{
*root = NULL;
free(aux);
return (value);
}
binary_tree_order(aux, &node, lev, binary_tree_height(aux));
while (aux->left || aux->right)
{
if (!aux->right || aux->left->n > aux->right->n)
{
value_aux = aux->n;
aux->n = aux->left->n;
aux->left->n = value_aux;
aux = aux->left;
}
else if (!aux->left || aux->left->n < aux->right->n)
{
value_aux = aux->n;
aux->n = aux->right->n;
aux->right->n = value_aux;
aux = aux->right;
}
}
aux->n = node->n;
if (node->parent->right)
node->parent->right = NULL;
else
node->parent->left = NULL;
free(node);
return (value);
}
