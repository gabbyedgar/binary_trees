#include "binary_trees.h"

/**
 * binary_tree_is_leaf - checks if node is a leaf node
 * @node: node to check
 *
 * Return: 0 if not a leaf or node is NULL, 1 otherwise
 */
int binary_tree_is_leaf(const binary_tree_t *node)
{
	if (node == NULL)
		return (0);
	if (node->left || node->right)
		return (0);
	return (1);
}
