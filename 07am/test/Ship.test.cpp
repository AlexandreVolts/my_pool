#include <iostream>
#include <criterion/criterion.h>
#include <criterion/redirect.h>
#include "../Borg.hpp"
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
Test(ship_test, empty_ctor_test, .init=redirect_all_stdout)
{
    Federation::Starfleet::Ship ship;

    cr_assert_stdout_eq_str("The ship USS Entreprise has been finished.\n");
    cr_assert_stdout_eq_str("It is 289 m long and 132 m in width.\n");
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
Test(ship_test, fire_test, .init=redirect_all_stdout)
{
    Federation::Starfleet::Ship ship(400, 20, "Kreogg", 2, 6);
    Federation::Starfleet::Captain captain("Adam Smith");
    Borg::Ship borgus;

    cr_assert_stdout_eq_str("The ship USS Xi has been finished.\n");
    cr_assert_stdout_eq_str("It is 400 m long and 20 m in width.\n");
    cr_assert_stdout_eq_str("It can go to Warp 2!\n");
    cr_assert_stdout_eq_str("Weapons are set: 6 torpedoes ready.\n");

    ship.promote(&captain);
    cr_assert_stdout_eq_str("Adam Smith: I'm glad to be the captain of the USS Kreogg.\n");

    ship.fire(&borgus);
    cr_assert_stdout_eq_str("USS Xi: Fire on target. 5 torpedoes remaining.");
    cr_assert(borgus.getShield() == 100 - 50);

    ship.fire(3, &borgus);
    cr_assert_stdout_eq_str("USS Xi: Fire on target. 5 torpedoes remaining.");
    cr_assert(borgus.getShield() == 100 - 200);

    ship.fire(4, &borgus);
    cr_assert_stdout_eq_str("USS Xi: Not enough torpedo to fire, Adam Smith!");
    cr_assert(borgus.getShield() == 100 - 200);

    ship.fire(2, &borgus);
    cr_assert_stdout_eq_str("USS Xi: Fire on target. 0 torpedoes remaining.");
    cr_assert_stdout_eq_str("USS Xi: No more torpedo to fire, Adam Smith!");
    cr_assert(borgus.getShield() == 100 - 300);
}