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
    char *result;
    char *cell_res;
    cell_t *curr = player->position;
    int oldLen = 0;

    cell_res = display_resources(curr);
    result = calloc(strlen(cell_res) + 1, sizeof(char));
    result[0] = '[';
    strcat(result, cell_res);
    free(cell_res);
    curr = (curr->up)->left;
    for (int i = 0; i < 4; i++) {
        cell_res = display_resources(curr);
        oldLen = strlen(result);
        result = realloc(result, (strlen(cell_res) + oldLen + 2));
        result = strcat(result, cell_res);
        if (i < 3)
            result = strcat(result, ",");
        curr = curr->right;
        free(cell_res);
    }
    oldLen = strlen(result);
    result = realloc(result, oldLen + 3);
    result = strcat(result, " ]");
    return (result);
}

/*
char *look_down(player_t *player);
char *look_left(player_t *player);
char *look_right(player_t *player);
*/

/*
char *look(player_t *player)
{
    char *result;
    char *cell_res;
    cell_t *curr = player->position;
    int oldLen = 0;

    cell_res = look_cell(curr);
    result = calloc(strlen(cell_res) + 1, sizeof(char));
    result[0] = '[';
    strcat(result, cell_res);
    free(cell_res);
    curr = (curr->up)->left;
    for (int i = 0; i < 4; i++) {
        cell_res = look_cell(curr);
        oldLen = strlen(result);
        result = realloc(result, (strlen(cell_res) + oldLen + 2));
        result = strcat(result, cell_res);
        if (i < 3)
            result = strcat(result, ",");
        curr = curr->right;
        free(cell_res);
    }
    oldLen = strlen(result);
    result = realloc(result, oldLen + 3);
    result = strcat(result, " ]");
    return (result);
}
*/


char *look(player_t *player)
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
    return (result);
}
