#ifndef PROTOTYPES_H_
#define PROTOTYPES_H_

#include "action.h"

void my_putchar(char c);
void my_putstr(const char *str);
void print_normal(const char *str);
void print_reverse(const char *str);
void print_upper(const char *str);
void print_42(const char *str);
void do_action(action_t action, const char *str);

#endif