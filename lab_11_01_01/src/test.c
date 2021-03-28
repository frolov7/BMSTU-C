#include <stdio.h>
#include <string.h>
#include <limits.h>
#include "../inc/my_string.h"

#define OK 0
#define ERROR 1
#define SIZEBUF 255

int compare_snprintf(const int lib_out, const int my_out, char *lib_str, char *my_str)
{
    int rc = OK;
    if (lib_out != my_out || strcmp(lib_str, my_str))
        rc = ERROR; 

    return rc;
}

void test_c_specf()
{
    int error = 0;

    char lib_buf[SIZEBUF];
    char my_buf[SIZEBUF];

    int lib_result = snprintf(lib_buf, 30, "%c", 'c');
    int my_result = my_snprintf(my_buf, 30, "%c", 'c');

    error += compare_snprintf(lib_result, my_result, lib_buf, my_buf);

    printf("%s: %s\n", __func__, error ? "FAILED" : "OK");
}

void test_free()
{
    int error = 0;

    char lib_buf[SIZEBUF];
    char my_buf[SIZEBUF];

    int lib_result = snprintf(lib_buf, 30, "%c", ' ');
    int my_result = my_snprintf(my_buf, 30, "%c", ' ');

    error += compare_snprintf(lib_result, my_result, lib_buf, my_buf);

    printf("%s: %s\n", __func__, error ? "FAILED" : "OK");
}

void test_s_specf()
{
    int error = 0;

    char lib_buf[SIZEBUF];
    char my_buf[SIZEBUF];

    int lib_result = snprintf(lib_buf, 8, "%s", "room");
    int my_result = my_snprintf(my_buf, 8, "%s", "room");

    error += compare_snprintf(lib_result, my_result, lib_buf, my_buf);

    printf("%s: %s\n", __func__, error ? "FAILED" : "OK");
}

void test_d_specf()
{
    int error = 0;

    char lib_buf[SIZEBUF];
    char my_buf[SIZEBUF];

    int lib_result = snprintf(lib_buf, 85, "%d", 256);
    int my_result = my_snprintf(my_buf, 85, "%d", 256);

    error += compare_snprintf(lib_result, my_result, lib_buf, my_buf);

    printf("%s: %s\n", __func__, error ? "FAILED" : "OK");
}

void test_d_zero_specf()
{
    int error = 0;

    char lib_buf[SIZEBUF];
    char my_buf[SIZEBUF];

    int lib_result = snprintf(lib_buf, 85, "%d", 0);
    int my_result = my_snprintf(my_buf, 85, "%d", 0);

    error += compare_snprintf(lib_result, my_result, lib_buf, my_buf);

    printf("%s: %s\n", __func__, error ? "FAILED" : "OK");
}

void test_d_max_specf()
{
    int error = 0;

    char lib_buf[SIZEBUF];
    char my_buf[SIZEBUF];

    int lib_result = snprintf(lib_buf, 85, "%d", INT_MAX);
    int my_result = my_snprintf(my_buf, 85, "%d", INT_MAX);

    error += compare_snprintf(lib_result, my_result, lib_buf, my_buf);

    printf("%s: %s\n", __func__, error ? "FAILED" : "OK");
}

void test_ld_max_specf()
{
    int error = 0;

    char lib_buf[SIZEBUF];
    char my_buf[SIZEBUF];

    int lib_result = snprintf(lib_buf, 90, "%ld", LONG_MAX);
    int my_result = my_snprintf(my_buf, 90, "%ld", LONG_MAX);

    error += compare_snprintf(lib_result, my_result, lib_buf, my_buf);

    printf("%s: %s\n", __func__, error ? "FAILED" : "OK");
}

int main()
{
    test_c_specf();
    test_s_specf();
    test_d_specf();
    test_d_zero_specf();
    test_d_max_specf();
    test_free();
    test_ld_max_specf();

    return OK;
}