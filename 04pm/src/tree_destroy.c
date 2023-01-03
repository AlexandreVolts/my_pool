#include <stdbool.h>
#include <stdlib.h>
#include "prototypes.h"
#include "tree.h"

bool tree_destroy(tree_t *tree_ptr)
{
    tree_t tree = tree_ptr == NULL ? NULL : *tree_ptr;
    list_t list;
    tree_node_t *children;

    if (tree == NULL)
        return (false);
    list = tree->children;
    for (; list != NULL; list = list->next) {
        children = list->value;
        tree_destroy(&children);
    }
    list_clear(&list);
    free(tree);
    return (true);
}