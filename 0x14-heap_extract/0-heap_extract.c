#include "binary_trees.h"

/**
 * heap_size - get the size of heap
 * @heap: pointer to root
 * Return: the size.
 */
int heap_mal(const heap_t *heap)
{
	size_t left_side, right_side, calc;

	if (!heap)
		return (0);
	left_side = heap_mal(heap->left_side);
	right_side = heap_mal(heap->right_side);
	calc = left_side + right_side + 1;

	return (calc);
}

/**
 * heap_search - for holbertonschool
 * @heap: var.
 */
void heap_search(heap_t *heap)
{
	heap_t *node = heap, *child;
	int temp;

	while (1)
	{
		if (!node->left_side)
			break;
		if (!node->right_side)
			child = node->left_side;
		else
			child = node->left_side->n > node->right_side->n ?
				node->left_side : node->right_side;
		if (node->n > child->n)
			break;
		temp = node->n;
		node->n = child->n;
		child->n = temp;
		node = child;
	}
}

/**
 * heap_extract - extracts top node of max binary heap
 * @heap: pointer to heap
 * Return: root node
 */
int heap_extract(heap_t **heap)
{
	int n, size, bitwise;
	heap_t *node, *root;

	if (!heap || !*heap)
		return (0);

	root = *heap;
	n = root->n;
	size = heap_mal(root);

	if (size == 1)
	{
		free(root);
		*heap = NULL;
		return (n);
	}

	for (bitwise = 1; bitwise <= size; bitwise <<= 1)
		;
	bitwise >>= 2;

	for (node = root; bitwise > 0; bitwise >>= 1)
		node = size & bitwise ? node->right : node->left;
	root->n = node->n;

	if (node->parent->left_side == node)
		node->parent->left_side = NULL;
	else
		node->parent->right_side = NULL;

	free(node);
	heap_search(root);
	*heap = root;

	return (n);
}
