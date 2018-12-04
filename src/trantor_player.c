/*
** EPITECH PROJECT, 2018
** trantor_player
** File description:
** Functions related to player
*/

#include <time.h>
#include <stdlib.h>
#include <stddef.h>
#include "trantor_elements.h"
#include "trantor_vision.h"

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

void rotate_left(player_t *player)
{
    if (player->up == 1) {
        player->up = 0;
        player->left = 1;
        player->front_cell = (player->position)->left;
    }
    if (player->down == 1) {
        player->down = 0;
        player->right = 1;
        player->front_cell = (player->position)->right;
    }
    if (player->left == 1) {
        player->left = 0;
        player->down = 1;
        player->front_cell = (player->position)->down;
    }
    if (player->right == 1) {
        player->right = 0;
        player->up = 1;
        player->front_cell = (player->position)->up;
    }
}

void rotate_right(player_t *player)
{
    if (player->up == 1) {
        player->up = 0;
        player->right = 1;
        player->front_cell = (player->position)->right;
    }
    if (player->down == 1) {
        player->down = 0;
        player->left = 1;
        player->front_cell = (player->position)->left;
    }
    if (player->left == 1) {
        player->left = 0;
        player->up = 1;
        player->front_cell = (player->position)->up;
    }
    if (player->right == 1) {
        player->right = 0;
        player->down = 1;
        player->front_cell = (player->position)->down;
    }
}

int move_forward(player_t *player)
{
    player->position->players -= 1;
    player->position = player->front_cell;
    player->position->players += 1;
    if (player->up == 1)
        player->front_cell = (player->position)->up;
    if (player->down == 1)
        player->front_cell = (player->position)->down;
    if (player->left == 1)
        player->front_cell = (player->position)->left;
    if (player->right == 1)
        player->front_cell = (player->position)->right;
    return (0);
}



/*
char *display_inventory(player_t *player)
{

    return (0);
}
*/