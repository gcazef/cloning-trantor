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

resource_t create_inventory(void)
{
    resource_t inventory;

    inventory.food = 10;
    inventory.linemate = 0;
    inventory.deraumere = 0;
    inventory.sibur = 0;
    inventory.mendiane = 0;
    inventory.phiras = 0;
    inventory.thystame = 0;
    return (inventory);
}

player_t create_player(char *team, cell_t *top_left, int height, int width)
{
    srand(time(NULL));
    player_t new_player;
    cell_t *pos = top_left;

    int posX = rand() % width;
    int posY = rand() % height;
    for (int i = 0; i < posX; i++)
        pos = pos->right;
    for (int i = 0; i < posY; i++)
        pos = pos->down;
    new_player.position = pos;
    new_player.position->players += 1;
    new_player.front_cell = pos->up;
    new_player.up = 1;
    new_player.down = 0;
    new_player.left = 0;
    new_player.right = 0;
    new_player.team = team;
    new_player.inventory = create_inventory();
    return (new_player);
}

int trantor(void)
{
    cell_t *top_left = create_grid(10, 10);
    player_t p = create_player("squad", top_left, 10, 10);
    char *lookStr = look(&p);

    printf("%s\n", lookStr);
    free(lookStr);
    destroy_grid(top_left);
    return (0);
}