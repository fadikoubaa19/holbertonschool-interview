#include "binary_trees.h"

/**
  *newNode - 1st func to insert the node
  *@data: val that need to get inserted
  *@left: the pointer of left nude
  *@right: the pointer of right node
  *Return: null or the node
  */

avl_t *newNode(int data, avl_t *left, avl_t *right)
{
	avl_t *node = malloc(sizeof(avl_t));

	if (!node)
		return (NULL);
	node->n = data;
	node->parent = NULL;
	node->left = left;
	node->right = right;

	return (node);
}

/**
  *sortedArrayToBST - 2nd function
  *@array: the pointer of parent
  *@start: the first index
  *@end: the last index
  *Return: null or fail or pointer
  */

avl_t *sortedArrayToBST(int *array, int start, int end)
{
	avl_t *root, *left, *right;
	int middle = (start + end) / 2;

	if (start > end)
		return (NULL);

	left = sortedArrayToBST(array, start, middle - 1);
	right = sortedArrayToBST(array, middle + 1, end);

	root = newNode(array[middle], left, right);
	if (left != NULL)
		left->parent = root;
	if (right != NULL)
		right->parent = root;
	return (root);
}
/**
  *sorted_array_to_avl - 3rd func array to avl
  *@array: the first converted pointer
  *@size: the numb of elements
  *Return: the pointer of root
  *or return fail or null
  */
avl_t *sorted_array_to_avl(int *array, size_t size)
{
	if (array == NULL)
		return (NULL);

	return (sortedArrayToBST(array, 0, size - 1));
}
