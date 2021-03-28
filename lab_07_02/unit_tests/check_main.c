#include "../inc/check_main.h"

int compare_arrs(int *arr1, int len1, int *arr2, int len2)
{
    int error = OK;
    if (len1 == len2)
    {
        for (int ind = 0; ind < len1; ind++)
        {
            if (arr1[ind] == arr2[ind])
                error = OK;

            else
                error = ERROR;
        }
    }
    else
        error = ERROR;

    return error;
}

Suite *tests_suite()
{
    Suite *s = suite_create("tests");

    s = sort_suite(s);
    s = key_suite(s);

    return s;
}


int main(void)
{
    Suite *s = tests_suite();
    SRunner *runner = srunner_create(s);
    srunner_run_all(runner, CK_VERBOSE);
    int errors = srunner_ntests_failed(runner);
    srunner_free(runner);
    return errors;
}
