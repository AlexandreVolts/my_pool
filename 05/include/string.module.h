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
    char (*at)(const struct string *this, size_t pos);
    void (*clear)(struct string *this);
    size_t (*length)(const struct string *this);
    int (*compare_s)(const struct string *this, const struct string *dest);
    int (*compare_c)(const struct string *this, const char *str);
    size_t (*copy)(const struct string *this, char *s, size_t n, size_t pos);
    const char *(*c_str)(const struct string *this);
    int (*empty)(const struct string *this);
    int (*find_s)(const struct string *this, const struct string *str, size_t pos);
    int (*find_c)(const struct string *this, const char *str, size_t pos);
    void (*insert_s)(struct string *this, const struct string *str, size_t pos);
    void (*insert_c)(struct string *this, const char *str, size_t pos);
    int (*to_int)(const struct string *this);
    char **(*split_c)(const struct string *this, char separator);
    struct string **(*split_s)(const struct string *this, char separator);
    void (*print)(const struct string *this);
    void (*join_c)(struct string *this, char delim, const char * const *array);
    void (*join_s)(struct string *this, char delim, const struct string * const *array);
    struct string *(*slice)(const struct string *this, int offset, int length);
} string_t;

void string_init(string_t *this, const char *s);
void string_destroy(string_t *this);
void assign_s(string_t *this, const string_t *source);
void assign_c(string_t *this, const char *source);
void append_s(string_t *this, const string_t *source);
void append_c(string_t *this, const char *source);
char at(const string_t *this, size_t pos);
void clear(string_t *this);
size_t length(const string_t *this);
int compare_s(const string_t *this, const string_t *source);
int compare_c(const string_t *this, const char *source);
size_t copy(const string_t *this, char *s, size_t n, size_t pos);
const char *c_str(const string_t *this);
int empty(const string_t *this);
int find_s(const string_t *this, const string_t *str, size_t pos);
int find_c(const string_t *this, const char *str, size_t pos);
void insert_s(string_t *this, const string_t *str, size_t pos);
void insert_c(string_t *this, const char *str, size_t pos);
int to_int(const string_t *this);
char **split_c(const string_t *this, char separator);
string_t **split_s(const string_t *this, char separator);
void print(const string_t *this);
void join_c(string_t *this, char delim, const char * const *array);
void join_s(string_t *this, char delim, const string_t * const *array);
string_t *slice(const string_t *this, int offset, int length);

int _strlen(const char *str);

#endif