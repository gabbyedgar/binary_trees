#include "binary_trees.h"

/**
 * binary_tree_inorder - in-order traversal of binary tree
 * @tree: root at which to begin traversal
 * @func: function to call on value of each node
 */
void binary_tree_inorder(const binary_tree_t *tree, void (*func)(int))
{
	if (tree == NULL || func == NULL)
		return;
	binary_tree_inorder(tree->left, func);
	func(tree->n);
	binary_tree_inorder(tree->right, func);
}
