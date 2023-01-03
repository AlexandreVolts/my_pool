#include <stdbool.h>
#include <stdlib.h>
#include "tree.h"
#include "prototypes.h"

bool tree_is_empty(tree_t tree)
{
    return (tree == NULL || tree->children == NULL);
}