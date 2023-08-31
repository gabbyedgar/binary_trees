#include "binary_trees.h"

/**
 * bst_search - search for value in binary search tree
 * @tree: root of tree to search
 * @value: value to search for
 *
 * Return: pointer to node containing value, or NULL if not found
 */
bst_t *bst_search(const bst_t *tree, int value)
{
	if (tree == NULL)
		return (NULL);
	if (value == tree->n)
		return ((bst_t *) tree);
	else if (value < tree->n)
		return (bst_search(tree->left, value));
	else
		return (bst_search(tree->right, value));
}
