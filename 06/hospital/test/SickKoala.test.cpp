#include <iostream>
#include <criterion/criterion.h>
#include <criterion/redirect.h>
#include "../SickKoala.hpp"

static void redirect_all_stdout(void)
{
    cr_redirect_stdout();
    cr_redirect_stderr();
}

Test(sick_koala_test, destructor_test, .init=redirect_all_stdout)
{
    std::string name = "Rick";
    SickKoala *koala = new SickKoala(name);

    delete koala;
    cr_assert_stdout_eq_str("Mr.Rick: Kreooogg!! I'm cuuuured!\n");
}
Test(sick_koala_test, poke_test, .init=redirect_all_stdout)
{
    std::string name = "Yoshi";
    SickKoala koala(name);

    koala.poke();
    cr_assert_stdout_eq_str("Mr.Yoshi: Gooeeeeerrk!!\n");
}
Test(sick_koala_test, take_drug_test, .init=redirect_all_stdout)
{
    std::string name = "Mario";
    SickKoala koala(name);

    koala.takeDrug("Mars");
    cr_assert_stdout_eq_str("Mr.Mario: Mars, and it kreogs!\n");
    koala.takeDrug("Kinder");
    cr_assert_stdout_eq_str("Mr.Mario: There is a toy inside!\n");
    koala.takeDrug("Rail de coke");
    cr_assert_stdout_eq_str("Mr.Mario: Goerkreog!\n");
}
Test(sick_koala_test, over_drive_test, .init=redirect_all_stdout)
{
    std::string name = "Peach";
    SickKoala koala(name);

    koala.overDrive("Hello world!");
    cr_assert_stdout_eq_str("Mr.Peach: Hello world!\n");
    koala.overDrive("Kreog!");
    cr_assert_stdout_eq_str("Mr.Peach: 1337\n");
    koala.overDrive("Kreog! world!");
    cr_assert_stdout_eq_str("Mr.Peach: 1337 world!\n");
    koala.overDrive("Kreog! world! Kreog!");
    cr_assert_stdout_eq_str("Mr.Peach: 1337 world! 1337\n");
}