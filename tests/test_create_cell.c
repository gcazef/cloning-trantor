/*
** EPITECH PROJECT, 2018
** test_create_cell
** File description:
** Tests for the create_cell function
*/

#include <criterion/criterion.h>
#include <stddef.h>
#include <stdlib.h>
#include "trantor_world.h"

Test(create_cell, cell_is_not_null)
{
    cell_t *new_cell = create_cell();

    cr_assert_neq(new_cell, NULL);
    free(new_cell);
}