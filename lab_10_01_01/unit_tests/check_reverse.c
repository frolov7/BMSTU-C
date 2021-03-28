#include"../inc/check_main.h"
#include"../inc/list.h"

//Positives
START_TEST(test_reverse)
{
    node_t *head1 = make_node("Black");
    node_t *before = head1;
    before = before->next = make_node("Red");
    before = before->next = make_node("Green");
    before = before->next = make_node("Grey");
    before = before->next = make_node("Yellow");
    before = before->next = make_node("Pink");

    head1 = reverse(head1);

    node_t *head2 = make_node("Pink");
    node_t *after = head2;
    after = after->next = make_node("Yellow");
    after = after->next = make_node("Grey");
    after = after->next = make_node("Green");
    after = after->next = make_node("Red");
    after = after->next = make_node("Black");

    int error = compare_lists(head1, head2);
    
    ck_assert_int_eq(error, SUCCESS);

    iterate_list(head1, free_str);
    iterate_list(head2, free_str);
    free_list(&head1);
    free_list(&head2);
}
END_TEST

Suite *rev(Suite *s)
{
    TCase *tc_pos;
    tc_pos = tcase_create("positives");

    tcase_add_test(tc_pos, test_reverse);

    suite_add_tcase(s, tc_pos);

    return s;
}