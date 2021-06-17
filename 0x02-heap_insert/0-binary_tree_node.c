#include "binary_trees.h"
/**
 * binary_tree_node - creates binary tree
 * @parent: parent to the pointer node
 * @value: the value to put a new node
 * Return: NULL on failure
 */
binary_tree_t *binary_tree_node(binary_tree_t *parent, int value)
{
binary_tree_t *new;
new = malloc(sizeof(binary_tree_t));
if (!new)
return (NULL);
new->parent = parent;
new->n = value;
new->left = NULL;
new->right = NULL;
return (new);
}
