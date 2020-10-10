#include "binary_trees.h"

static int NOMEM;

/**
 * max_heapify - swaps node n values
 * @inserted: node n value to swap
 */
void max_heapify(heap_t **inserted)
{
	heap_t *curr;
	int tmp;

	for (curr = *inserted; curr->parent; curr = curr->parent)
		if (curr->n > curr->parent->n)
		{
			tmp = curr->parent->n;
			curr->parent->n = curr->n;
			curr->n = tmp;
			*inserted = (*inserted)->parent;
		}
}

/**
 * pop_queue - pops node from queue
 * @q_node: double ptr to queue node
 */
void pop_queue(queue **q_node)
{
	queue *tmp;

	if (*q_node)
	{
		tmp = *q_node;
		*q_node = (*q_node)->next;
		free(tmp);
	}
}

/**
 * push_queue - pushes address of curr to queue
 * @qnode: double ptr to queue node
 * @curr: ptr to current node
 *
 * Return: ptr to new created queue node
 */
queue *push_queue(queue **qnode, heap_t *curr)
{
	queue **currq, *newq = malloc(sizeof(*newq));

	if (!newq)
		return (NULL);
	newq->node = curr;
	newq->next = NULL;

	currq = qnode;
	while (*currq)
		currq = &(*currq)->next;
	newq->next = *currq;
	*currq = newq;
	return (newq);
}

/**
 * push_insert - pushes node to queue, inserts into binary tree
 * @curr: ptr to currrent node
 * @currq: double ptr to currrent queue node
 * @inserted: double ptr to inserted node
 * @dir: double ptr to curr direction
 * @value: value stored in the node to be inserted
 *
 * Return: ptr to inserted node
 */
heap_t *push_insert(heap_t *curr, queue **currq, heap_t **inserted,
					heap_t **dir, int value)
{
	if (*dir)
	{
		if (!push_queue(currq, *dir))
			NOMEM = 1;
	}
	else
	{
		*dir = binary_tree_node(curr, value);
		if (!*dir)
			NOMEM = 1;
		*inserted = *dir;
	}
	return (*inserted);
}

/**
 * level_order - traverses tree in level order
 * @root: double ptr to root node
 * @value: value stored in the node to be inserted
 *
 * Return: ptr to inserted node, or NULL on failure
 */
heap_t *level_order(heap_t **root, int value)
{
	queue *currq = NULL;
	heap_t *inserted, *curr = *root;

	if (!push_queue(&currq, curr))
		return (NULL);
	inserted = NULL;
	while (currq)
	{
		curr = currq->node;
		if (!inserted)
			push_insert(curr, &currq, &inserted, &curr->left, value);
		if (!inserted)
			push_insert(curr, &currq, &inserted, &curr->right, value);
		if (NOMEM)
			return (NULL);
		pop_queue(&currq);
	}
	return (inserted);
}

/**
 * heap_insert - inserts a value into a max binary heap
 * @root: double ptr to the root node of the heap
 * @value: value stored in the node to be inserted
 *
 * Return: ptr to inserted node, or NULL on failure
 */
heap_t *heap_insert(heap_t **root, int value)
{
	heap_t *inserted;

	if (!root)
		return (NULL);
	if (!*root)
	{
		*root = binary_tree_node(*root, value);
		inserted = *root;
	}
	else
	{
		inserted = level_order(root, value);
		max_heapify(&inserted);
	}
	return (inserted);
}
