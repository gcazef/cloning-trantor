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

Test(destroy_grid, grid_exists)
{
    cell_t *grid = create_grid(3, 3);

    cr_assert_eq(destroy_grid(grid), 0);
}