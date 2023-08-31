#include "binary_trees.h"

/**
 * binary_tree_depth - measure depth of node in binary tree
 * @node: pointer to node to measure
 *
 * Return: integer depth of node relative to root, or 0 if node is NULL
 */
size_t binary_tree_depth(const binary_tree_t *node)
{
	if (node == NULL || node->parent == NULL)
		return (0);
	return (1 + binary_tree_depth(node->parent));
}
