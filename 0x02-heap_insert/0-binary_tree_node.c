#include <stdio.h>
#include "binary_trees.h"
/**
* binary_tree_node - creates a new binary tree node
* @parent: pointer to parent node
* @value: value to put in the new node
* Return: pointer to the new node, or NULL on failure
*/
binary_tree_t *binary_tree_node(binary_tree_t *parent, int value)
{
binary_tree_t *newnd = malloc(sizeof(binary_tree_t));
if (newnd == NULL)
return (NULL);
newnd->n = value;
newnd->parent = parent;
newnd->left = NULL;
newnd->right = NULL;
return (newnd);
}
