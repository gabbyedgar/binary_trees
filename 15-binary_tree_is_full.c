#include "binary_trees.h"

/**
 * binary_tree_is_full - check whether binary tree is full
 * (i.e. all nodes have either 0 or 2 children)
 * @tree: tree to check
 *
 * Return: 1 if full, 0 otherwise
 */
int binary_tree_is_full(const binary_tree_t *tree)
{
	if (tree == NULL || ((tree->left == NULL) ^ (tree->right == NULL)))
		return (0);
	if (tree->left == NULL && tree->right == NULL)
		return (1);
	return (1
		&& binary_tree_is_full(tree->left)
		&& binary_tree_is_full(tree->right));
}
