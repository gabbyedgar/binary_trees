#include "binary_trees.h"

/**
 * binary_tree_postorder - postorder traversal of binary tree
 * @tree: root at which to begin traversal
 * @func: function to call on value of each node
 */
void binary_tree_postorder(const binary_tree_t *tree, void (*func)(int))
{
	if (tree == NULL || func == NULL)
		return;
	binary_tree_postorder(tree->left, func);
	binary_tree_postorder(tree->right, func);
	func(tree->n);
}
