/*
** EPITECH PROJECT, 2018
** trantor_player
** File description:
** Functions related to player
*/

#include <time.h>
#include <stdlib.h>
#include <stddef.h>
#include <string.h>
#include <stdio.h>
#include "trantor_elements.h"
#include "trantor_resources.h"

player_t *create_player(cell_t *top_left, int height, int width)
{
    player_t *new_player = malloc(sizeof(player_t));
    cell_t *pos = top_left;
    int posX = rand() % width;
    int posY = rand() % height;
    
    for (int i = 0; i < posX; i++)
        pos = pos->right;
    for (int i = 0; i < posY; i++)
        pos = pos->down;
    new_player->position = pos;
    if (new_player->position->resources.food == 0)
        new_player->position->resources.food = 1;
    new_player->position->players += 1;
    new_player->front_cell = pos->up;
    new_player->look = 0;
    new_player->inventory = create_inventory();
    return (new_player);
}

void rotate_left(player_t *player)
{
    if (player->look == UP) {
        player->look = LEFT;
        player->front_cell = (player->position)->left;
        return;
    }
    if (player->look == DOWN) {
        player->look = RIGHT;
        player->front_cell = (player->position)->right;
        return;
    }
    if (player->look == LEFT) {
        player->look = DOWN;
        player->front_cell = (player->position)->down;
        return;
    }
    if (player->look == RIGHT) {
        player->look = UP;
        player->front_cell = (player->position)->up;
        return;
    }
}

void rotate_right(player_t *player)
{
    if (player->look == UP) {
        player->look = RIGHT;
        player->front_cell = (player->position)->right;
        return;
    }
    if (player->look == DOWN) {
        player->look = LEFT;
        player->front_cell = (player->position)->left;
        return;
    }
    if (player->look == LEFT) {
        player->look = UP;
        player->front_cell = (player->position)->up;
        return;
    }
    if (player->look == RIGHT) {
        player->look = DOWN;
        player->front_cell = (player->position)->down;
        return;
    }
}

void move_forward(player_t *player)
{
    player->position->players -= 1;
    player->position = player->front_cell;
    player->position->players += 1;
    if (player->look == UP)
        player->front_cell = (player->position)->up;
    if (player->look == RIGHT)
        player->front_cell = (player->position)->right;
    if (player->look == DOWN)
        player->front_cell = (player->position)->down;
    if (player->look == LEFT)
        player->front_cell = (player->position)->left;
}

void display_inventory(player_t *player, int sockfd)
{
    char *result = calloc(2, sizeof(char));
    char *temp;
    int len = 0;

    result[0] = '[';
    for (int i = 0; i < 7; i++) {
        temp = calloc((9 + strlen(resource_names[i])), sizeof(char));
        sprintf(temp, " %s %d", resource_names[i], (player->inventory).res[i]);
        len = strlen(result);
        result = realloc(result, (len + strlen(temp) + 2));
        result = strcat(result, temp);
        free(temp);
        if (i < 6)
            result = strcat(result, ",");
    }
    dprintf(sockfd, "%s ]\n", result);
    free(result);
}