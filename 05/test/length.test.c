#include <stdlib.h>
#include <criterion/criterion.h>
#include "string.module.h"

Test(string_length_test, null)
{
    string_t s;

    string_init(&s, NULL);
    cr_assert(s.length(&s) == 0);
    string_destroy(&s);
}
Test(string_length_test, empty)
{
    string_t s;

    string_init(&s, "");
    cr_assert(s.length(&s) == 0);
    string_destroy(&s);
}
Test(string_length_test, str)
{
    string_t s;

    string_init(&s, "hello world!");
    cr_assert(s.length(&s) == 12);
    string_destroy(&s);
}