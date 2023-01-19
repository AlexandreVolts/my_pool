#include <iostream>
#include <criterion/criterion.h>
#include <criterion/redirect.h>
#include "../KreogCom.hpp"

static void redirect_all_stdout(void)
{
    cr_redirect_stdout();
    cr_redirect_stderr();
}

Test(kreog_com_test, ctor, .init=redirect_all_stdout)
{
    KreogCom kc(67, 45, 2345);

    cr_assert_stdout_eq_str("KreogCom 2345 initialized\n");
}
Test(kreog_com_test, dtor, .init=redirect_all_stdout)
{
    KreogCom kc(5, 0, 456);

    cr_assert_stdout_eq_str("KreogCom 456 shutting down\n");
}