#include "binary_trees.h"

/**
 * tree_size - finds the size of the tree
 * @node: root node of tree
 * Return: tree size
 */
int tree_size(heap_t *node)
{
	int left, right;

	if (!node)
		return (0);

	left = tree_size(node->left);
	right = tree_size(node->right);

	if (left > right)
		return (left + 1);
	return (right + 1);
}

/**
 * move_node - moves node
 * @node: node to move
 * Return: void
 */
void move_node(heap_t *node)
{
	heap_t *largest = NULL;
	int ph;

	if (node->right)
	{
		if (node->right->n > node->left->n)
			largest = node->right;
		else
			largest = node->left;
	}
	else if (node->left)
		largest = node->left;

	if (largest && largest->n > node->n)
	{
		ph = largest->n;
		largest->n = node->n;
		node->n = ph;
		move_node(largest);
	}
}

/**
 * get_node - gets the last most right node of the tree
 * @height: height of the tree
 * @height_counter: recursive height counter
 * @node: node
 * Return: last node
 */
heap_t *get_node(int height, int height_counter, heap_t *node)
{
	heap_t *left;
	heap_t *right;

	if (height_counter != height)
	{
		left = get_node(height, height_counter + 1, node->left);
		right = get_node(height, height_counter + 1, node->right);
	}
	else
		return (node);

	if (right)
		return (right);
	return (left);
}

/**
 * get_last - finds last node of the tree
 * @root: root node of the tree
 * Return: last node
 */
heap_t *get_last(heap_t *root)
{
	int height;

	height = tree_size(root);

	return (get_node(height, 1, root));
}

/**
 * heap_extract - extracts the root node of a Max Binary Heap
 * @root: double pointer to the  root node of the heap
 * Return: the value stored in the root node, otherwise 0 on failure
 */
int heap_extract(heap_t **root)
{
	heap_t *ph;
	int swap;

	if (!root || !*root)
		return (0);

	if (!(*root)->left && !(*root)->right)
	{
		swap = (*root)->n;
		free(*root);
		*root = NULL;
		return (swap);
	}
	ph = get_last(*root);
	if (ph->parent->right)
		ph->parent->right = NULL;
	else
		ph->parent->left = NULL;

	swap = (*root)->n;
	(*root)->n = ph->n;

	move_node(*root);

	free(ph);
	return (swap);
}
