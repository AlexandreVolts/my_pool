#include <stdbool.h>
#include <stdlib.h>
#include "tree.h"

bool tree_init(tree_t *tree_ptr, void *data)
{
    tree_t root = malloc(sizeof(tree_node_t));

    if (root == NULL)
        return (false);
    root->data = data;
    root->children = NULL;
    *tree_ptr = root;
    return (true);
}