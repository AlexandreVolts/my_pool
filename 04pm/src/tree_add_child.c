#include <stdlib.h>
#include "prototypes.h"
#include "tree.h"

tree_node_t *tree_add_child(tree_node_t *tree_node, void *data)
{
    tree_node_t *child;

    if (!tree_init(&child, data))
        return (NULL);
    if (tree_node == NULL) {
        free(child);
        return (NULL);
    }
    if (list_add_elem_at_back(&tree_node->children, child)) {
        return (child);
    }
    free(child);
    return (NULL);
}