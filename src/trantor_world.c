/*
** EPITECH PROJECT, 2018
** trantor_world
** File description:
** Functions for generating the trantor world
*/

#include <stdlib.h>
#include "trantor_elements.h"

grid_t create_grid(int width, int height)
{
    grid_t grid;

    grid.width = width;
    grid.height = height;
    grid.cells = malloc(width * sizeof(cell_t *));
    for (int i = 0; i < height; i++) {
        grid.cells[i] = malloc(sizeof(cell_t *));
    }
    return (grid);
}

element_t *create_element(char *type, char identifier)
{
    element_t elem;

    return (&elem);
}

int populate_grid(grid_t grid)
{
    return (0);
}

int clean_cell(cell_t cell)
{
    return (0);
}

int destroy_grid(grid_t grid)
{
    for (int i = 0; i < grid.width; i++) {
        for (int j = 0; j < grid.height; j++) {
            clean_cell(grid.cells[i][j]);
        }
    }
    for (int i = 0; i < grid.width; i++) {
        free(grid.cells[i]);
    }
    free(grid.cells);
}