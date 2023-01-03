#ifndef STRING_H_
#define STRING_H_

#include <stdlib.h>

typedef struct string
{
    char *str;
    void (*assign_s)(struct string *this, const struct string *dest);
    void (*assign_c)(struct string *this, const char *str);
    void (*append_s)(struct string *this, const struct string *dest);
    void (*append_c)(struct string *this, const char *str);
    char (*at)(struct string *this, size_t pos);
    void (*clear)(struct string *this);
    int (*length)(struct string *this);
    int (*compare_s)(struct string *this, const struct string *dest);
    int (*compare_c)(struct string *this, const char *str);
} string_t;

void string_init(string_t *this, const char *s);
void string_destroy(string_t *this);
void assign_s(string_t *this, const string_t *source);
void assign_c(string_t *this, const char *source);
void append_s(string_t *this, const string_t *source);
void append_c(string_t *this, const char *source);
char at(string_t *this, size_t pos);
void clear(string_t *this);
int length(string_t *this);
int compare_s(string_t *this, const string_t *source);
int compare_c(string_t *this, const char *source);

int _strlen(const char *str);

#endif