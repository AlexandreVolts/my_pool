#include <stdlib.h>
#include <string.h>
#include <criterion/criterion.h>
#include "string.module.h"

Test(string_at_test, at_null)
{
    string_t s;

    string_init(&s, NULL);
    cr_assert(s.at(&s, 0) == -1);
    cr_assert(s.at(&s, 5) == -1);
    string_destroy(&s);
}
Test(string_at_test, at_empty)
{
    string_t s;

    string_init(&s, "");
    cr_assert(s.at(&s, 0) == -1);
    cr_assert(s.at(&s, 5) == -1);
    string_destroy(&s);
}
Test(string_at_test, at_str)
{
    string_t s;

    string_init(&s, "hello world!");
    cr_assert(s.at(&s, 0) == 'h');
    cr_assert(s.at(&s, 5) == ' ');
    cr_assert(s.at(&s, 10) == 'd');
    cr_assert(s.at(&s, 11) == '!');
    cr_assert(s.at(&s, 20) == -1);
    string_destroy(&s);
}