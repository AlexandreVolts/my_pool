#include <iostream>
#include <criterion/criterion.h>
#include <criterion/redirect.h>
#include "../Federation.hpp"
#include "../WarpSystem.hpp"

static void redirect_all_stdout(void)
{
    cr_redirect_stdout();
    cr_redirect_stderr();
}

Test(ship_test, ctor_test, .init=redirect_all_stdout)
{
    Federation::Starfleet::Ship ship(400, 20, "Xi", 2);

    cr_assert_stdout_eq_str("The ship USS Xi has been finished.\n");
    cr_assert_stdout_eq_str("It is 400 m long and 20 m in width.\n");
    cr_assert_stdout_eq_str("It can go to Warp 2!\n");
}
Test(ship_test, core_manipulation, .init=redirect_all_stdout)
{
    Federation::Starfleet::Ship ship(400, 20, "Kreogg", 2);
    WarpSystem::QuantumReactor reactor;
    WarpSystem::Core core(&reactor);

    cr_assert_stdout_eq_str("The ship USS Xi has been finished.\n");
    cr_assert_stdout_eq_str("It is 400 m long and 20 m in width.\n");
    cr_assert_stdout_eq_str("It can go to Warp 2!\n");
    ship.checkCore();
    cr_assert_stdout_eq_str("");
    ship.setupCore(&core);
    cr_assert_stdout_eq_str("USS Kreogg: The core is set.");
    ship.checkCore();
    cr_assert_stdout_eq_str("USS Kreogg: The core is stable at the time.");
    core.checkReactor()->setStability(false);
    ship.checkCore();
    cr_assert_stdout_eq_str("USS Kreogg: The core is unstable at the time.");
}