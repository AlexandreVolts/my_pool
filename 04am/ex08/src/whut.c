#include <stdlib.h>
#include "prototypes.h"

int get_array_nb_elem(const int *ptr1, const int *ptr2)
{
    if (ptr1 == NULL || ptr2 == NULL || ptr1 >= ptr2)
        return (0);
    return (ptr2 - ptr1);
}
whut_t *get_whut_ptr(const int *member)
{
    whut_t w;
    char *output = (char *)member;
    char *m = (char *)&w.member;
    char *base = (char *)&w;

    return ((whut_t *)(output - (m - base)));
}