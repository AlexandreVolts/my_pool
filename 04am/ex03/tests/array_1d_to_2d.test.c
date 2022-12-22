#include <stdlib.h>
#include <criterion/criterion.h>
#include "prototypes.h"

static int *generate_1d_array(int len)
{
    int *output = malloc(len * sizeof(int));

    for (int i = 0; i < len; i++) {
        output[i] = i;
    }
    return (output);
}

Test(array_1d_to_2d, basic_array)
{
    int *array = generate_1d_array(7 * 6);
    int **res = NULL;
    size_t width = 6;
    size_t height = 7;

    array_1d_to_2d(array, height, width, &res);
    cr_assert(res[0][0] == 0);
    cr_assert(res[6][5] == 41);
    cr_assert(res[4][4] == 28);
    cr_assert(res[0][3] == 3);
    cr_assert(res[3][0] == 18);
    cr_assert(res[4][2] == 26);
    free(array);
    array_2d_free(res, height, width);
}
Test(array_1d_to_2d, null_array)
{
    int *array = NULL;
    int **res = NULL;

    array_1d_to_2d(array, 2, 5, &res);
    cr_assert(res == NULL);
}