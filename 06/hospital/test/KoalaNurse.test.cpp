#include <iostream>
#include <criterion/criterion.h>
#include <criterion/redirect.h>
#include "../KoalaNurse.hpp"
#include "../SickKoala.hpp"

static void redirect_all_stdout(void)
{
    cr_redirect_stdout();
    cr_redirect_stderr();
}

Test(koala_nurse_test, destructor_test, .init=redirect_all_stdout)
{
    KoalaNurse *koala = new KoalaNurse(5);

    delete koala;
    cr_assert_stdout_eq_str("Nurse 5: Finally some rest!\n");
}
Test(koala_nurse_test, give_drug_test, .init=redirect_all_stdout)
{
    SickKoala sick("Hakim");
    KoalaNurse nurse(5);

    nurse.giveDrug("LSD", sick);
    cr_assert_stdout_eq_str("Mr.Hakim: Goerkreog!\n");
}
Test(koala_nurse_test, time_check_test, .init=redirect_all_stdout)
{
    KoalaNurse nurse(8);

    nurse.timeCheck();
    cr_assert_stdout_eq_str("Nurse 8: Time to get to work!\n");
    nurse.timeCheck();
    cr_assert_stdout_eq_str("Nurse 8: Time to go home to my eucalyptus forest!\n");
}