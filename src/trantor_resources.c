/*
** EPITECH PROJECT, 2018
** trantor_resources
** File description:
** Generation of trantor resources
*/

#include <stdlib.h>
#include <string.h>
#include <pthread.h>
#include "trantor_elements.h"

resource_t generate_resource(void)
{
    resource_t ptr;

    for (int i = 0; i < 7; i++) {
        ptr.res[i] = rand() % 2;
    }
    return (ptr);
}

char *display_resources(cell_t *cell)
{
    char *result = calloc((cell->players * 7 + 1), sizeof(char));
    int res_len = 0;
    int old_len = 0;

    for (int i = 0; i < cell->players; i++)
        result = strcat(result, " player");
    for (int i = 0; i < 7; i++) {
        res_len = (strlen(resource_names[i]) + 1) * (cell->resources).res[i];
        old_len = strlen(result);
        result = realloc(result, (res_len + old_len + 1) * sizeof(char));
        result[old_len] = '\0';
        pthread_mutex_lock(&(cell->res_mutex[i]));
        for (int j = 0; j < (cell->resources).res[i]; j++) {
            result = strcat(result, " ");
            result = strcat(result, resource_names[i]);
        }
        pthread_mutex_unlock(&(cell->res_mutex[i]));
        result[old_len + res_len] = '\0';
    }
    return (result);
}

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

int drop_resource(player_t *player, char *name)
{
    int found = 1;
    int i = 0;
    int present = 0;
    cell_t *pos = player->position;

    while ((found != 0) && (i < 7)) {
        found = strcmp(name, resource_names[i]);
        i++;
    }
    if (found != 0)
        return (84);
    present = (player->inventory).res[i - 1];
    if (present > 0) {
        pthread_mutex_lock(&(pos->res_mutex[i - 1]));
        (player->inventory).res[i - 1] -= 1;
        (pos->resources).res[i - 1] += 1;
        pthread_mutex_unlock(&(pos->res_mutex[i - 1]));
        return (0);
    }
    return (84);
}

int take_resource(player_t *player, char *name)
{
    int found = 1;
    int i = 0;
    int present = 0;
    cell_t *pos = player->position;

    while ((found != 0) && (i < 7)) {
        found = strcmp(name, resource_names[i]);
        i++;
    }
    if (found != 0)
        return (84);
    pthread_mutex_lock(&(pos->res_mutex[i - 1]));
    present = (pos->resources).res[i - 1];
    if (present > 0) {
        (player->inventory).res[i - 1] += 1;
        (pos->resources).res[i - 1] -= 1;
    }
    pthread_mutex_unlock(&(pos->res_mutex[i - 1]));
    return (present > 0) ? 0 : 84;
}