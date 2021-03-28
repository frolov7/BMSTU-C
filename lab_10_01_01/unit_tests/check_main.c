#include <check.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include"../inc/check_main.h"

int compare_lists(node_t *head1, node_t *head2)
{
    int error = SUCCESS;
    for (node_t *current1 = head1, *current2 = head2; current1 && current2; current1 = current1->next, current2 = current2->next)
        if (strcmp(current1->data, current2->data))
        {
            error = NO_RESULT;
            break;
        }
    return error;
}

// ввод строки
char *copy_dynamic(const char *s)
{
    int len = strlen(s);
    char *copy = (char*) malloc((len + 1) * sizeof(char));
    strcpy(copy, s);

    return copy;
}

node_t *make_node(const char *s)
{
    node_t *node = (node_t *)malloc(sizeof(node_t));
    node->next = NULL;
    node->data = copy_dynamic(s);

    return node;
}
void free_str(void *data) 
{
    free((char*) data);
}

int comparator(const void *a, const void *b) 
{
    char *pa = (char *)a;
    char *pb = (char *)b;

    return strcmp(pa, pb);
}

Suite *tests_suite()
{
    Suite *s = suite_create("tests");

    s = pop_f(s);
    s = pop_b(s);
    s = rev(s);
    s = sort_func(s);

    return s;
}

int main(void)
{
    Suite *s = tests_suite();
    SRunner *runner = srunner_create(s);
    srunner_run_all(runner, CK_VERBOSE);
    int mistakes = srunner_ntests_failed(runner);
    srunner_free(runner);

    return mistakes;
}