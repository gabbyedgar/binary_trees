#include "binary_trees.h"

/**
 * array_to_bst - function to build binary search tree from array
 * @array: array of integers from which to build tree
 * @size: number of elements in array
 *
 * Return: pointer to new binary search array
 */
bst_t *array_to_bst(int *array, size_t size)
{
	bst_t *root = NULL;

	if (array == NULL || size == 0)
		return (NULL);
	while (size--)
		bst_insert(&root, *array++);
	return (root);
}
