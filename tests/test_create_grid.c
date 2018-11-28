/*
** EPITECH PROJECT, 2018
** test_create_grid
** File description:
** Tests for the create_grid function
*/

#include <criterion/criterion.h>
#include <stddef.h>
#include "trantor_world.h"

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
