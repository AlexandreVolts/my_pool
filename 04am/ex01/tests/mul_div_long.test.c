#include <criterion/criterion.h>
#include "prototypes.h"

Test(mul_div_long_test, test_positive)
{
    int a = 13;
    int b = 4;
    int mul;
    int div;

    mul_div_long(a, b, &mul, &div);
    cr_assert(mul == a * b);
    cr_assert(div == a / b);
}
Test(mul_div_long_test, test_negative)
{
    int a = 16;
    int b = -4;
    int mul;
    int div;

    mul_div_long(a, b, &mul, &div);
    cr_assert(mul == a * b);
    cr_assert(div == a / b);
}
Test(mul_div_long_test, test_invalid_div)
{
    int a = 16;
    int b = 0;
    int mul;
    int div;

    mul_div_long(a, b, &mul, &div);
    cr_assert(mul == 0);
    cr_assert(div == 42);
}