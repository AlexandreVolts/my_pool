#include <stdlib.h>
#include "action.h"
#include "prototypes.h"

void print_normal(const char *str)
{
    if (str == NULL)
        return;
    my_putstr(str);
}
void print_reverse(const char *str)
{
    if (str == NULL || *str == '\0')
        return;
    print_reverse(str + 1);
    my_putchar(*str);
}
void print_upper(const char *str)
{
    for (; str != NULL && *str != '\0'; str++) {
        if (*str >= 'a' && *str <= 'z') {
            my_putchar(*str - ('a' - 'A'));
            continue;
        }
        my_putchar(*str);
    }
}
void print_42(const char *str)
{
    str = str;
    my_putstr("42");
}
void do_action(action_t action, const char *str)
{
    void (*func[])(const char *str) = {
        print_normal,
        print_reverse,
        print_upper,
        print_42
    };

    (*func[action])(str);
}