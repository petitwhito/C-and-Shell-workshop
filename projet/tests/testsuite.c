#include <criterion/criterion.h>
#include <criterion/redirect.h>
#include "../src/tinyprintf.h"
#include <stdio.h>

Test(Basic, first)
{
    cr_redirect_stdout();
    tinyprintf("%s [%d] %s", "Hello", 42, "world!");
    fflush(stdout);
    cr_expect_stdout_eq_str("Hello [42] world!");
}

Test(Basic, second)
{
    cr_redirect_stdout();
    tinyprintf("%s [%x] %s", "Hello", 42, "world!");
    fflush(stdout);
    cr_expect_stdout_eq_str("Hello [2a] world!");
}

Test(Basic, third)
{
    tinyprintf("Good morning ACU! %t Tinyprintf is cool", 12);
    cr_redirect_stdout();
    tinyprintf("Good morning ACU! %t Tinyprintf is cool", 12);
    fflush(stdout);
    cr_expect_stdout_eq_str("Good morning ACU! %t Tinyprintf is cool");
}

Test(Basic, fourth)
{
    tinyprintf("%%s", "in your head");
    cr_redirect_stdout();
    tinyprintf("%%s", "in your head");
    fflush(stdout);
    cr_expect_stdout_eq_str("%s");
}

Test(Basic, fifth)
{
    tinyprintf("%c%c is %s... %d too.", '4', '2', "the answer", '*');
    cr_redirect_stdout();
    tinyprintf("%c%c is %s... %d too.", '4', '2', "the answer", '*');
    fflush(stdout);
    cr_expect_stdout_eq_str("42 is the answer... 42 too.");
}

Test(Basic, six)
{
    tinyprintf("%u is Great !", -100);
    cr_redirect_stdout();
    tinyprintf("%u is Great !", -100);
    fflush(stdout);
    cr_expect_stdout_eq_str("4294967196 is Great !");
}





