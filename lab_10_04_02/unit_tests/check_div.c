#include"../inc/check_main.h"
#include <assert.h>

//Positives
START_TEST(test_multi_normal_f)
{
    garbage_collector_t gc = init_gc();
    number_t number_a;
    number_t number_b;

    assert(make_number(&gc, 15, &number_a) == 0);
    assert(to_number(number_a) == 15);

    assert(make_number(&gc, 4, &number_b) == 0);
    assert(to_number(number_b) == 4);

    number_t div = divide(&gc, number_a, number_b);
    assert(to_number(div) == 3);
    free_gc(&gc);

}
END_TEST

START_TEST(test_multi_normal_s)
{
    garbage_collector_t gc = init_gc();
    number_t number_a;
    number_t number_b;

    assert(make_number(&gc, 16, &number_a) == 0);
    assert(to_number(number_a) == 16);

    assert(make_number(&gc, 4, &number_b) == 0);
    assert(to_number(number_b) == 4);

    number_t div = divide(&gc, number_a, number_b);
    assert(to_number(div) == 4);
    free_gc(&gc);

}
END_TEST

START_TEST(test_multi_normal_t)
{
    garbage_collector_t gc = init_gc();
    number_t number_a;
    number_t number_b;

    assert(make_number(&gc, 3, &number_a) == 0);
    assert(to_number(number_a) == 3);

    assert(make_number(&gc, 1, &number_b) == 0);
    assert(to_number(number_b) == 1);

    number_t div = divide(&gc, number_a, number_b);
    assert(to_number(div) == 3);
    free_gc(&gc);

}
END_TEST

Suite *div_suite(Suite *s)
{
    TCase *tc_pos;
    tc_pos = tcase_create("positives");

    tcase_add_test(tc_pos, test_multi_normal_f);
    tcase_add_test(tc_pos, test_multi_normal_s);
    tcase_add_test(tc_pos, test_multi_normal_t);

    suite_add_tcase(s, tc_pos);

    return s;
}