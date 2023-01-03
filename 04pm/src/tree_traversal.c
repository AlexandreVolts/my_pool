#include <stdlib.h>
#include "container.h"
#include "list.h"
#include "prototypes.h"
#include "tree.h"

static void container_cpy_tree(tree_t tree, container_t *container)
{
    list_t list = tree->children;

    container->push_func(&container->container, tree->data);
    for (unsigned int i = list_get_size(list); i > 0; i--) {
        container_cpy_tree(list_get_elem_at_position(list, i - 1), container);
    }
}
static void container_dump(void *container, dump_func_t dump_func)
{
    list_t list = container;

    for (; list != NULL; list = list->next) {
        dump_func(list->value);
    }
}
void tree_traversal(tree_t tree, container_t *container, dump_func_t dump_func)
{
    if (tree == NULL || container == NULL || dump_func == NULL)
        return;
    if (container->pop_func == NULL || container->push_func == NULL)
        return;
    container_cpy_tree(tree, container);
    container_dump(container->container, dump_func);
}