/*
** EPITECH PROJECT, 2018
** trantor
** File description:
** Main functions of the trantor server
*/

#include <stddef.h>
#include "trantor_elements.h"
#include "trantor_world.h"
#include "trantor_server.h"

int trantor(void)
{
    grid_t grid = create_grid(10, 10);
    populate_grid(grid);
    //destroy_grid(grid);
    return (0);
}