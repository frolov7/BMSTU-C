#include "../inc/check_main.h"
#include"../inc/func.h"

START_TEST(test_ok)
{
    FILE *in_file = fopen("./func_tests/pos/pos_08_in.txt", "r");
    ck_assert_ptr_nonnull(in_file);

    int number_of_objs;
    product_t *product = NULL;
    int rc = read_products(in_file, &product, &number_of_objs);

    ck_assert_int_ne(number_of_objs, 0);
    ck_assert_ptr_nonnull(product);
    ck_assert_int_eq(rc, 0);
    free_products(product, number_of_objs);
    if (in_file)
        fclose(in_file);
}
END_TEST

Suite *check_read_func(void)
{
    Suite *s;
    TCase *tc_pos;

    s = suite_create("Read file");
    
    tc_pos = tcase_create("positives");
    tcase_add_test(tc_pos, test_ok);
    
    suite_add_tcase(s, tc_pos);

    return s;
}