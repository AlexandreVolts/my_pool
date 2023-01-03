#ifndef CONTAINER_H_
#define CONTAINER_H_

#include <stdbool.h>

typedef bool (*push_func_t)(void *container, void *data);
typedef void *(*pop_func_t)(void *container);

typedef struct container
{
    void *container;
    push_func_t push_func;
    pop_func_t pop_func;
} container_t;

#endif