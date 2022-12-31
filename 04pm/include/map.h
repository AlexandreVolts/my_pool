#ifndef MAP_H_
#define MAP_H_

#include "list.h"

typedef list_t map_t;
typedef int (*key_comparator_t)(void *first_key, void *second_key);

typedef struct pair
{
    void *key;
    void *value;
} pair_t;

#endif