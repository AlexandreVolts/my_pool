#include <stdlib.h>
#include <criterion/criterion.h>
#include "list.h"
#include "tree.h"
#include "prototypes.h"

Test(tree_add_child_test, null)
{
    cr_assert(tree_add_child(NULL, NULL) == NULL);
}
Test(tree_add_child_test, add_one_child)
{
    tree_node_t *tree;
    int a = 5;
    int b = 8;

    tree_init(&tree, &a);
    cr_assert(tree_add_child(tree, &b) != NULL);
    cr_assert(list_get_size(tree->children) == 1);
    tree_destroy(&tree);
}
Test(tree_add_child_test, add_multiple_children)
{
    tree_node_t *tree;
    int a = 5;
    int b = 8;

    tree_init(&tree, &a);
    for (unsigned int i = 0; i < 3; i++) {
        cr_assert(tree_add_child(tree, &b) != NULL);
        cr_assert(list_get_size(tree->children) == i + 1);
    }
    tree_destroy(&tree);
}
Test(tree_add_child_test, add_children_to_children)
{
    tree_node_t *tree;
    tree_node_t *leaf;
    tree_node_t *tmp;
    int a = 5;
    int b = 8;

    tree_init(&tree, &a);
    leaf = tree;
    for (unsigned int i = 0; i < 3; i++) {
        tmp = leaf;
        leaf = tree_add_child(leaf, &b);
        cr_assert(leaf != NULL);
        cr_assert(list_get_size(tmp->children) == 1);
    }
    tree_destroy(&tree);
}