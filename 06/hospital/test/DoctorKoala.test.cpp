#include <iostream>
#include <criterion/criterion.h>
#include <criterion/redirect.h>
#include "../KoalaDoctor.hpp"
#include "../SickKoala.hpp"

static void redirect_all_stdout(void)
{
    cr_redirect_stdout();
    cr_redirect_stderr();
}

Test(koala_doctor_test, constructor_test, .init=redirect_all_stdout)
{
    KoalaDoctor koala("Jake");

    cr_assert_stdout_eq_str("Dr.Jake: I'm Dr.Jake! How do you kreog?\n");
}
Test(koala_doctor_test, diagnose_test, .init=redirect_all_stdout)
{
    SickKoala koala("Vladimir");
    KoalaDoctor doctor("Jimmy");

    cr_assert_stdout_eq_str("Dr.Jimmy: I'm Dr.Jimmy! How do you kreog?\n");
    doctor.diagnose(&koala);
    cr_assert_stdout_eq_str("Dr.Jimmy: So what's goerking you Mr.Vladimir?\n");
    cr_assert_stdout_eq_str("Mr.Vladimir: Gooeeeeerrk!!\n");
}