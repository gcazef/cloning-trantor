/*
** EPITECH PROJECT, 2019
** USP_cloning_trantor_2018
** File description:
** test_trantor_buff
*/

#include <criterion/criterion.h>
#include <string.h>
#include "trantor_buff.h"

#include <stdio.h>

Test(push_buff, single_char_push)
{
    char msg[BUFF_SIZE] = { 0 };
    ring_buff_t buffer = { msg, 0, 0 };

    push_buff(&buffer, 'a');
    cr_assert_str_eq(buffer.buff, "a");
    cr_assert_eq(strlen(buffer.buff), 1);
    cr_assert_eq(buffer.writer, 1);
    cr_assert_eq(buffer.reader, 0);
    push_buff(&buffer, 'b');
    cr_assert_str_eq(buffer.buff, "ab");
    cr_assert_eq(strlen(buffer.buff), 2);
    cr_assert_eq(buffer.writer, 2);
    cr_assert_eq(buffer.reader, 0);
}

Test(push_buff, push_string)
{
    char msg[BUFF_SIZE] = { 0 };
    char *input = "input";
    ring_buff_t buffer = { msg, 0, 0 };
    int i = 0;

    while (input[i] != 0) {
        push_buff(&buffer, input[i]);
        i++;
    }
    cr_assert_str_eq(buffer.buff, "input");
    cr_assert_eq(strlen(buffer.buff), strlen(input));
    cr_assert_eq(buffer.writer, strlen(input));
    cr_assert_eq(buffer.reader, 0);
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
