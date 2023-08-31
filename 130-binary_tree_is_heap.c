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
 * binary_tree_balance - compute balance factor for a binary tree
 * @tree: root of tree to measure balance factor of
 *
 * Return: integer balance factor, or 0 if tree is NULL
 */
int binary_tree_balance(const binary_tree_t *tree)
{
	if (tree == NULL)
		return (0);
	return (height(tree->left) - height(tree->right));
}

/**
 * binary_tree_is_perfect - check whether binary tree is perfect
 * (i.e. all non-leaf nodes have 2 children and tree is balanced)
 * @tree: tree to check
 *
 * If binary tree is balanced at each node then it is perfect.
 *
 * Return: 1 if perfect, 0 otherwise
 */
int binary_tree_is_perfect(const binary_tree_t *tree)
{
	int height_left, height_right;

	if (tree == NULL)
		return (1);
	if (tree->right == NULL && tree->left == NULL)
		return (1);
	if (tree->left && tree->left->n > tree->n)
		return (0);
	if (tree->right && tree->right->n > tree->n)
		return (0);
	height_left = height(tree->left);
	height_right = height(tree->right);
	if (height_left != height_right)
		return (0);
	return (binary_tree_is_perfect(tree->left)
		&& binary_tree_is_perfect(tree->right));
}

/**
 * binary_tree_is_heap - checks whether tree is formatted as a max binary heap
 * @tree: root of tree to check
 *
 * Return: 1 if it is a max binary heap, 0 otherwise
 */
int binary_tree_is_heap(const binary_tree_t *tree)
{
	int bf;

	if (tree == NULL)
		return (0);
	if (tree->left && tree->left->n > tree->n)
		return (0);
	if (tree->right && tree->right->n > tree->n)
		return (0);
	if (binary_tree_is_perfect(tree))
		return (1);
	bf = binary_tree_balance(tree);
	if (bf == 0)
		return (binary_tree_is_perfect(tree->left)
			&& binary_tree_is_heap(tree->right));
	if (bf == 1)
		return (binary_tree_is_heap(tree->left)
			&& binary_tree_is_perfect(tree->right));
	else
		return (0);
}
