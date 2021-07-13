#include "binary_trees.h"

/**
 * binary_tree_size - function binary tree size
 * @tree: the pointer
 * Return: if null return 0
 */
size_t binary_tree_size(const binary_tree_t *tree)
{
	size_t i = 1;

	if (!tree)
		return (0);
	if (tree->left != NULL)
		i = i + binary_tree_size(tree->left);
	if (tree->right != NULL)
		i = i + binary_tree_size(tree->right);
	return (i);
}

/**
 * binary_tree_is_perfect - funcition to check the binary tree
 * @tree: the pointer
 * Return: NULL or 0
 */
int binary_tree_is_perfect(const binary_tree_t *tree)
{
	if (!tree)
		return (0);

	if (binary_tree_size(tree->left) == binary_tree_size(tree->right))
		return (1);
	return (0);
}

/**
 * heap_parent_vs_child - function that swap nodes
 * @son: the pointer
 * @father: the pointer
 * Return: 0
 */
void heap_parent_vs_child(heap_t **son, heap_t **father)
{
	heap_t *left_side, *right_side, *child = *son, *parent = *father;

	right_side = (*son)->right, left_side = (*son)->left;

	if (child->n > parent->n)
	{
		if (child->left)
			child->left->parent = parent;
		if (child->right)
			child->right->parent = parent;
		if (parent->left == child)
		{
			if (parent->right)
				parent->right->parent = child;
			child->right = parent->right;
			child->left = parent;
		}
		else
		{
			parent->left->parent = child;
			child->left = parent->left;
			child->right = parent;
		}
		if (parent->parent)
		{
			if (parent->parent->left == parent)
				parent->parent->left = child;
			else
				parent->parent->right = child;
		}
		else
		{
			*father = child;
		}
		child->parent = parent->parent;
		parent->parent = child;
		parent->left = left_side;
		parent->right = right_side;
	}
}

/**
 * heap_insert - insert the max binary
 * @root: the pointer
 * @value: valeur
 * Return: failure
 */
heap_t *heap_insert(heap_t **root, int value)
{
	heap_t *new_tree;

	if ((*root) == NULL)
	{
		*root = binary_tree_node(NULL, value);
		return (*root);
	}
	if (binary_tree_is_perfect(*root) || (!binary_tree_is_perfect((*root)->left)))
	{
		if ((*root)->left != NULL)
		{
			new_tree = heap_insert(&((*root))->left, value);
			heap_parent_vs_child(&((*root)->left), root);
			return (new_tree);
		}
		else
		{
			new_tree = binary_tree_node(*root, value);
			(*root)->left = new_tree;
			heap_parent_vs_child(&((*root)->left), root);
			return (new_tree);
		}
	}
	else
	{
		if ((*root)->right != NULL)
		{
			new_tree = heap_insert(&((*root)->right), value);
			heap_parent_vs_child(&((*root)->right), root);
			return (new_tree);
		}
		else
		{
			new_tree = binary_tree_node(*root, value);
			(*root)->right = new_tree;
			heap_parent_vs_child(&((*root)->right), root);
			return (new_tree);
		}
	}
	return (NULL);
}

