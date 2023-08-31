#include "binary_trees.h"
#include <stdio.h>

#define ROTR binary_tree_rotate_right
#define ROTL binary_tree_rotate_left
#define BBAL binary_tree_balance

/**
 * avl_rebalance2 - function to rebalance an AVL tree
 * @tree: root of tree to rebalance
 */
void avl_rebalance2(avl_t **tree)
{
	int bf;

	if (tree == NULL || *tree == NULL)
		return;
	if ((*tree)->left == NULL && (*tree)->right == NULL)
		return;
	avl_rebalance2(&(*tree)->left);
	avl_rebalance2(&(*tree)->right);
	bf = BBAL((const binary_tree_t *)*tree);
	if (bf > 1)
		*tree = ROTR((binary_tree_t *)*tree);
	else if (bf < -1)
		*tree = ROTL((binary_tree_t *)*tree);
}

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

/**
 * simple_remove - subroutine to remove node of BST when it has no children
 * @root: root of tree in which `to_remove` resides
 * @to_remove: node to remove
 * @parent: pointer to member of parent that points to `to_remove`
 *
 * Return: pointer to root in case root is replaced
 */
bst_t *simple_remove(bst_t *root, bst_t *to_remove, bst_t **parent)
{
	if (to_remove->left != NULL)
	{
		to_remove->left->parent = to_remove->parent;
		if (to_remove->parent == NULL)
		{
			root = to_remove->left;
			free(to_remove);
			return (root);
		}
		*parent = to_remove->left;
		free(to_remove);
		return (root);
	}
	else if (to_remove->parent == NULL)
	{
		free(to_remove);
		return (NULL);
	}
	*parent = NULL;
	free(to_remove);
	return (root);
}

/**
 * bst_remove - remove node from binary search tree with value equal to `value`
 * @root: root of tree from which to remove node
 * @value: value of node to remove
 *
 * Return: pointer to new root of tree
 */
bst_t *bst_remove(bst_t *root, int value)
{
	bst_t **parent, *child, *to_remove = bst_search(root, value);

	if (to_remove == NULL)
		return (root);
	if (to_remove->parent != NULL)
		parent = (to_remove == to_remove->parent->left ?
			  &to_remove->parent->left : &to_remove->parent->right);
	if (to_remove->right == NULL)
		return (simple_remove(root, to_remove, parent));
	child = to_remove->right;
	while (child->left != NULL)
		child = child->left;
	if (child != to_remove->right)
	{
		to_remove->right->parent = child;
		child->parent->left = child->right;
		if (child->right != NULL)
			child->right->parent = child->parent;
		child->right = to_remove->right;
	}
	if (to_remove->left != NULL)
		to_remove->left->parent = child;
	child->left = to_remove->left;
	child->parent = to_remove->parent;
	if (to_remove->parent == NULL)
	{
		free(to_remove);
		return (child);
	}
	*parent = child;
	free(to_remove);
	return (root);
}

/**
 * avl_remove - remove node from binary search tree with value equal to `value`
 * @root: root of tree from which to remove `value`
 * @value: value of node to remove
 *
 * Return: pointer to root
 */
avl_t *avl_remove(avl_t *root, int value)
{
	avl_t *avl_root = (avl_t *) bst_remove((bst_t *) root, value);

	if (avl_root == NULL)
		return (NULL);
	avl_rebalance2(&avl_root);
	return (avl_root);
}
