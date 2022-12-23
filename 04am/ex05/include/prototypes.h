#ifndef PROTOTYPES_H_
#define PROTOTYPES_H_

#include <stdlib.h>

typedef int (*cmp_callback_t)(const void *, const void *);

void my_putchar(char c);
void my_putnbr(int nb);
void my_putstr(const char *str);
char *get(void *array, size_t index, size_t size);
void set(void *array, size_t index, size_t size, void *value);

void sort_int_array(int *array, size_t n);
size_t uniq_int_array(int *array, size_t n);
void disp_int_array(const int *array, size_t n);
void sort_array(void *array, size_t n, size_t size, cmp_callback_t compar);
size_t uniq_array(void *array, size_t n, size_t size, cmp_callback_t compar);
void disp_array(void *array, size_t n, size_t size, void (*print)(const void *));

#endif