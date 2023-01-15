#include <iostream>
#include <criterion/criterion.h>
#include <criterion/redirect.h>
#include "../Skat.hpp"

static void redirect_all_stdout(void)
{
    cr_redirect_stdout();
    cr_redirect_stderr();
}

Test(skat_test, ctor)
{
    Skat skat;

    cr_assert(skat.stimPack() == 15);
    cr_assert(skat.name().compare("bob") == 0);
}
Test(skat_test, share_stimpack)
{
    Skat skat("Tom", 18);
    int stock = 5;

    skat.shareStimPack(5, stock);
    cr_assert(stock == 10);
    cr_assert(skat.stimPack() == 13);
    skat.shareStimPack(25, stock);
    cr_assert(stock == 10);
    cr_assert(skat.stimPack() == 13);
}
Test(skat_test, share_stimpack_output, .init=redirect_all_stdout)
{
    Skat skat("Tom", 18);
    int stock = 5;

    skat.shareStimPack(5, stock);
    cr_assert_stdout_eq_str("Keep the change.\n");
    skat.shareStimPack(25, stock);
    cr_assert_stdout_eq_str("Don't be greedy.\n");
}
Test(skat_test, add_stimpack, .init=redirect_all_stdout)
{
    Skat skat("Tom", 18);

    skat.addStimPack(5);
    cr_assert(skat.stimPack() == 23);
    skat.addStimPack(0);
    cr_assert_stdout_eq_str("Hey boya, did you forget something?\n");
}
Test(skat_test, use_stimpack, .init=redirect_all_stdout)
{
    Skat skat("Tom", 1);

    skat.useStimPack();
    cr_assert(skat.stimPack() == 0);
    cr_assert_stdout_eq_str("Time to kick some ass and chew bubble gum.\n");
    skat.useStimPack();
    cr_assert(skat.stimPack() == 0);
    cr_assert_stdout_eq_str("Mediiiiiiic\n");
}