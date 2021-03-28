#include"../inc/check_main.h"
#include"../inc/matrix.h"

//Positives

START_TEST(test_for_matrix_3_2)
{
    matrix start;
    start.rows = 3;
    start.cols = 2;
    init_matrix(&start);
    ck_assert_int_eq(!start.values, 0); 

    start.values[0] = 5;
    start.values[1] = 6;
    start.values[2] = 7;
    start.values[3] = 5;
    start.values[4] = 7;
    start.values[5] = 1;

    matrix_to_square(&start);
    ck_assert_int_eq(start.rows, start.cols); 

    matrix end;
    end.rows = 2;
    end.cols = 2;
    init_matrix(&end);
    ck_assert_int_eq(!end.values, 0); 
    
    end.values[0] = 5;
    end.values[1] = 6;
    end.values[2] = 7;
    end.values[3] = 5;

    int compare_code = compare_matrix(start, end);
    ck_assert_int_eq(compare_code, 0); 

    free_matrix(&start);
    free_matrix(&end);
}
END_TEST

START_TEST(test_for_matrix_2_3)
{
    matrix start;
    start.rows = 2;
    start.cols = 3;
    init_matrix(&start);
    ck_assert_int_eq(!start.values, 0); 

    start.values[0] = 1;
    start.values[1] = 2;
    start.values[2] = 3;
    start.values[3] = 4;
    start.values[4] = 5;
    start.values[5] = 6;

    matrix_to_square(&start);
    ck_assert_int_eq(start.rows, start.cols); 

    matrix end;
    end.rows = 2;
    end.cols = 2;
    init_matrix(&end);
    ck_assert_int_eq(!end.values, 0); 
    
    end.values[0] = 2;
    end.values[1] = 3;
    end.values[2] = 5;
    end.values[3] = 6;

    int compare_code = compare_matrix(start, end);
    ck_assert_int_eq(compare_code, 0); 

    free_matrix(&start);
    free_matrix(&end);
}
END_TEST

START_TEST(test_parse_nothinng_to_delete)
{
    matrix start;
    start.rows = 2;
    start.cols = 2;
    init_matrix(&start);
    ck_assert_int_eq(!start.values, 0); 

    start.values[0] = 1;
    start.values[1] = 2;
    start.values[2] = 3;
    start.values[3] = 4;

    matrix_to_square(&start);
    ck_assert_int_eq(start.rows, start.cols); 

    matrix end;
    end.rows = 2;
    end.cols = 2;
    init_matrix(&end);
    ck_assert_int_eq(!end.values, 0); 
    
    end.values[0] = 1;
    end.values[1] = 2;
    end.values[2] = 3;
    end.values[3] = 4;

    int compare_code = compare_matrix(start, end);
    ck_assert_int_eq(compare_code, 0); 

    free_matrix(&start);
    free_matrix(&end);
}
END_TEST

START_TEST(test_parse_only_one_elem)
{
    matrix start;
    start.rows = 1;
    start.cols = 1;
    init_matrix(&start);
    ck_assert_int_eq(!start.values, 0); 

    start.values[0] = 1;

    matrix_to_square(&start);
    ck_assert_int_eq(start.rows, start.cols); 

    matrix end;
    end.rows = 1;
    end.cols = 1;
    init_matrix(&end);
    ck_assert_int_eq(!end.values, 0); 
    
    end.values[0] = 1;

    int compare_code = compare_matrix(start, end);
    ck_assert_int_eq(compare_code, 0); 

    free_matrix(&start);
    free_matrix(&end);
}
END_TEST

Suite *delete_suite(Suite *s)
{
    TCase *tc_pos;
    tc_pos = tcase_create("positives");

    tcase_add_test(tc_pos, test_for_matrix_3_2);
    tcase_add_test(tc_pos, test_for_matrix_2_3);
    tcase_add_test(tc_pos, test_parse_nothinng_to_delete);
    tcase_add_test(tc_pos, test_parse_only_one_elem);

    suite_add_tcase(s, tc_pos);

    return s;
}