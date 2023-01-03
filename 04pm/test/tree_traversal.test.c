#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <criterion/criterion.h>
#include <criterion/redirect.h>
#include "prototypes.h"

static void my_putchar(char c)
{
    write(1, &c, 1);
}
static void my_putnbr(int nb)
{
    if (nb == 0)
        return;
    if (nb < 0) {
        my_putchar('-');
        my_putnbr(-nb);
        return;
    }
    my_putnbr(nb / 10);
    my_putchar(nb % 10 + '0');
}
static void print_int(const void *nbr)
{
    int tmp = *((int *)nbr);

    my_putnbr(tmp);
    my_putchar('\n');
}
static container_t create_container()
{
    container_t container;

    container.container = NULL;
    container.push_func = (void *)&stack_push;
    container.pop_func = (void *)&stack_pop;
    return (container);
}
static void redirect_all_stdout(void)
{
    cr_redirect_stdout();
    cr_redirect_stderr();
}

Test(tree_traversal_test, with_null, .init=redirect_all_stdout)
{
    tree_traversal(NULL, NULL, NULL);
    cr_assert_stdout_eq_str("");
}
Test(tree_traversal_test, with_one_children, .init=redirect_all_stdout)
{
    tree_node_t *tree;
    container_t container = create_container();
    int a = 5;
    int b = 8;

    tree_init(&tree, &a);
    tree_add_child(tree, &b);
    tree_traversal(tree, &container, (void *)&print_int);
    cr_assert_stdout_eq_str("5\n8\n");
    tree_destroy(&tree);
}
Test(tree_traversal_test, add_multiple_children, .init=redirect_all_stdout)
{
    tree_node_t *tree;
    container_t container = create_container();
    int a = 5;
    int b[] = { 4, 8, 3 };

    tree_init(&tree, &a);
    for (unsigned int i = 0; i < 3; i++) {
        tree_add_child(tree, &b[i]);
    }
    tree_traversal(tree, &container, (void *)&print_int);
    cr_assert_stdout_eq_str("5\n3\n8\n4\n");
    tree_destroy(&tree);
}
Test(tree_traversal_test, add_children_to_children, .init=redirect_all_stdout)
{
    container_t container = create_container();
    tree_node_t *tree;
    tree_node_t *l_leaf;
    tree_node_t *r_leaf;
    int a = 5;
    int b[3][2] = { { 2, 6 }, { 7, 1 }, { 9, 3 } };

    tree_init(&tree, &a);
    l_leaf = tree_add_child(tree, &b[0][0]);
    r_leaf = tree_add_child(tree, &b[0][1]);
    tree_add_child(l_leaf, &b[1][0]);
    tree_add_child(l_leaf, &b[1][1]);
    tree_add_child(r_leaf, &b[2][0]);
    tree_add_child(r_leaf, &b[2][1]);
    tree_traversal(tree, &container, (void *)&print_int);
    cr_assert_stdout_eq_str("5\n6\n3\n9\n2\n1\n7\n");
    tree_destroy(&tree);
}