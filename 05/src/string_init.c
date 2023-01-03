#include <stdlib.h>
#include "string.module.h"

void string_init(string_t *this, const char *s)
{
    if (this == NULL)
        return;
    this->str = NULL;
    this->assign_c = &assign_c;
    this->assign_s = &assign_s;
    this->append_c = &append_c;
    this->append_s = &append_s;
    this->at = &at;
    this->clear = &clear;
    this->length = &length;
    this->compare_c = &compare_c;
    this->compare_s = &compare_s;
    this->assign_c(this, s);
}