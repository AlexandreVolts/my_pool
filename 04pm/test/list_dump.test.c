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
static void my_putstr(const char *str)
{
    for (; *str != '\0'; str++) {
        my_putchar(*str);
    }
}
static void print_int(const void *nbr)
{
    int tmp = *((int *)nbr);

    my_putnbr(tmp);
    my_putchar('\n');
}
static void redirect_all_stdout(void)
{
    cr_redirect_stdout();
    cr_redirect_stderr();
}

Test(list_dump_test, with_null, .init=redirect_all_stdout)
{
    list_dump(NULL, NULL);
    cr_assert_stdout_eq_str("");
}
Test(list_dump_test, with_int_list, .init=redirect_all_stdout)
{
    list_t list = NULL;
    int arr[] = { 5, 6, 9, 21 };

    for (int i = 0; i < 4; i++) {
        list_add_elem_at_back(&list, arr + i);
    }
    list_dump(list, &print_int);
    cr_assert_stdout_eq_str("5\n6\n9\n21\n");
    list_clear(&list);
}
Test(list_dump_test, with_str_list, .init=redirect_all_stdout)
{
    list_t list = NULL;
    char *arr[] = { "hello", " wo", "rld", " !" };

    for (int i = 0; i < 4; i++) {
        list_add_elem_at_back(&list, arr[i]);
    }
    list_dump(list, (void *)&my_putstr);
    cr_assert_stdout_eq_str("hello world !");
    list_clear(&list);
}