#include <stdlib.h>
#include "tree.h"

void tree_node_dump(tree_node_t *tree_node, dump_func_t dump_func)
{
    dump_func(tree_node == NULL ? NULL : tree_node->data);
}