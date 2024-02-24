#include "bst.h"

#include <stddef.h>
#include <stdlib.h>

struct bst_node *create_node(int value)
{
    struct bst_node *res = malloc(sizeof(struct bst_node));
    if (!res)
        return NULL;
    res->data = value;
    res->left = NULL;
    res->right = NULL;
    return res;
}

struct bst_node *add_node(struct bst_node *tree, int value)
{
    if (!tree)
        return create_node(value);
    ;

    if (value > tree->data)
    {
        tree->right = add_node(tree->right, value);
    }

    if (value <= tree->data)
    {
        tree->left = add_node(tree->left, value);
    }

    return tree;
}

struct bst_node *delete_node(struct bst_node *tree, int value)
{
    if (!tree)
        return tree;

    if (value > tree->data)
    {
        tree->right = delete_node(tree->right, value);
        return tree;
    }

    if (value < tree->data)
    {
        tree->left = delete_node(tree->left, value);
        return tree;
    }

    if (!tree->left)
    {
        struct bst_node *tmp = tree->right;
        free(tree);
        return tmp;
    }

    else if (!tree->right)
    {
        struct bst_node *tmp = tree->left;
        free(tree);
        return tmp;
    }

    else
    {
        struct bst_node *tmpparent = tree;
        struct bst_node *tmpsucc = tree->right;

        while (tmpsucc->left)
        {
            tmpparent = tmpsucc;
            tmpsucc = tmpsucc->left;
        }

        if (tmpparent != tree)
            tmpparent->left = tmpsucc->right;
        else
            tmpparent->right = tmpsucc->right;

        tree->data = tmpsucc->data;
        free(tmpsucc);
    }

    return tree;
}

const struct bst_node *find(const struct bst_node *tree, int value)
{
    if (!tree)
        return NULL;

    if (tree->data == value)
        return tree;

    if (value > tree->data)
    {
        return find(tree->right, value);
    }

    return find(tree->left, value);
}

void free_bst(struct bst_node *tree)
{
    if (!tree)
        return;

    free_bst(tree->left);
    free_bst(tree->right);

    free(tree);
}

int main(void)
{}
