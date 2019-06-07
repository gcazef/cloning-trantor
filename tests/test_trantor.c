/*
** EPITECH PROJECT, 2019
** USP_cloning_trantor_2018
** File description:
** test_trantor
*/

#include <criterion/criterion.h>
#include "trantor.h"

// check_args
Test(check_args, bad_port)
{
    args_t args;
    int result;

    args.height = 10;
    args.width = 10;
    args.port = 666666;
    result = check_args(&args);
    cr_assert_eq(result, -1);
    args.port = -1;
    cr_assert_eq(result, -1);
}

Test(check_args, bad_dimensions)
{
    args_t args;
    int result;

    args.port = 4242;
    args.height = 0;
    args.width = 0;
    result = check_args(&args);
    cr_assert_eq(result, -1);
    args.height = -10;
    args.width = 10;
    cr_assert_eq(result, -1);
    args.height = 10;
    args.width = -10;
    cr_assert_eq(result, -1);
    args.height = -10;
    args.width = -10;
    cr_assert_eq(result, -1);
}

Test(check_args, good_dimensions)
{
    args_t args;
    int result;

    args.port = 4242;
    args.height = 10;
    args.width = 10;
    result = check_args(&args);
    cr_assert_eq(result, 0);
}
