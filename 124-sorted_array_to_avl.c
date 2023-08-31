#include "binary_trees.h"

/**
 * _sorted_array_to_avl - subroutine to recursively populate AVL tree from
 * sorted array
 * @parent: parent of next node to insert
 * @array: array of integers from which to create new nodes
 * @size: size of array to draw from
 *
 * Return: pointer to root of new subtree
 */
avl_t *_sorted_array_to_avl(avl_t *parent, int *array, size_t size)
{
	avl_t *root;

	if (array == NULL || size == 0)
		return (NULL);
	root = (avl_t *) binary_tree_node(parent, array[(size - 1) / 2]);
	if (root == NULL)
		return (NULL);
	root->left = _sorted_array_to_avl(root, array, (size - 1) / 2);
	root->right = _sorted_array_to_avl(root,
					   array + (size + 1) / 2,
					   size / 2);
	return (root);
}

/**
 * sorted_array_to_avl - function to build AVL tree from sorted array
 * @array: sorted array of integers
 * @size: length of array
 *
 * Return: pointer root node of AVL tree
 */
avl_t *sorted_array_to_avl(int *array, size_t size)
{
	return (_sorted_array_to_avl(NULL, array, size));
}
