#include <stdlib.h>
#include <unistd.h>

static void my_putchar(char c)
{
    write(1, &c, 1);
}
static void my_putnbr(int nb)
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
void disp_int_array(int *array, size_t n)
{
    if (array == NULL)
        return;
    for (size_t i = 0; i < n; i++) {
        my_putnbr(array[i]);
        my_putchar('\n');
    }
}