#include "binary_trees.h"

/**
 * binary_tree_insert_right - insert node as right-child of `parent`
 * @parent: parent of new node
 * @value: integer value to store in new node
 *
 * Return: pointer to new node, or NULL on failure
 */
binary_tree_t *binary_tree_insert_right(binary_tree_t *parent, int value)
{
	binary_tree_t *new_node;

	if (parent == NULL)
		return (NULL);
	new_node = binary_tree_node(parent, value);
	if (new_node == NULL)
		return (NULL);
	new_node->right = parent->right;
	if (parent->right != NULL)
		parent->right->parent = new_node;
	parent->right = new_node;
	return (new_node);
}
