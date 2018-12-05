/*
** EPITECH PROJECT, 2018
** trantor_vision
** File description:
** Functions for vision handling
*/

#include <stdlib.h>
#include <string.h>
#include "trantor_elements.h"
#include "trantor_resources.h"

char *look_up(player_t *player)
{
    char *result = calloc(2, sizeof(char));
    char *cell_res;
    cell_t *curr = player->position;
    int len = 0;

    result[0] = '[';
    for (int i = 0; i < 4; i++) {
        cell_res = display_resources(curr);
        len = strlen(result);
        result = realloc(result, (strlen(cell_res) + len + 2));
        strcat(result, cell_res);
        free(cell_res);
        if (i < 1)
            curr = (player->front_cell)->left;
        else
            curr = curr->right;
        if (i < 3)
            result = strcat(result, ",");
    }
    result = strcat(result, " ]");
    return (result);
}

char *look_down(player_t *player)
{
    char *result = calloc(2, sizeof(char));
    char *cell_res;
    cell_t *curr = player->position;
    int len = 0;

    result[0] = '[';
    for (int i = 0; i < 4; i++) {
        cell_res = display_resources(curr);
        len = strlen(result);
        result = realloc(result, (strlen(cell_res) + len + 2));
        strcat(result, cell_res);
        free(cell_res);
        if (i < 1)
            curr = (player->front_cell)->right;
        else
            curr = curr->left;
        if (i < 3)
            result = strcat(result, ",");
    }
    result = strcat(result, " ]");
    return (result);
}

char *look_left(player_t *player)
{
    char *result = calloc(2, sizeof(char));
    char *cell_res;
    cell_t *curr = player->position;
    int len = 0;

    result[0] = '[';
    for (int i = 0; i < 4; i++) {
        cell_res = display_resources(curr);
        len = strlen(result);
        result = realloc(result, (strlen(cell_res) + len + 2));
        strcat(result, cell_res);
        free(cell_res);
        if (i < 1)
            curr = (player->front_cell)->down;
        else
            curr = curr->up;
        if (i < 3)
            result = strcat(result, ",");
    }
    result = strcat(result, " ]");
    return (result);
}

char *look_right(player_t *player)
{
    char *result = calloc(2, sizeof(char));
    char *cell_res;
    cell_t *curr = player->position;
    int len = 0;

    result[0] = '[';
    for (int i = 0; i < 4; i++) {
        cell_res = display_resources(curr);
        len = strlen(result);
        result = realloc(result, (strlen(cell_res) + len + 2));
        strcat(result, cell_res);
        free(cell_res);
        if (i < 1)
            curr = (player->front_cell)->up;
        else
            curr = curr->down;
        if (i < 3)
            result = strcat(result, ",");
    }
    result = strcat(result, " ]");
    return (result);
}

int look(player_t *player)
{
    char *result;

    if (player->up == 1)
        result = look_up(player);
    if (player->down == 1)
        result = look_down(player);
    if (player->left == 1)
        result = look_left(player);
    if (player->right == 1)
        result = look_left(player);
    printf("%s\n", result);
    free(result);
    return (0);
}
