#include <stdlib.h>
#include <criterion/criterion.h>
#include "list.h"
#include "tree.h"
#include "prototypes.h"

Test(tree_is_empty_test, null)
{
    tree_t tree = NULL;

    cr_assert(tree_is_empty(tree));
}
Test(tree_is_empty_test, empty)
{
    tree_t tree = malloc(sizeof(tree_t));

    tree->children = NULL;
    cr_assert(tree_is_empty(tree));
    free(tree);
}
Test(tree_is_empty_test, not_empty)
{
    tree_t tree = malloc(sizeof(tree_t));
    list_t list = NULL;
    list_t tmp = NULL;

    for (unsigned int i = 0; i < 3; i++) {
        list = malloc(sizeof(node_t));
        list->next = tmp;
        list->value = 0;
        tmp = list;
    }
    tree->children = list;
    cr_assert(!tree_is_empty(tree));
    list_clear(&list);
    free(tree);
}