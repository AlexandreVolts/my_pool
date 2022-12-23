#ifndef PROTOTYPES_H_
#define PROTOTYPES_H_

#include <stdlib.h>

typedef struct whut
{
    char c;
    int align;
    long any;
    int member;
    char *wow;
    char d;
} whut_t;

int get_array_nb_elem(const int *ptr1, const int *ptr2);
whut_t *get_whut_ptr(const int *member);

#endif