#include "binary_trees.h"

/**
 * binary_tree_is_root - checks if node is a root of an entire tree
 * @node: node to check
 *
 * Return: 0 if node is not a root or node is NULL, 1 otherwise
 */
int binary_tree_is_root(const binary_tree_t *node)
{
	if (node == NULL)
		return (0);
	if (node->parent == NULL)
		return (1);
	return (0);
}
