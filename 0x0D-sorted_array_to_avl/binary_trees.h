#ifndef BINARY_TREES_H
#define BINARY_TREES_H


/* Libraries */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <limits.h>

/**
 * struct binary_tree_s - Binary tree node
 *
 * @n: Integer stored in the node
 * @parent: Pointer to the parent node
 * @left: Pointer to the left child node
 * @right: Pointer to the right child node
 */
struct binary_tree_s
{
	int n;
	struct binary_tree_s *parent;
	struct binary_tree_s *left;
	struct binary_tree_s *right;
};

typedef struct binary_tree_s binary_tree_t;
typedef struct binary_tree_s avl_t;

/**
 * struct queue_s - doubly linked list representation of a stack (or queue)
 * @node: a pointer to a binary tree node
 * @prev: points to the previous element of the stack (or queue)
 * @next: points to the next element of the stack (or queue)
 *
 * Description: doubly linked list node structure
 * for stack, queues, LIFO, FIFO Holberton project
 */
typedef struct queue_s
{
	const binary_tree_t *node;
	struct queue_s *prev;
	struct queue_s *next;
} queue_t;

/* Prototypes */
avl_t *sorted_array_to_avl(int *array, size_t size);
void binary_tree_print(const binary_tree_t *);

#endif /* BINARY_TREES_H */
