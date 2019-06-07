/*
** EPITECH PROJECT, 2019
** USP_cloning_trantor_2018
** File description:
** test_trantor_world
*/

#include <criterion/criterion.h>
#include <stddef.h>
#include <stdlib.h>
#include "trantor_world.h"

// create_cell
Test(create_cell, cell_is_not_null)
{
    cell_t *new_cell = create_cell();

    cr_assert_neq(new_cell, NULL);
    free(new_cell);
}

// create_grid
Test(create_grid, null_size_values)
{
    cell_t *grid = create_grid(0, 0);

    cr_assert_eq(grid, NULL);
}

Test(create_grid, negative_size_values)
{
    cell_t *grid = create_grid(-1, -1);

    cr_assert_eq(grid, NULL);
}

Test(create_grid, positive_size_values)
{
    cell_t *grid = create_grid(3, 3);

    cr_assert_eq(grid, (grid->up->left->down->right));
    destroy_grid(grid);
}

// destroy_grid
Test(destroy_grid, grid_exists)
{
    cell_t *grid = create_grid(3, 3);

    cr_assert_eq(destroy_grid(grid), 0);
}

// link_lines
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
