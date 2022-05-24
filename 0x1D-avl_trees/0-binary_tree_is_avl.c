#include "binary_trees.h"

/**
* checker - checking avl
* @newn: node
* @minimum: the minimum value
* @maximum: the maximum value
* @height: height
* Return: 1 or zero
*/
int checker(const binary_tree_t *newn, int minimum, int maximum, int *height)
{
	int left, right;

	right = 0;
	left = 0;
	if (!newn)
		return (1);
	if (newn->n <= minimum || newn->n >= maximum)
		return (0);
	if (!checker(newn->left, minimum, newn->n, &left) ||
			!checker(newn->right, newn->n, maximum, &right))
		return (0);
	if (left > right)
		*height = left + 1;
	else
		*height = right + 1;
	return (abs(left - right) < 2);
}

/**
 * binary_tree_is_avl - function tree avl
 * avl checker
 * @tree: binary tree
 * Return: 1 or zero
 */
int binary_tree_is_avl(const binary_tree_t *tree)
{
	int height = 0;

	if (!tree)
		return (0);
	return (cheker(tree, INT_MIN, INT_MAX, &height));
}
