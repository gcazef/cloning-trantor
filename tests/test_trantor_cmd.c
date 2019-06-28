/*
** EPITECH PROJECT, 2019
** USP_cloning_trantor_2018
** File description:
** test_trantor_cmd
*/

#include <criterion/criterion.h>
#include <criterion/redirect.h>
#include <unistd.h>
#include <string.h>
#include "trantor_cmd.h"

void redirect_all_std(void)
{
    cr_redirect_stdout();
    cr_redirect_stderr();
}

Test(send_resp, cmd_is_ok, .init=redirect_all_std)
{
    int retval = send_resp(1, 0);

    cr_assert_stdout_eq_str("ok\n");
    cr_assert_eq(retval, 0);
}

Test(send_resp, cmd_is_ko, .init=redirect_all_std)
{
    int retval = send_resp(1, 84);

    cr_assert_stdout_eq_str("ko\n");
    cr_assert_eq(retval, 0);
}

Test(send_resp, bad_file_descriptor)
{
    int retval = send_resp(-1, 0);

    cr_assert_eq(retval, -1);
}

Test(pop_buff, buffer_pops_data)
{
    char msg[BUFF_SIZE] = { 0 };
    char result[BUFF_SIZE] = { 0 };
    ring_buff_t buffer = { msg, 0, 5 };

    strcpy(buffer.buff, "look\n");
    pop_buff(&buffer, result);
    cr_assert_str_eq(buffer.buff, result);
    cr_assert_eq(buffer.writer, 5);
    cr_assert_eq(buffer.reader, 5);
}
