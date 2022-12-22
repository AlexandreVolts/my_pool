#include <unistd.h>

void my_putchar(char c) {
    write(1, &c, 1);
}
void my_putstr(char *str) {
    for (; *str != '\0'; str++) {
        my_putchar(*str);
    }
}
int main()
{
    my_putstr("z\n");
    return (0);
}