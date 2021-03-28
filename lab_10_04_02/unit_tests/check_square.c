#include"../inc/check_main.h"
#include <assert.h>

//Positives
START_TEST(test_multi_normal_f)
{
    garbage_collector_t gc = init_gc();
    number_t number_a;

    assert(make_number(&gc, 15, &number_a) == 0);
    assert(to_number(number_a) == 15);

    square(number_a);
    assert(to_number(number_a) == 225);
    free_gc(&gc);

}
END_TEST

START_TEST(test_multi_normal_s)
{
    garbage_collector_t gc = init_gc();
    number_t number_a;

    assert(make_number(&gc, 3, &number_a) == 0);
    assert(to_number(number_a) == 3);

    square(number_a);
    assert(to_number(number_a) == 9);
    free_gc(&gc);

}
END_TEST

START_TEST(test_multi_normal_t)
{
    garbage_collector_t gc = init_gc();
    number_t number_a;

    assert(make_number(&gc, 6, &number_a) == 0);
    assert(to_number(number_a) == 6);

    square(number_a);
    assert(to_number(number_a) == 36);
    free_gc(&gc);

}
END_TEST

Suite *square_suite(Suite *s)
{
    TCase *tc_pos;
    tc_pos = tcase_create("positives");

    tcase_add_test(tc_pos, test_multi_normal_f);
    tcase_add_test(tc_pos, test_multi_normal_s);
    tcase_add_test(tc_pos, test_multi_normal_t);

    suite_add_tcase(s, tc_pos);

    return s;
}