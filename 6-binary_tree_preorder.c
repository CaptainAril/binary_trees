#include "binary_trees.h"

/**
 * binary_tree_preorder - tree traversal
 *
 * @tree: tree
 * @func: func
 * Return: nothing
 */

void binary_tree_preorder(const binary_tree_t *tree, void (*func)(int))
{
	if (func == NULL){
        return;
    }
	if (tree != NULL)
	{
		func(tree->n);
		binary_tree_preorder(tree->left, func);
		binary_tree_preorder(tree->right, func);
	}
}
