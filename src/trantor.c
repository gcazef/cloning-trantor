/*
** EPITECH PROJECT, 2018
** trantor
** File description:
** Main functions of the trantor server
*/

#include <stddef.h>
#include <stdio.h>
#include "trantor_elements.h"
#include "trantor_world.h"

int trantor(void)
{
    cell_t *top_left = create_grid(10, 10);
    destroy_grid(top_left);
    return (0);
}