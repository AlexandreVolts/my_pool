#include <iostream>
#include <criterion/criterion.h>
#include <criterion/redirect.h>
#include "../WarpSystem.hpp"

static void redirect_all_stdout(void)
{
    cr_redirect_stdout();
    cr_redirect_stderr();
}

Test(core_test, core_checking_test, .init=redirect_all_stdout)
{
    WarpSystem::QuantumReactor reactor;
    WarpSystem::QuantumReactor *ptr = &reactor;
    WarpSystem::Core core(ptr);

    cr_assert(core.checkReactor() == ptr);
}