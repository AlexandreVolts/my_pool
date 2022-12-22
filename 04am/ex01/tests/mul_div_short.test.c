#include <criterion/criterion.h>
#include "prototypes.h"

Test(mul_div_short_test, test_positive)
{
    int a = 13;
    int b = 4;

    mul_div_short(&a, &b);
    cr_assert(a == 13 * 4);
    cr_assert(b == 13 / 4);
}
Test(mul_div_short_test, test_negative)
{
    int a = 16;
    int b = -4;

    mul_div_short(&a, &b);
    cr_assert(a == 16 * -4);
    cr_assert(b == 16 / -4);
}
Test(mul_div_short_test, test_invalid_div)
{
    int a = 16;
    int b = 0;

    mul_div_short(&a, &b);
    cr_assert(a == 0);
    cr_assert(b == 42);
}