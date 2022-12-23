#include <stdlib.h>
#include <unistd.h>
#include "prototypes.h"

void my_putchar(char c)
{
    write(1, &c, 1);
}
void my_putnbr(int nb)
{
    if (nb == 0)
        return;
    if (nb < 0) {
        my_putchar('-');
        my_putnbr(-nb);
        return;
    }
    my_putnbr(nb / 10);
    my_putchar(nb % 10 + '0');
}
void my_putstr(const char *str)
{
    for (; *str != '\0'; str++) {
        my_putchar(*str);
    }
}
void disp_int_array(const int *array, size_t n)
{
    if (array == NULL)
        return;
    for (size_t i = 0; i < n; i++) {
        my_putnbr(array[i]);
        my_putchar('\n');
    }
}
void disp_array(void *array, size_t n, size_t size, void (*print)(const void *))
{
    if (array == NULL || print == NULL)
        return;
    for (size_t i = 0; i < n; i++) {
        print(get(array, i, size));
    }
}