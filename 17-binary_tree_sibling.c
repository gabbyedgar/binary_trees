#include "binary_trees.h"

/**
 * binary_tree_sibling - find the sibling to a node
 * @node: node to find sibling of
 *
 * Return: pointer to sibling, or NULL if none exists
 */
binary_tree_t *binary_tree_sibling(binary_tree_t *node)
{
	if (node == NULL || node->parent == NULL)
		return (NULL);
	return (node->parent->left == node ?
		node->parent->right : node->parent->left);
}
