#include "binary_trees.h"

/**
 * array_to_avl - function that builds an AVL tree from an array
 * @array: array to build tree from
 * @size: size of array
 *
 * Return: pointer to root of AVL tree
 */
avl_t *array_to_avl(int *array, size_t size)
{
	avl_t *tree = NULL;

	if (array == NULL)
		return (NULL);
	while (size--)
		if (avl_insert(&tree, *array++) == NULL)
			return (NULL);
	return (tree);
}
