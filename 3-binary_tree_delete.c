#include "binary_trees.h"

/**
 * binary_tree_delete - delete entire binary tree rooted at `tree`
 * @tree: root of tree to delete
 */
void binary_tree_delete(binary_tree_t *tree)
{
	if (tree == NULL)
		return;
	binary_tree_delete(tree->left);
	binary_tree_delete(tree->right);
	free(tree);
}
