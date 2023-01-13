#include <iostream>
#include <criterion/criterion.h>
#include <criterion/redirect.h>
#include "../Federation.hpp"

Test(captain_test, name_test)
{
    Federation::Starfleet::Captain captain("James T. Watt");

    cr_assert(captain.getName().compare("James T. Watt"));
}
Test(captain_test, age_test)
{
    Federation::Starfleet::Captain captain("James T. Watt");

    cr_assert(captain.getAge() == 0);
    captain.setAge(25);
    cr_assert(captain.getAge() == 25);
}