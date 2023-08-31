#include "binary_trees.h"

/**
 * binary_tree_nodes - count the number of internal nodes in a binary tree
 * @tree: tree to count internal nodes of
 *
 * Return: number of internal nodes
 */
size_t binary_tree_nodes(const binary_tree_t *tree)
{
	if (tree == NULL)
		return (0);
	if (tree->left == NULL && tree->right == NULL)
		return (0);
	return (1
		+ binary_tree_nodes(tree->left)
		+ binary_tree_nodes(tree->right));
}
