/*
** EPITECH PROJECT, 2018
** trantor_world
** File description:
** Header for trantor_world generation
*/

#ifndef TRANTOR_WORLD_H_
#define TRANTOR_WORLD_H_

#include "trantor_elements.h"

cell_t *create_cell(void);
void link_lines(cell_t *prev, cell_t *curr);
void link_borders(cell_t *top_left);
cell_t *create_grid(int width, int height);
int destroy_grid(cell_t *top_left);
resource_t generate_resource(void);

#endif /* !TRANTOR_WORLD_H_ */
