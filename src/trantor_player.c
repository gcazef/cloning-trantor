/*
** EPITECH PROJECT, 2018
** trantor_player
** File description:
** Functions related to player
*/

#include <stdlib.h>
#include <string.h>
#include "trantor_elements.h"
#include "trantor_resources.h"

int rotate_left(player_t *player)
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
    return (0);
}

int rotate_right(player_t *player)
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
    return (0);
}

int move_forward(player_t *player)
{
    player->position = player->front_cell;
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

char *look(player_t *player)
{
    char *result;

    result = look_cell(player->position);    
    return (result);
}

/*
char *display_inventory(player_t *player)
{

    return (0);
}
*/