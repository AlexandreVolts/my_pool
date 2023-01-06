#include <stdlib.h>
#include <criterion/criterion.h>
#include "string.module.h"

Test(string_find_test, from_null)
{
    string_t s;

    string_init(&s, NULL);
    cr_assert(s.find_c(&s, "hello", 0) == -1);
    string_destroy(&s);
}
Test(string_find_test, to_null)
{
    string_t s;

    string_init(&s, "hello");
    cr_assert(s.find_c(&s, NULL, 0) == -1);
    string_destroy(&s);
}
Test(string_find_test, valid_find)
{
    string_t s;

    string_init(&s, "this is a test");
    cr_assert(s.find_c(&s, "s", 0) == 3);
    cr_assert(s.find_c(&s, "s", 8) == 12);
    cr_assert(s.find_c(&s, "this", 0) == 0);
    cr_assert(s.find_c(&s, "is a", 3) == 5);
    cr_assert(s.find_c(&s, "test", 5) == 10);
    string_destroy(&s);
}
Test(string_find_test, invalid_find)
{
    string_t s;

    string_init(&s, "this is a test");
    cr_assert(s.find_c(&s, "this", 5) == -1);
    cr_assert(s.find_c(&s, "is a", 8) == -1);
    cr_assert(s.find_c(&s, "test", 12) == -1);
    cr_assert(s.find_c(&s, "a", 25) == -1);
    string_destroy(&s);
}