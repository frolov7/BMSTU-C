#include"../inc/check_main.h"
#include"../inc/matrix.h"

//Positives
START_TEST(test_p0)
{
    matrix start_a;
    start_a.rows = 2;
    start_a.cols = 2;
    init_matrix(&start_a);
    ck_assert_int_eq(!start_a.values, 0); 

    start_a.values[0] = 1;
    start_a.values[1] = 2;
    start_a.values[2] = 3;
    start_a.values[3] = 4;

    matrix start_b;
    start_b.rows = 2;
    start_b.cols = 2;
    init_matrix(&start_b);
    ck_assert_int_eq(!start_b.values, 0); 

    start_b.values[0] = 1;
    start_b.values[1] = 2;
    start_b.values[2] = 3;
    start_b.values[3] = 4;


    matrix expected_result;
    expected_result.rows = 2;
    expected_result.cols = 2;
    init_matrix(&expected_result);
    ck_assert_int_eq(!expected_result.values, 0); 

    expected_result.values[0] = 7;
    expected_result.values[1] = 10;
    expected_result.values[2] = 15;
    expected_result.values[3] = 22;

    matrix result;
    result.rows = 2;
    result.cols = 2;
    init_matrix(&result);
    ck_assert_int_eq(!result.values, 0); 

    multiply_matrix(&start_a, &start_b, &result);

    ck_assert_int_eq(compare_matrix(expected_result, result), 0);

    free(start_a.values);
    free(start_b.values);
    free(result.values);
    free(expected_result.values);
}
END_TEST

START_TEST(test_p1)
{
    matrix start_a;
    start_a.rows = 2;
    start_a.cols = 2;
    init_matrix(&start_a);
    ck_assert_int_eq(!start_a.values, 0); 

    start_a.values[0] = 0;
    start_a.values[1] = 0;
    start_a.values[2] = 0;
    start_a.values[3] = 0;

    matrix start_b;
    start_b.rows = 2;
    start_b.cols = 2;
    init_matrix(&start_b);
    ck_assert_int_eq(!start_b.values, 0); 

    start_b.values[0] = 0;
    start_b.values[1] = 0;
    start_b.values[2] = 0;
    start_b.values[3] = 0;

    matrix expected_result;
    expected_result.rows = 2;
    expected_result.cols = 2;
    init_matrix(&expected_result);
    ck_assert_int_eq(!expected_result.values, 0); 

    expected_result.values[0] = 0;
    expected_result.values[1] = 0;
    expected_result.values[2] = 0;
    expected_result.values[3] = 0;

    matrix result;
    result.rows = 2;
    result.cols = 2;
    init_matrix(&result);
    ck_assert_int_eq(!result.values, 0); 

    multiply_matrix(&start_a, &start_b, &result);

    ck_assert_int_eq(compare_matrix(expected_result, result), 0);

    free(start_a.values);
    free(start_b.values);
    free(result.values);
    free(expected_result.values);
}
END_TEST
Suite *grade_suite(Suite *s)
{
    TCase *tc_pos;
    tc_pos = tcase_create("positives");

    tcase_add_test(tc_pos, test_p0);
    tcase_add_test(tc_pos, test_p1);

    suite_add_tcase(s, tc_pos);

    return s;
}