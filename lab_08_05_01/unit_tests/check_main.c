#include "../inc/check_main.h"

int compare_matrix(matrix mat1, matrix mat2)
{
    if (mat1.rows != mat2.rows)
        return -1;

    if (mat1.cols != mat2.cols)
        return -1;

    for (int i = 0; i < mat1.rows * mat1.cols; i++)
        if (mat1.values[i] != mat2.values[i])
            return -1;

    return 0;
}

Suite *tests_suite()
{
    Suite *s = suite_create("tests");

    s = add_suite(s);
    s = delete_suite(s);
    s = grade_suite(s);

    return s;
}


int main(void)
{
    Suite *s = tests_suite();
    SRunner *runner = srunner_create(s);
    srunner_run_all(runner, CK_VERBOSE);
    int mistakes = srunner_ntests_failed(runner);
    srunner_free(runner);

    return mistakes;
}