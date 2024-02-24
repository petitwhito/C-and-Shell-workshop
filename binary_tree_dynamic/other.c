#include <limits.h>
#include <stddef.h>
#include <stdio.h>

#include "binary_tree.h"

int size(const struct binary_tree *tree)
{
    if (!tree)
        return 0;
    return 1 + size(tree->right) + size(tree->left);
}

int max(int a, int b)
{
    return (a > b) ? a : b;
}

int height(const struct binary_tree *tree)
{
    if (!tree)
        return -1;
    return 1 + max(height(tree->left), height(tree->right));
}

int mypow(int x, int n)
{
    int i;
    int number = 1;

    for (i = 0; i < n; ++i)
        number *= x;

    return number;
}

int is_perfect(const struct binary_tree *tree)
{
    return size(tree) == (mypow(2, height(tree) + 1) - 1);
}

int comp(const struct binary_tree *tree, int i, int size)
{
    if (!tree)
        return 1;

    if (i >= size)
        return 0;

    return comp(tree->left, 2 * i + 1, size)
        && comp(tree->right, 2 * i + 2, size);
}

int is_complete(const struct binary_tree *tree)
{
    return comp(tree, 0, size(tree));
}

int is_degenerate(const struct binary_tree *tree)
{
    if (tree->right && tree->left)
    {
        return 0;
    }
    else if (tree->right)
        return is_degenerate(tree->right);
    else if (tree->left)
        return is_degenerate(tree->left);
    return 1;
}

int is_full(const struct binary_tree *tree)
{
    if (!tree->left && !tree->right)
    {
        return 1;
    }
    else if (!tree->right || !tree->left)
    {
        return 0;
    }
    return is_full(tree->right) && is_full(tree->left);
}

static int bst(const struct binary_tree *tree, int min, int max)
{
    if (!tree)
        return 1;

    if (tree->data > max || tree->data < min)
        return 0;

    return bst(tree->left, min, tree->data - 1)
        && bst(tree->right, tree->data + 1, max);
}

int is_bst(const struct binary_tree *tree)
{
    return bst(tree, INT_MIN, INT_MAX);
}
