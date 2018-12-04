/*
** EPITECH PROJECT, 2018
** trantor_player
** File description:
** Functions related to player
*/

#include "trantor_elements.h"
#include "trantor_vision.h"

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