#include "../inc/check_main.h"
#include "../inc/work_arr.h"

START_TEST(test_sort_normal)
{
    int arr1[] = {45, 23, 25, 1, 6, 84, 20};
    int len1 = 7;

    int arr2[] = {1, 6, 20, 23, 25, 45, 84};
    int len2 = 7;

    mysort(arr1, len1, sizeof(int), compare_int);

    int rc = compare_arrs(arr1, len1, arr2, len2);

    ck_assert_int_eq(rc, OK);
}
END_TEST


START_TEST(test_sort_reverse)
{
    int arr1[] = {200, 100, 50, 45, 30, 5, 1};
    int len1 = 7;

    int arr2[] = {1, 5, 30, 45, 50, 100, 200};
    int len2 = 7;

    mysort(arr1, len1, sizeof(int), compare_int);

    int rc = compare_arrs(arr1, len1, arr2, len2);

    ck_assert_int_eq(rc, OK);
}
END_TEST


START_TEST(test_sort_sorted)
{
    int arr1[] = {22, 25, 42, 48, 63, 250, 680, 712};
    int len1 = 8;

    int arr2[] = {22, 25, 42, 48, 63, 250, 680, 712};
    int len2 = 8;

    mysort(arr1, len1, sizeof(int), compare_int);

    int rc = compare_arrs(arr1, len1, arr2, len2);

    ck_assert_int_eq(rc, OK);
}
END_TEST


START_TEST(test_sort_one_elem)
{
    int arr1[] = {15};
    int len1 = 1;

    int arr2[] = {15};
    int len2 = 1;

    mysort(arr1, len1, sizeof(int), compare_int);

    int rc = compare_arrs(arr1, len1, arr2, len2);

    ck_assert_int_eq(rc, OK);
}
END_TEST


START_TEST(test_sort_two_elems)
{
    int arr1[] = {15, 2};
    int len1 = 2;

    int arr2[] = {2, 15};
    int len2 = 2;

    mysort(arr1, len1, sizeof(int), compare_int);

    int rc = compare_arrs(arr1, len1, arr2, len2);

    ck_assert_int_eq(rc, OK);
}
END_TEST

START_TEST(test_sort_equal_elems)
{
    int arr1[] = {12, 12, 12, 12, 12};
    int len1 = 5;

    int arr2[] = {12, 12, 12, 12, 12};
    int len2 = 5;

    mysort(arr1, len1, sizeof(int), compare_int);

    int rc = compare_arrs(arr1, len1, arr2, len2);

    ck_assert_int_eq(rc, OK);
}
END_TEST


Suite *sort_suite(Suite *s)
{
    TCase *tc_pos;

    tc_pos = tcase_create("positives");

    tcase_add_test(tc_pos, test_sort_normal);
    tcase_add_test(tc_pos, test_sort_reverse);
    tcase_add_test(tc_pos, test_sort_sorted);
    tcase_add_test(tc_pos, test_sort_one_elem);
    tcase_add_test(tc_pos, test_sort_two_elems);
    tcase_add_test(tc_pos, test_sort_equal_elems);

    suite_add_tcase(s, tc_pos);

    return s;
}
