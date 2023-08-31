#include "binary_trees.h"

/**
 * bst_insert - insert new node into correct location in binary search tree
 * @tree: double pointer to root of tree
 * @value: value of new node to insert
 *
 * Return: pointer to inserted node, or NULL on failure
 */
bst_t *bst_insert(bst_t **tree, int value)
{
	bst_t *root;

	if (tree == NULL)
		return (NULL);
	if (*tree == NULL)
	{
		*tree = (bst_t *) binary_tree_node(NULL, value);
		return (*tree);
	}
	root = *tree;
	if (value < root->n)
	{
		if (root->left == NULL)
		{
			root->left = (bst_t *) binary_tree_node(root, value);
			return (root->left);
		}
		else
			return (bst_insert(&(root->left), value));
	}
	if (value > root->n)
	{
		if (root->right == NULL)
		{
			root->right = (bst_t *) binary_tree_node(root, value);
			return (root->right);
		}
		else
			return (bst_insert(&(root->right), value));
	}
	return (NULL);
}
