#include "binary_trees.h"

/**
 * binary_tree_node - Create new binary tree node
 * @parent: parent node of new node
 * @value: integer value to store in new node
 *
 * Return: pointer to new node, or NULL on failure
 */
binary_tree_t *binary_tree_node(binary_tree_t *parent, int value)
{
	binary_tree_t *new_node = malloc(sizeof(binary_tree_t));

	if (new_node == NULL)
		return (NULL);
	new_node->parent = parent;
	new_node->right = new_node->left = NULL;
	new_node->n = value;
	return (new_node);
}
