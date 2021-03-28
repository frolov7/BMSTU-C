#include <stdio.h>
#include <stdlib.h>
#include <check.h>
#include <string.h>
#include "../inc/list.h"

#define SUCCESS 0
#define NO_RESULT -1

#ifndef CHECK_MAIN_H
#define CHECK_MAIN_H

int compare_lists(node_t *head1, node_t *head2);
void free_str(void *data);
char *copy_dynamic(const char *s);
node_t *make_node(const char *s);
void free_str(void *data);
int comparator(const void *a, const void *b);

node_t* read_list(FILE *f);
Suite *pop_f(Suite *s);
Suite *pop_b(Suite *s);
Suite *rev(Suite *s);
Suite *sort_func(Suite *s);

#endif