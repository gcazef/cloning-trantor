/*
** EPITECH PROJECT, 2018
** trantor
** File description:
** Main functions of the trantor server
*/

#include <stddef.h>
#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#include "trantor_world.h"
#include "trantor_player.h"
#include "trantor_vision.h"
#include "trantor_resources.h"

int trantor(void)
{
    cell_t *top_left = create_grid(10, 10);
    player_t p = create_player("squad", top_left, 10, 10);

    printf("%s\n", look(&p));
    printf("%s\n", display_inventory(&p));
    drop_resource(&p, "linemate");
    printf("\n%s\n", look(&p));
    printf("%s\n", display_inventory(&p));
    destroy_grid(top_left);
    return (0);
}