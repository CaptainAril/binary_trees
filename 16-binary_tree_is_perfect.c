#include "binary_trees.h"


/**
 * height_tree - get height of tree
 *
 * @tree: tree
 * Return: size
 */
int height_tree(const binary_tree_t *tree)
{
	if (tree == NULL)
	{
		return (0);
	}

	int height_l;
	int height_r;

	height_l = tree->left ? 1 + height_tree(tree->left) : 0;
	height_r = tree->right ? 1 + height_tree(tree->right) : 0;
	return (height_l = height_r ? 1 : 0);
}


/**
 * binary_tree_is_perfect - checks if a binary tree is perfect
 *
 * @tree: pointer to the root node of the tree to check
 * Return: 1 if tree is perfect, otherwise 0; 0 if tree is NULL
 */
int binary_tree_is_perfect(const binary_tree_t *tree)
{
	int levelL, levelR, heightL, heightR;

	if (tree == NULL)
		return (0);

	heightL = height_tree(tree->left);
	heightR = height_tree(tree->right);
	if (heightL != heightR)
		return (0);

	if (tree->left == NULL && tree->right == NULL)
		return (1);

	levelL = binary_tree_is_perfect(tree->left);
	levelR = binary_tree_is_perfect(tree->right);

	if ((levelL == 0 || levelR == 0) || (levelL != levelR))
		return (0);
	return (1);
}
