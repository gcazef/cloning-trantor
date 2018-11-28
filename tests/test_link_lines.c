/*
** EPITECH PROJECT, 2018
** test_link_lines
** File description:
** Tests for the link_lines function
*/

#include <criterion/criterion.h>
#include <stddef.h>
#include <stdlib.h>
#include "trantor_world.h"

Test(link_lines, lines_are_linked)
{
    cell_t *curr = create_cell();
    cell_t *prev = create_cell();

    link_lines(prev, curr);
    cr_assert_eq((curr->down), prev);
    cr_assert_eq((prev->up), curr);
    free(curr);
    free(prev);
}

Test(link_lines, line_is_null)
{
    cell_t *prev = create_cell();

    link_lines(prev, NULL);
    cr_assert_eq((prev->up), NULL);
    free(prev);
}