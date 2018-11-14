/*
** EPITECH PROJECT, 2018
** trantor_world
** File description:
** Header for trantor_world generation
*/

#ifndef TRANTOR_WORLD_H_
#define TRANTOR_WORLD_H_

#include "trantor_elements.h"

grid_t create_grid(int width, int height);
int populate_grid(grid_t grid);
element_t *create_element(char *type, char identifier);
int clean_cell(cell_t cell);
int destroy_grid(grid_t grid);

#endif /* !TRANTOR_WORLD_H_ */
