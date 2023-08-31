#include "binary_trees.h"

/**
 * binary_trees_ancestor - find lowest common ancestor of two nodes
 * @first: first node
 * @second: second node
 *
 * Return: pointer to lowest common ancestor, or NULL if none exists
 */
binary_tree_t *binary_trees_ancestor(const binary_tree_t *first,
				     const binary_tree_t *second)
{
	binary_tree_t *parent;

	if (first == NULL || second == NULL)
		return (NULL);
	if (first == second)
		return ((binary_tree_t *) first);
	while (first != NULL)
	{
		parent = (binary_tree_t *) second;
		while (parent != NULL)
		{
			if (parent == first)
				return (parent);
			parent = parent->parent;
		}
		first = first->parent;
	}
	return (NULL);
}
