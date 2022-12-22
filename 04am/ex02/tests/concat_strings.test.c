#include <stdlib.h>
#include <string.h>
#include <criterion/criterion.h>

#include "prototypes.h"

Test(concat_strings_test, basic_strings)
{
    char str1[] = "hello";
    char str2[] = "world";
    char *res = NULL;

    concat_strings(str1, str2, &res);
    cr_assert(strcmp(res, "helloworld") == 0);
    free(res);
}
Test(concat_strings_test, one_null_string)
{
    char *str1 = NULL;
    char str2[] = "world";
    char *res = NULL;

    concat_strings(str1, str2, &res);
    cr_assert(strcmp(res, "world") == 0);
    free(res);
}
Test(concat_strings_test, null_strings)
{
    char *str1 = NULL;
    char *str2 = NULL;
    char *res = NULL;

    concat_strings(str1, str2, &res);
    cr_assert(res == NULL);
}