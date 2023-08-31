#include "binary_trees.h"

/**
 * binary_tree_rotate_right - rotate binary tree node to the right, making
 * it's left child it's parent.
 * @tree: node to rotate
 *
 * Return: pointer to node that has taken the place of `tree`, or NULL if
 * rotation is not possible.
 */
binary_tree_t *binary_tree_rotate_right(binary_tree_t *tree)
{
	binary_tree_t *pivot;

	if (tree == NULL || tree->left == NULL)
		return (NULL);
	pivot = tree->left;
	tree->left = pivot->right;
	if (pivot->right != NULL)
		pivot->right->parent = tree;
	pivot->right = tree;
	pivot->parent = tree->parent;
	tree->parent = pivot;
	return (pivot);
}
