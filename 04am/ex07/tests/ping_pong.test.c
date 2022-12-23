#include <criterion/criterion.h>
#include "ping_pong.h"

Test(ping_pong_test, with_array)
{
    ping_t ping;

    cr_assert(sizeof(ping.ping.pong.ping) == sizeof(ping.ping.ping));
    cr_assert(sizeof(ping.pong) == 2 * sizeof(ping.ping.pong));
    cr_assert(sizeof(ping.ping.ping) == sizeof(ping.ping.pong.pong));
}