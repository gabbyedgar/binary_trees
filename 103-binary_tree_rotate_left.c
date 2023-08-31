#include "binary_trees.h"

/**
 * binary_tree_rotate_left - rotate binary tree node to the left, making
 * it's right child it's parent.
 * @tree: node to rotate
 *
 * Return: pointer to node that has taken the place of `tree`, or NULL if
 * rotation is not possible.
 */
binary_tree_t *binary_tree_rotate_left(binary_tree_t *tree)
{
	binary_tree_t *pivot;

	if (tree == NULL || tree->right == NULL)
		return (NULL);
	pivot = tree->right;
	tree->right = pivot->left;
	if (pivot->left != NULL)
		pivot->left->parent = tree;
	pivot->left = tree;
	pivot->parent = tree->parent;
	tree->parent = pivot;
	return (pivot);
}
