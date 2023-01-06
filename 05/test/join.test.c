#include <stdlib.h>
#include <criterion/criterion.h>
#include "string.module.h"

Test(string_join_test, from_null)
{
    string_t s;

    string_init(&s, "hello");
    s.join_c(&s, ' ', NULL);
    cr_assert(strcmp(s.str, "hello") == 0);
    string_destroy(&s);
}
Test(string_join_test, from_null_array)
{
    string_t s;
    const char *arr[] = { NULL };

    string_init(&s, "hello");
    s.join_c(&s, ' ', arr);
    cr_assert(strcmp(s.str, "") == 0);
    string_destroy(&s);
}
Test(string_join_test, to_null)
{
    string_t s;
    const char *arr[] = { "hello", NULL };

    string_init(&s, NULL);
    s.join_c(&s, ' ', arr);
    cr_assert(strcmp(s.str, "hello") == 0);
    string_destroy(&s);
}
Test(string_join_test, basic_join)
{
    string_t s;
    const char *arr[] = { "hello", "world", NULL };

    string_init(&s, "test");
    s.join_c(&s, '.', arr);
    cr_assert(strcmp(s.str, "hello.world") == 0);
    string_destroy(&s);
}
Test(string_join_test, complex_join)
{
    string_t s;
    const char *arr[] = { "hello", "world", "!", NULL };

    string_init(&s, "test test");
    s.join_c(&s, '_', arr);
    cr_assert(strcmp(s.str, "hello_world_!") == 0);
    string_destroy(&s);
}