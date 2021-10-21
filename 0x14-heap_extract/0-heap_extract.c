#include "binary_trees.h"
/**
 * height - for holbertonschool
 * @tree: var
 * Return: var
 **/
size_t height(const heap_t *tree)
{
	size_t left, right;

	if (!tree)
		return (0);

	if (!tree->left && !tree->right)
		return (0);

	left = height(tree->left) + 1;
	right = height(tree->right) + 1;

	if (left >= right)
		return (left);
	else		return (right);
}

/**
 * recursion - for holbertonschool
 * @tree: var
 * @node: var
 * @height: the height
 * @level: a var
 **/
void recursion(heap_t *tree, heap_t **node, size_t height, size_t level)
{
	if (!tree)
		return;

	if (height == level)
		*node = tree;

	level++;

	if (tree->left)
		recursion(tree->left, node, height, level);

	if (tree->right)
		recursion(tree->right, node, height, level);
}

/**
 * replace - for holb school
 * @tree: var
 * @node: var
 * @extracted_value: var
 * Return: return  the v alue of node
 **/
int replace(heap_t **tree, heap_t **node, int extracted_value)
{
	heap_t *rns;
	int value;

	rns = *tree;

	while (rns->left || rns->right)
	{
		if (!rns->right || rns->left->n > rns->right->n)
		{
			value = rns->n;
			rns->n = rns->left->n;
			rns->left->n = value;
			rns = rns->left;
		}
		else if (!rns->left || rns->left->n < rns->right->n)
		{
			value = rns->n;
			rns->n = rns->right->n;
			rns->right->n = value;
			rns = rns->right;
		}
	}
	rns->n = (*node)->n;
	if ((*node)->parent->right)
		(*node)->parent->right = NULL;
	else
		(*node)->parent->left = NULL;
	free(*node);
	return (extracted_value);
}

/**
 * heap_extract - for holbertonschool
 * @root: var
 * Return: return the root
 **/
int heap_extract(heap_t **root)
{
	int extracted_value, result;
	size_t level, altura;
	heap_t *rns, *node = NULL;

	if (!root || !*root)
		return (0);
	rns = *root;
	extracted_value = rns->n;
	level = 0;
	if (rns->left == NULL && rns->right == NULL)
	{
		*root = NULL;
		free(rns);
		return (extracted_value);
	}
	altura = height(rns);
	recursion(rns, &node, altura, level);
	result = replace(&rns, &node, extracted_value);
	return (result);
}
