#include "../inc/check_main.h"
#include "../inc/work_arr.h"

START_TEST(test_filter_normal)
{
    int arr1_b[] = {1, 2, 3, 4, 5, 6, -7};
    int *arr1_e = arr1_b + 7;

    int *pb_dst = NULL;
    int *pe_dst = NULL;

    int arr2[] = {1, 2, 3, 4, 5, 6};
    int len2 = 6;

    key(arr1_b, arr1_e, &pb_dst, &pe_dst);

    int len1 = pe_dst - pb_dst;

    int rc = compare_arrs(pb_dst, len1, arr2, len2);

    ck_assert_int_eq(rc, OK);

    free(pb_dst);
}
END_TEST


START_TEST(test_filter_third_neg)
{
    int arr1_b[] = {2, 5, -3, 1, -5, -6, -8};
    int *arr1_e = arr1_b + 7;

    int *pb_dst = NULL;
    int *pe_dst = NULL;

    int arr2[] = {2, 5};
    int len2 = 2;

    key(arr1_b, arr1_e, &pb_dst, &pe_dst);

    int len1 = pe_dst - pb_dst;

    int rc = compare_arrs(pb_dst, len1, arr2, len2);

    ck_assert_int_eq(rc, OK);

    free(pb_dst);
}
END_TEST


START_TEST(test_filter_several_negatives)
{
    int arr1_b[] = {5, 1, 7, -1, 3, -8, 9};
    int *arr1_e = arr1_b + 7;

    int *pb_dst = NULL;
    int *pe_dst = NULL;

    int arr2[] = {5, 1, 7};
    int len2 = 3;

    key(arr1_b, arr1_e, &pb_dst, &pe_dst);

    int len1 = pe_dst - pb_dst;

    int rc = compare_arrs(pb_dst, len1, arr2, len2);

    ck_assert_int_eq(rc, OK);

    free(pb_dst);
}
END_TEST

//Negatives

START_TEST(test_filter_all_neg)
{
    int arr1_b[] = {-7, -7, -7, -7, -7};
    int *arr1_e = arr1_b + 5;

    int *pb_dst = NULL;
    int *pe_dst = NULL;

    int rc = key(arr1_b, arr1_e, &pb_dst, &pe_dst);

    ck_assert_int_eq(rc, ERROR);

    free(pb_dst);
}
END_TEST

START_TEST(test_filter_first_neg)
{
    int arr1_b[] = {-7, 1, 3, 8, 6};
    int *arr1_e = arr1_b + 5;

    int *pb_dst = NULL;
    int *pe_dst = NULL;

    int rc = key(arr1_b, arr1_e, &pb_dst, &pe_dst);

    ck_assert_int_eq(rc, ERROR);

    free(pb_dst);
}
END_TEST


START_TEST(test_filter_only_one_elem_in_array)
{
    int arr1_b[] = {-2};
    int *arr1_e = arr1_b + 1;

    int *pb_dst = NULL;
    int *pe_dst = NULL;

    int rc = key(arr1_b, arr1_e, &pb_dst, &pe_dst);

    ck_assert_int_eq(rc, ERROR);

    free(pb_dst);
}
END_TEST


START_TEST(test_filter_unright_pointers)
{
    int arr1_b[] = {7, 5, 11, 30, 25};
    int *arr1_e = arr1_b - 1;

    int *pb_dst = NULL;
    int *pe_dst = NULL;

    int rc = key(arr1_b, arr1_e, &pb_dst, &pe_dst);

    ck_assert_int_eq(rc, ERROR);

    free(pb_dst);
}
END_TEST


Suite *key_suite(Suite *s)
{
    TCase *tc_pos, *tc_neg;

    tc_pos = tcase_create("positives");

    tcase_add_test(tc_pos, test_filter_normal);
    tcase_add_test(tc_pos, test_filter_third_neg);
    tcase_add_test(tc_pos, test_filter_several_negatives);

    suite_add_tcase(s, tc_pos);

    tc_neg = tcase_create("negatives");

    tcase_add_test(tc_neg, test_filter_all_neg);
    tcase_add_test(tc_neg, test_filter_first_neg);
    tcase_add_test(tc_neg, test_filter_only_one_elem_in_array);
    tcase_add_test(tc_neg, test_filter_unright_pointers);

    suite_add_tcase(s, tc_neg);

    return s;
}
