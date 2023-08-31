#include "binary_trees.h"

#define max(a, b) ((a) >= (b) ? (a) : (b))

/**
 * height - measure the height of a binary tree
 * @tree: root of tree to measure
 *
 * Return: integer height of tree or 0 if tree is NULL
 */
int height(const binary_tree_t *tree)
{
	if (tree == NULL)
		return (0);
	if (tree->left == NULL && tree->right == NULL)
		return (tree->parent != NULL);
	return (1 + max(height(tree->left),
			height(tree->right)));
}

/**
 * binary_tree_is_avl - check whether a binary tree is an AVL tree
 * @tree: root of tree to check
 *
 * Return: 1 if true, 0 otherwise
 */
int binary_tree_is_avl(const binary_tree_t *tree)
{
	int bf;

	if (!binary_tree_is_bst(tree))
		return (0);
	bf = height(tree->left) - height(tree->right);
	if (bf > 1 || bf < -1)
		return (0);
	return (1
		&& (tree->left == NULL || binary_tree_is_avl(tree->left))
		&& (tree->right == NULL || binary_tree_is_avl(tree->right)));
}

/**
 * bst_compare_right - check that all right nodes have a value greater
 * than `start_val`.
 * @tree: node to start comparison
 * @start_val: value to compare to
 *
 * Return: 1 if all right nodes are greater than `start_val`, 0 otherwise
 */
int bst_compare_right(const binary_tree_t *tree, int start_val)
{
	if (tree == NULL)
		return (1);
	if (tree->n > start_val)
		return (bst_compare_right(tree->right, start_val)
			&& bst_compare_right(tree->left, start_val));
	return (0);
}

/**
 * bst_compare_left - check that all left nodes have a value less
 * than `start_val`.
 * @tree: node to start comparison
 * @start_val: value to compare to
 *
 * Return: 1 if all left nodes are less than `start_val`, 0 otherwise
 */
int bst_compare_left(const binary_tree_t *tree, int start_val)
{
	if (tree == NULL)
		return (1);
	if (tree->n < start_val)
		return (bst_compare_left(tree->left, start_val)
			&& bst_compare_left(tree->right, start_val));
	return (0);
}

/**
 * binary_tree_is_bst - check if binary tree is a valid binary search tree
 * @tree: root of tree to check
 *
 * Return: 1 if true, 0 otherwise
 */
int binary_tree_is_bst(const binary_tree_t *tree)
{
	if (tree == NULL)
		return (0);
	if (bst_compare_left(tree->left, tree->n)
	    && bst_compare_right(tree->right, tree->n))
		return ((tree->left == NULL
			 || binary_tree_is_bst(tree->left))
			&& (tree->right == NULL
			    || binary_tree_is_bst(tree->right)));
	return (0);
}
