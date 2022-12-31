#ifndef PROTOTYPES_H_
#define PROTOTYPES_H_

#include <stdbool.h>
#include "list.h"
#include "map.h"
#include "queue.h"
#include "stack.h"

typedef void (*value_displayer_t)(const void *value);

unsigned int list_get_size(list_t list);
bool list_is_empty(list_t list);
bool list_add_elem_at_front(list_t *front_ptr, void *elem);
bool list_add_elem_at_back(list_t *front_ptr, void *elem);
bool list_add_elem_at_position(list_t *front_ptr, void *elem, unsigned int position);
void *list_get_elem_at_front(list_t list);
void *list_get_elem_at_back(list_t list);
void *list_get_elem_at_position(list_t list, unsigned int position);
bool list_del_elem_at_front(list_t *front_ptr);
bool list_del_elem_at_back(list_t *front_ptr);
bool list_del_elem_at_position(list_t *front_ptr, unsigned int position);
void list_clear(list_t *front);
void list_dump(list_t list, value_displayer_t val_disp);
unsigned int map_get_size(map_t map);
bool map_is_empty(map_t map);
int map_get_index(map_t map_ptr, void *key, key_comparator_t key_cmp);
bool map_add_elem(map_t *map_ptr, void *key, void *value, key_comparator_t key_cmp);
void *map_get_elem(map_t *map_ptr, void *key, key_comparator_t key_cmp);
bool map_del_elem(map_t *map_ptr, void *key, key_comparator_t key_cmp);
void map_clear(map_t *map_ptr);
unsigned int queue_get_size(queue_t queue);
bool queue_is_empty(queue_t queue);
bool queue_push(queue_t *queue_ptr, void *elem);
bool queue_pop(queue_t *queue_ptr);
void queue_clear(queue_t *queue_ptr);
void *queue_front(queue_t stack);
unsigned int stack_get_size(stack_t stack);
bool stack_is_empty(stack_t stack);
bool stack_push(stack_t *stack_ptr, void *elem);
bool stack_pop(stack_t *stack_ptr);
void stack_clear(stack_t *stack_ptr);
void *stack_top(stack_t stack);

#endif