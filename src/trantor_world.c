/*
** EPITECH PROJECT, 2018
** trantor_world
** File description:
** Functions for generating the trantor world
*/

#include <stdlib.h>
#include "trantor_elements.h"

cell_t *create_grid(int width, int height)
{
    cell_t *top_left;
    cell_t *top_right;
    cell_t *bottom_left;
    cell_t *bottom_right;
    cell_t *ptr;

    for (int i = 0; i < height; i++) {
        for (int j = 0; j < width; j++) {
            ptr = malloc(sizeof(cell_t));

        }
    }
}

int destroy_grid(cell_t *top_left)
{

}