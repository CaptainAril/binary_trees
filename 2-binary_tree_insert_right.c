#include <stdio.h>
#include <stdlib.h>
#include "binary_trees.h"

/**
 * *binary_tree_insert_right - isert to right
 *
 * @param parent: root
 * @param value: value
 * @return binary_tree_t*: return binary_tree_t
 */

binary_tree_t *binary_tree_insert_right(binary_tree_t *parent, int value)
{
	binary_tree_t *result = malloc(sizeof(binary_tree_t));
	binary_tree_t *current;

	result->n = value;
	result->left = NULL;
	result->right = NULL;
	result->parent = parent;

	if (parent == NULL)
	{
		return NULL;
	}

	if (parent->n < value)
	{
		if (parent->right != NULL && parent->right->n > value)
		{
			current = parent->right;
			parent->right = result;
			binary_tree_insert_right(result, current->n);
		}
		else
		{
			parent->right = result;
		}
	}

	return current;
}