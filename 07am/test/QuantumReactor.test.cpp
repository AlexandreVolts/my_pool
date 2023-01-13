#include <iostream>
#include <criterion/criterion.h>
#include <criterion/redirect.h>
#include "../WarpSystem.hpp"

static void redirect_all_stdout(void)
{
    cr_redirect_stdout();
    cr_redirect_stderr();
}

Test(quantum_reactor_test, stability_test, .init=redirect_all_stdout)
{
    WarpSystem::QuantumReactor reactor;

    cr_assert(reactor.isStable());
    reactor.setStability(false);
    cr_assert(!reactor.isStable());
}