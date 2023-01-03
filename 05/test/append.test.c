#include <stdlib.h>
#include <string.h>
#include <criterion/criterion.h>
#include "string.module.h"

Test(string_append_test, append_null)
{
    string_t s;

    string_init(&s, "");
    s.append_c(&s, NULL);
    cr_assert(strcmp(s.str, "") == 0);
    string_destroy(&s);
}
Test(string_append_test, append_on_null)
{
    string_t s;

    string_init(&s, NULL);
    s.append_c(&s, "Hello world!");
    cr_assert(strcmp(s.str, "Hello world!") == 0);
    string_destroy(&s);
}
Test(string_append_test, append_on_empty)
{
    string_t s;

    string_init(&s, "");
    s.append_c(&s, "Hello!");
    cr_assert(strcmp(s.str, "Hello!") == 0);
    string_destroy(&s);
}
Test(string_append_test, append_empty)
{
    string_t s;

    string_init(&s, "Hello");
    s.append_c(&s, "");
    cr_assert(strcmp(s.str, "Hello") == 0);
    string_destroy(&s);
}
Test(string_append_test, append_on_str)
{
    string_t s;

    string_init(&s, "Hello");
    s.append_c(&s, " world!");
    cr_assert(strcmp(s.str, "Hello world!") == 0);
    string_destroy(&s);
}