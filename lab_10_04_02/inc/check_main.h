#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <check.h>
#include"../inc/io.h"
#include"../inc/funcs.h"
#include"../inc/garbage_collector.h"

#ifndef CHECK_MAIN_H
#define CHECK_MAIN_H

Suite *square_suite(Suite *s);
Suite *mult_suite(Suite *s);
Suite *div_suite(Suite *s);

#endif