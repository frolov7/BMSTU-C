#include <check.h>
#include <stdio.h>
#include <string.h>
#include <stdint.h>
#include <limits.h>
#include "../inc/array_utils.h"



START_TEST(perform_shift_1)
{
	int src[] = { 0, 1, 2, 3, 4, 5, 6, 7, 8, 9 };
    const size_t len = sizeof(src) / sizeof(int);
    const size_t shift = 1;

    cycle_shift(src, len, shift);

    for (size_t i = 0; i < len; i++)
        ck_assert_int_eq(src[i], (i + shift) % len);
}
END_TEST
START_TEST(perform_shift_2)
{
	int src[] = { 0, 1, 2, 3, 4, 5, 6, 7, 8, 9 };
    const size_t len = sizeof(src) / sizeof(int);
    const size_t shift = 2;

    cycle_shift(src, len, shift);

    for (size_t i = 0; i < len; i++)
        ck_assert_int_eq(src[i], (i + shift) % len);
}
END_TEST
START_TEST(perform_shift_3)
{
	int src[] = { 0, 1, 2, 3, 4, 5, 6, 7, 8, 9 };
    const size_t len = sizeof(src) / sizeof(int);
    const size_t shift = 3;

    cycle_shift(src, len, shift);

    for (size_t i = 0; i < len; i++)
        ck_assert_int_eq(src[i], (i + shift) % len);
}
END_TEST
START_TEST(perform_shift_9)
{
	int src[] = { 0, 1, 2, 3, 4, 5, 6, 7, 8, 9 };
    const size_t len = sizeof(src) / sizeof(int);
    const size_t shift = 3;

    cycle_shift(src, len, shift);

    for (size_t i = 0; i < len; i++)
        ck_assert_int_eq(src[i], (i + shift) % len);
}
END_TEST
START_TEST(perform_shift_10)
{
	int src[] = { 0, 1, 2, 3, 4, 5, 6, 7, 8, 9 };
    const size_t len = sizeof(src) / sizeof(int);
    const size_t shift = 3;

    cycle_shift(src, len, shift);

    for (size_t i = 0; i < len; i++)
        ck_assert_int_eq(src[i], (i + shift) % len);
}
END_TEST
START_TEST(perform_shift_12)
{
	int src[] = { 0, 1, 2, 3, 4, 5, 6, 7, 8, 9 };
    const size_t len = sizeof(src) / sizeof(int);
    const size_t shift = 3;

    cycle_shift(src, len, shift);

    for (size_t i = 0; i < len; i++)
        ck_assert_int_eq(src[i], (i + shift) % len);
}
END_TEST

START_TEST(perform_copy_10)
{
	int src[] = { 0, 1, 2, 3, 4, 5, 6, 7, 8, 9 };
    const size_t len = sizeof(src) / sizeof(int);

    size_t res_len = copy_squares(src, len, NULL);
    ck_assert_int_eq(res_len, 4);

    int dst[4];
    copy_squares(src, len, dst);
    ck_assert_int_eq(dst[0], 0);
    ck_assert_int_eq(dst[1], 1);
    ck_assert_int_eq(dst[2], 4);
    ck_assert_int_eq(dst[3], 9);
}
END_TEST
START_TEST(perform_copy_20)
{
	int src[] = { 0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16, 17, 18, 19 };
    const size_t len = sizeof(src) / sizeof(int);

    size_t res_len = copy_squares(src, len, NULL);
    ck_assert_int_eq(res_len, 5);

    int dst[4];
    copy_squares(src, len, dst);
    ck_assert_int_eq(dst[0], 0);
    ck_assert_int_eq(dst[1], 1);
    ck_assert_int_eq(dst[2], 4);
    ck_assert_int_eq(dst[3], 9);
    ck_assert_int_eq(dst[4], 16);
}
END_TEST

Suite *make_suite()
{
	Suite *suite = suite_create("array_utils");

	TCase *cycle_shift_func = tcase_create("cycle_shift");
	tcase_add_test(cycle_shift_func, perform_shift_1);
	tcase_add_test(cycle_shift_func, perform_shift_2);
	tcase_add_test(cycle_shift_func, perform_shift_3);
	tcase_add_test(cycle_shift_func, perform_shift_9);
	tcase_add_test(cycle_shift_func, perform_shift_10);
	tcase_add_test(cycle_shift_func, perform_shift_12);
	suite_add_tcase(suite, cycle_shift_func);
    
	TCase *copy_squares_func = tcase_create("copy_squares");
	tcase_add_test(copy_squares_func, perform_copy_10);
	tcase_add_test(copy_squares_func, perform_copy_20);
	suite_add_tcase(suite, copy_squares_func);

	return suite;
}
int main()
{
	Suite *suite = make_suite();
	SRunner *runner = srunner_create(suite);

	srunner_run_all(runner, CK_VERBOSE);
	int success = srunner_ntests_failed(runner);
	srunner_free(runner);
	
	return success;
}