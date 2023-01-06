#include <stdlib.h>
#include <string.h>
#include <criterion/criterion.h>
#include "string.module.h"

Test(string_insert_test, from_null)
{
    string_t s;

    string_init(&s, NULL);
    s.insert_c(&s, "hello", 0);
    cr_assert(strcmp(s.str, "hello") == 0);
    string_destroy(&s);
}
Test(string_insert_test, to_null)
{
    string_t s;

    string_init(&s, "hello");
    s.insert_c(&s, NULL, 0);
    cr_assert(strcmp(s.str, "hello") == 0);
    string_destroy(&s);
}
Test(string_insert_test, insert)
{
    string_t s;

    string_init(&s, "");
    s.insert_c(&s, "hello", 0);
    cr_assert(strcmp(s.str, "hello") == 0);
     s.insert_c(&s, "", 25);
    cr_assert(strcmp(s.str, "hello") == 0);
    s.insert_c(&s, "world", 25);
    cr_assert(strcmp(s.str, "helloworld") == 0);
    s.insert_c(&s, "oo ", 5);
    cr_assert(strcmp(s.str, "hellooo world") == 0);
    s.insert_c(&s, "hi ", 0);
    cr_assert(strcmp(s.str, "hi hellooo world") == 0);
    string_destroy(&s);
}