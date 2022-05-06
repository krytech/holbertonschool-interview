#include "binary_trees.h"
#include <stdlib.h>

/**
 * tree_height_left - gets the height of the left most branch
 * @node: the node of the tree which to find the height
 * Return: the heigh of the binary tree
 */
int tree_height_left(heap_t *node)
{
	int height = 0;

	while (node)
	{
		height++;
		node = node->left;
	}
	return (height);
}

/**
 * tree_arrange - arranges nodes of the binary tree in an array
 * @node: root node
 * @array: array to place pointers to the nodes
 * @index: current node index
 * Return: void
 */
void tree_arrange(heap_t *node, heap_t **array, int index)
{
	int index_left = index * 2 + 1;
	int index_right = index * 2 + 2;

	if (!node)
		return;

	array[index] = node;
	tree_arrange(node->left, array, index_left);
	tree_arrange(node->right, array, index_right);
}

/**
 * heap_insert - insert a value into a Max Binary Heap
 * @root: double pointer to the root node of the Heap
 * @value: value to store in the node to be inserted
 * Return: pointer to the inserted node
 */
heap_t *heap_insert(heap_t **root, int value)
{
	heap_t *insert = NULL, *parent = NULL;
	heap_t **node_array = NULL;
	int height = 0, max_nodes = 0, i = 0;

	if (!root)
		return (NULL);
	if (!*root)
	{
		insert = binary_tree_node(*root, value);
		*root = insert;
		return (insert);
	}
	height = get_left_height(*root);
	max_nodes = (1 << height) - 1;
	node_array = (heap_t **)calloc(max_nodes, sizeof(heap_t *));

	if (!node_array)
		return (NULL);

	tree_arrange(*root, node_array, 0);
	while (i < max_nodes && node_array[i])
		i++;

	parent = node_array[(i - (2 - i % 2)) / 2];
	insert = binary_tree_node(parent, value);
	if (!insert)
		return (NULL);
	if (i % 2)
		parent->left = insert;
	else
		parent->right = insert;

	while (parent && value >= parent->n)
	{
		insert->n = parent->n;
		parent->n = value;
		insert = parent;
		parent = parent->parent;
	}
	return (insert);
}
