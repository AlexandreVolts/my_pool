#include <stdlib.h>
#include <string.h>
#include <criterion/criterion.h>
#include "string.module.h"

Test(string_copy_test, null)
{
    string_t s;

    string_init(&s, NULL);
    cr_assert(s.copy(&s, NULL, 1, 1) == 0);
    string_destroy(&s);
}
Test(string_copy_test, null_buffer)
{
    string_t s;

    string_init(&s, "hello");
    cr_assert(s.copy(&s, NULL, 5, 5) == 0);
    string_destroy(&s);
}
Test(string_copy_test, str_valid_cpy)
{
    string_t s;
    char buffer[10];

    string_init(&s, "hello world!");
    cr_assert(s.copy(&s, buffer, 5, 0) == 5);
    cr_assert(strcmp(buffer, "hello") == 0);
    cr_assert(s.copy(&s, buffer, 6, 6) == 6);
    cr_assert(strcmp(buffer, "world!") == 0);
    cr_assert(s.copy(&s, buffer, 1, 0) == 1);
    cr_assert(strcmp(buffer, "h") == 0);
    string_destroy(&s);
}
Test(string_copy_test, str_partial_cpy)
{
    string_t s;
    char buffer[40];

    string_init(&s, "hello world!");
    cr_assert(s.copy(&s, buffer, 20, 0) == 12);
    cr_assert(strcmp(buffer, "hello world!") == 0);
    cr_assert(s.copy(&s, buffer, 15, 6) == 6);
    cr_assert(strcmp(buffer, "world!") == 0);
    cr_assert(s.copy(&s, buffer, 0, 0) == 0);
    cr_assert(strcmp(buffer, "") == 0);
    string_destroy(&s);
}
Test(string_copy_test, invalid_copy)
{
    string_t s;
    char buffer[1];

    string_init(&s, "hello world!");
    cr_assert(s.copy(&s, buffer, 5, 20) == 0);
    cr_assert(strcmp(buffer, "") == 0);
    string_destroy(&s);
}