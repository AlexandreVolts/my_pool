#include <stdlib.h>
#include "string.module.h"

static void string_add_paired_func(string_t *this)
{
    this->assign_c = &assign_c;
    this->assign_s = &assign_s;
    this->append_c = &append_c;
    this->append_s = &append_s;
    this->compare_c = &compare_c;
    this->compare_s = &compare_s;
    this->find_c = &find_c;
    this->find_s = &find_s;
    this->insert_c = &insert_c;
    this->insert_s = &insert_s;
    this->split_c = &split_c;
    this->split_s = &split_s;
    this->join_c = &join_c;
    this->join_s = &join_s;
}
void string_init(string_t *this, const char *s)
{
    if (this == NULL)
        return;
    this->str = NULL;

    this->at = &at;
    this->clear = &clear;
    this->length = &length;
    this->copy = &copy;
    this->c_str = &c_str;
    this->empty = &empty;
    this->to_int = &to_int;
    this->print = &print;
    this->slice = &slice;
    string_add_paired_func(this);
    this->assign_c(this, s);
}