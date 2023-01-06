#include <stdlib.h>
#include <string.h>
#include <criterion/criterion.h>
#include "string.module.h"

Test(string_slice_test, null)
{
    string_t s;
    string_t *tmp;

    string_init(&s, NULL);
    tmp = s.slice(&s, 0, 0);
    cr_assert(tmp->str == NULL);
    string_destroy(tmp);
    free(tmp);
    string_destroy(&s);
}
Test(string_slice_test, empty)
{
    string_t s;
    string_t *tmp;

    string_init(&s, "");
    tmp = s.slice(&s, 0, 10);
    cr_assert(strcmp(tmp->str, "") == 0);
    string_destroy(tmp);
    free(tmp);
    tmp = s.slice(&s, 10, 5);
    cr_assert(strcmp(tmp->str, "") == 0);
    string_destroy(tmp);
    free(tmp);
    string_destroy(&s);
}
Test(string_slice_test, str_positive)
{
    string_t s;
    string_t *tmp;

    string_init(&s, "hello world test!");
    tmp = s.slice(&s, 0, 5);
    cr_assert(strcmp(tmp->str, "hello") == 0);
    string_destroy(tmp);
    free(tmp);
    tmp = s.slice(&s, 6, 5);
    cr_assert(strcmp(tmp->str, "world") == 0);
    string_destroy(tmp);
    free(tmp);
    tmp = s.slice(&s, 8, 20);
    cr_assert(strcmp(tmp->str, "rld test!") == 0);
    string_destroy(tmp);
    free(tmp);
    tmp = s.slice(&s, 20, 3);
    cr_assert(strcmp(tmp->str, "") == 0);
    string_destroy(tmp);
    free(tmp);
    string_destroy(&s);
}
Test(string_slice_test, str_negative_offset)
{
    string_t s;
    string_t *tmp;

    string_init(&s, "hello world test!");
    tmp = s.slice(&s, -11, 11);
    cr_assert(strcmp(tmp->str, "world test!") == 0);
    string_destroy(tmp);
    free(tmp);
    tmp = s.slice(&s, -20, 25);
    cr_assert(strcmp(tmp->str, "hello world test!") == 0);
    string_destroy(tmp);
    free(tmp);
    tmp = s.slice(&s, -5, 4);
    cr_assert(strcmp(tmp->str, "test") == 0);
    string_destroy(tmp);
    free(tmp);
    string_destroy(&s);
}
Test(string_slice_test, str_negative_length)
{
    string_t s;
    string_t *tmp;

    string_init(&s, "hello world test!");
    tmp = s.slice(&s, 11, -5);
    cr_assert(strcmp(tmp->str, "world") == 0);
    string_destroy(tmp);
    free(tmp);
    tmp = s.slice(&s, 17, -7);
    cr_assert(strcmp(tmp->str, "d test!") == 0);
    string_destroy(tmp);
    free(tmp);
    tmp = s.slice(&s, 5, -10);
    cr_assert(strcmp(tmp->str, "hello") == 0);
    string_destroy(tmp);
    free(tmp);
    tmp = s.slice(&s, 27, -20);
    cr_assert(strcmp(tmp->str, "orld test!") == 0);
    string_destroy(tmp);
    free(tmp);
    tmp = s.slice(&s, -6, -5);
    cr_assert(strcmp(tmp->str, "world") == 0);
    string_destroy(tmp);
    free(tmp);
    string_destroy(&s);
}