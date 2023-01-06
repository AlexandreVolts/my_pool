#include <stdlib.h>
#include <criterion/criterion.h>
#include "string.module.h"

static void dealloc_str_array(char **array)
{
    for (int i = 0; array[i] != NULL; i++) {
        free(array[i]);
    }
    free(array);
}
static void dealloc_array(string_t **array)
{
    for (int i = 0; array[i] != NULL; i++) {
        string_destroy(array[i]);
    }
    free(array);
}

Test(string_split_test, null)
{
    string_t s;
    char **str_array;
    string_t **array;

    string_init(&s, NULL);
    str_array = s.split_c(&s, ' ');
    array = s.split_s(&s, ' ');
    cr_assert(str_array[0] == NULL);
    cr_assert(array[0] == NULL);
    dealloc_str_array(str_array);
    dealloc_array(array);
    string_destroy(&s);
}
Test(string_split_test, empty)
{
    string_t s;
    char **str_array;
    string_t **array;

    string_init(&s, "");
    str_array = s.split_c(&s, ' ');
    array = s.split_s(&s, ' ');
    cr_assert(str_array[0] == NULL);
    cr_assert(array[0] == NULL);
    dealloc_str_array(str_array);
    dealloc_array(array);
    string_destroy(&s);
}
Test(string_split_test, basic_split)
{
    string_t s;
    char **str_array;
    string_t **array;

    string_init(&s, "hello world!");
    str_array = s.split_c(&s, ' ');
    array = s.split_s(&s, ' ');
    cr_assert(strcmp(str_array[0], "hello") == 0);
    cr_assert(strcmp(str_array[1], "world!") == 0);
    cr_assert(strcmp(array[0]->str, "hello") == 0);
    cr_assert(strcmp(array[1]->str, "world!") == 0);
    dealloc_str_array(str_array);
    dealloc_array(array);
    string_destroy(&s);
}
Test(string_split_test, complex_split)
{
    string_t s;
    char **str_array;
    string_t **array;

    string_init(&s, "hello world!");
    str_array = s.split_c(&s, 'l');
    array = s.split_s(&s, 'l');
    cr_assert(strcmp(str_array[0], "he") == 0);
    cr_assert(strcmp(str_array[1], "o wor") == 0);
    cr_assert(strcmp(str_array[2], "d!") == 0);
    cr_assert(strcmp(array[0]->str, "he") == 0);
    cr_assert(strcmp(array[1]->str, "o wor") == 0);
    cr_assert(strcmp(array[2]->str, "d!") == 0);
    dealloc_str_array(str_array);
    dealloc_array(array);
    string_destroy(&s);
}
Test(string_split_test, split_at_start)
{
    string_t s;
    char **str_array;
    string_t **array;

    string_init(&s, "hello world!");
    str_array = s.split_c(&s, 'h');
    array = s.split_s(&s, 'h');
    cr_assert(strcmp(str_array[0], "ello world!") == 0);
    cr_assert(strcmp(array[0]->str, "ello world!") == 0);
    dealloc_str_array(str_array);
    dealloc_array(array);
    string_destroy(&s);
}
Test(string_split_test, split_at_end)
{
    string_t s;
    char **str_array;
    string_t **array;

    string_init(&s, "hello world!");
    str_array = s.split_c(&s, '!');
    array = s.split_s(&s, '!');
    cr_assert(strcmp(str_array[0], "hello world") == 0);
    cr_assert(strcmp(array[0]->str, "hello world") == 0);
    dealloc_str_array(str_array);
    dealloc_array(array);
    string_destroy(&s);
}