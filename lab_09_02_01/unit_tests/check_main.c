#include "../inc/check_main.h"

int main(void)
{
    int mistakes  = 0;
    Suite *s = check_read_func();;
    SRunner *runner = srunner_create(s);;
    srunner_run_all(runner, CK_VERBOSE);
    mistakes  = srunner_ntests_failed(runner);
    srunner_free(runner);
    return mistakes  == 0 ? EXIT_SUCCESS : EXIT_FAILURE;;
}