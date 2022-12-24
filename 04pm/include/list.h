#ifndef LIST_H_
#define LIST_H_

typedef struct node
{
    void *value;
    struct node *next;
} node_t;

typedef node_t *list_t;

#endif