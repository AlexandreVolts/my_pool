#include <stdlib.h>
#include "list.h"

void list_clear(list_t *front)
{
    list_t list = *front;
    list_t tmp = NULL;

    while (list != NULL) {
        tmp = list;
        list = list->next;
        free(tmp);
    }
    *front = NULL;
}