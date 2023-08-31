#include "binary_trees.h"

#define ROTR binary_tree_rotate_right
#define ROTL binary_tree_rotate_left
#define BBAL binary_tree_balance

/**
 * avl_rebalance - function to rebalance an AVL tree
 * @tree: root of tree to rebalance
 */
void avl_rebalance(avl_t **tree)
{
	int bf;

	if (tree == NULL || *tree == NULL)
		return;
	if ((*tree)->left == NULL && (*tree)->right == NULL)
		return;
	avl_rebalance(&(*tree)->left);
	avl_rebalance(&(*tree)->right);
	bf = BBAL((const binary_tree_t *)*tree);
	if (bf > 1)
	{
		if (BBAL((const binary_tree_t *)(*tree)->left) > 0)
			*tree = ROTR((binary_tree_t *)*tree);
		else
		{
			(*tree)->left = ROTL((binary_tree_t *)(*tree)->left);
			*tree = ROTR((binary_tree_t *)*tree);
		}
	}
	else if (bf < -1)
	{
		if (BBAL((const binary_tree_t *)(*tree)->right) < 0)
			*tree = ROTL((binary_tree_t *)*tree);
		else
		{
			(*tree)->right = ROTR((binary_tree_t *)(*tree)->right);
			*tree = ROTL((binary_tree_t *)*tree);
		}
	}
}

/**
 * avl_insert - function to insert a new value into an AVL tree
 * @tree: double pointer to root node of tree
 * @value: value of node to insert
 *
 * Return: pointer to inserted node
 */
avl_t *avl_insert(avl_t **tree, int value)
{
	avl_t *new_node = (avl_t *) bst_insert((bst_t **)tree, value);

	if (new_node != NULL)
		avl_rebalance(tree);
	return (new_node);
}

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
