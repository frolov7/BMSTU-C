#include"../inc/check_main.h"
#include"../inc/matrix.h"

//Positives

START_TEST(test_change_nothing_to_add)
{
    matrix start;
    start.cols = 2;
    start.rows = 2;
    init_matrix(&start);
    ck_assert_int_eq(!start.values, 0); 

    start.values[0] = 1;
    start.values[1] = 2;
    start.values[2] = 3;
    start.values[3] = 4;

    matrix_inflate(&start, 2);
    ck_assert_int_eq(start.rows, start.cols); 

    matrix end;
    end.cols = 2;
    end.rows = 2;
    init_matrix(&end);
    ck_assert_int_eq(!end.values, 0); 
    
    end.values[0] = 1;
    end.values[1] = 2;
    end.values[2] = 3;
    end.values[3] = 4;

    int rc = compare_matrix(start, end);
    ck_assert_int_eq(rc, 0); 

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

    matrix_inflate(&start, 1);
    ck_assert_int_eq(start.rows, start.cols); 

    matrix end;
    end.cols = 1;
    end.rows = 1;
    init_matrix(&end);
    ck_assert_int_eq(!end.values, 0); 
    
    end.values[0] = 1;

    int compare_code = compare_matrix(start, end);
    ck_assert_int_eq(compare_code, 0); 

    free_matrix(&start);
    free_matrix(&end);
}
END_TEST

START_TEST(test_normal)
{
    matrix start;
    start.rows = 2;
    start.cols = 3;
    init_matrix(&start);
    ck_assert_int_eq(!start.values, 0); 

    start.values[0] = 4;
    start.values[1] = 7;
    start.values[2] = 1;
    start.values[3] = 3;
    start.values[4] = 2;
    start.values[5] = 7;


    matrix_inflate(&start, 3);
    ck_assert_int_eq(start.rows, start.cols); 

    matrix end;
    end.rows = 3;
    end.cols = 3;
    init_matrix(&end);
    ck_assert_int_eq(!end.values, 0); 
    
    end.values[0] = 4;
    end.values[1] = 7;
    end.values[2] = 1;
    end.values[3] = 3;
    end.values[4] = 2;
    end.values[5] = 7;
    end.values[6] = 3;
    end.values[7] = 3;
    end.values[8] = 2;

    int rc = compare_matrix(start, end);
    ck_assert_int_eq(rc, 0); 

    free_matrix(&start);
    free_matrix(&end);
}
END_TEST

Suite *add_suite(Suite *s)
{
    TCase *tc_pos;

    tc_pos = tcase_create("positives");

    tcase_add_test(tc_pos, test_change_nothing_to_add);
    tcase_add_test(tc_pos, test_parse_only_one_elem);
    tcase_add_test(tc_pos, test_normal);

    suite_add_tcase(s, tc_pos);

    return s;
}