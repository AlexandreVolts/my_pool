#ifndef TREE_H_
#define TREE_H_

#include "list.h"

typedef struct tree_node
{
    void *data;
    list_t children;
} tree_node_t;

typedef tree_node_t *tree_t;
typedef void (*dump_func_t)(void *data);

#endif