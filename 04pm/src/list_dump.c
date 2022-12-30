#include <stdlib.h>
#include "list.h"
#include "prototypes.h"

void list_dump(list_t list, value_displayer_t val_disp)
{
    if (val_disp == NULL)
        return;
    for (; list != NULL; list = list->next) {
        val_disp(list->value);
    }
}