#include"../inc/check_main.h"
#include <assert.h>

//Positives
START_TEST(test_multi_normal_f)
{
    garbage_collector_t gc = init_gc();
    number_t number_a;
    number_t number_b;

    assert(make_number(&gc, 5, &number_a) == 0);
    assert(to_number(number_a) == 5);

    assert(make_number(&gc, 4, &number_b) == 0);
    assert(to_number(number_b) == 4);

    number_t mul = multiply(number_a, number_b);
    assert(to_number(mul) == 20);
    free_gc(&gc);

}
END_TEST

START_TEST(test_multi_normal_s)
{
    garbage_collector_t gc = init_gc();
    number_t number_a;
    number_t number_b;

    assert(make_number(&gc, 10, &number_a) == 0);
    assert(to_number(number_a) == 10);

    assert(make_number(&gc, 5, &number_b) == 0);
    assert(to_number(number_b) == 5);

    number_t mul = multiply(number_a, number_b);
    assert(to_number(mul) == 50);
    free_gc(&gc);

}
END_TEST

Suite *mult_suite(Suite *s)
{
    TCase *tc_pos;
    tc_pos = tcase_create("positives");

    tcase_add_test(tc_pos, test_multi_normal_f);
    tcase_add_test(tc_pos, test_multi_normal_s);

    suite_add_tcase(s, tc_pos);

    return s;
}