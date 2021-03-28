#include"../inc/check_main.h"
#include"../inc/list.h"

//Positives
START_TEST(test_pop_front)
{
    node_t *head = make_node("Black");
    node_t *current = head;
    current = current->next = make_node("Red");
    current = current->next = make_node("Green");
    current = current->next = make_node("Grey");
    current = current->next = make_node("Yellow");
    current = current->next = make_node("Pink");

    void *data1 = (char *)pop_front(&head); 

    ck_assert_str_eq(data1, "Black");

    iterate_list(head, free_str);
    free_list(&head);
    free(data1);
}
END_TEST

Suite *pop_f(Suite *s)
{
    TCase *tc_pos;
    tc_pos = tcase_create("positives");

    tcase_add_test(tc_pos, test_pop_front);

    suite_add_tcase(s, tc_pos);

    return s;
}