#include "binary_trees.h"

/**
 * get_size - gets the heap size
 * @heap: pointer to root of the heap
 * Return: size of heap
 */
int get_size(heap_t *heap)
{
	return (heap ? 1 + get_size(heap->left) + get_size(heap->right) : 0);
}


/**
 * heap_extract -  extracts the root node of a Max Binary Heapp
 * @heap: pointer to heap struct
 * Return: n value, 0
 */
int heap_extract(heap_t **heap)
{
	int n, size, i = 1, tmp;
	heap_t *node, *root, *child;

	if (!heap || !*heap)
		return (0);
	root = *heap;
	n = root->n;
	size = get_size(root);
	if (size == 1)
	{
		free(root);
		*heap = NULL;
		return (n);
	}
	for (; i <= size;)
		i <<= 1;
	i >>= 2;
	for (node = root; i > 0; i >>= 1)
		node = size & i ? node->right : node->left;
	root->n = node->n;
	if (node->parent->left == node)
		node->parent->left = NULL;
	else
		node->parent->right = NULL;
	free(node);
	node = root;
	while (1)
	{
		if (!node->left)
			break;
		if (!node->right)
			child = node->left;
		else
			child = node->left->n > node->right->n ? node->left : node->right;
		if (node->n > child->n)
			break;
		tmp = node->n;
		node->n = child->n;
		child->n = tmp;
		node = child;

	}
	*heap = root;
	return (n);
}
