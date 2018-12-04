/*
** EPITECH PROJECT, 2018
** trantor_resources
** File description:
** Generation of trantor resources
*/

#include <time.h>
#include <stdlib.h>
#include <string.h>
#include "trantor_elements.h"

resource_t generate_resource(void)
{
    resource_t ptr;
    srand(time(NULL));

    ptr.food = rand() % 2;
    ptr.linemate = rand() % 2;
    ptr.deraumere = rand() % 2;
    ptr.sibur = rand() % 2;
    ptr.mendiane = rand() % 2;
    ptr.phiras = rand() % 2;
    ptr.thystame = rand() % 2;
    return (ptr);
}

char *display_resources(cell_t *cell)
{
    char *result = calloc((cell->players * 7 + 1), sizeof(char));
    int resLen = 0;
    int oldLen = 0;

    for (int i = 0; i < cell->players; i++)
        result = strcat(result, " player");
    for (int i = 0; i < 7; i++) {
        resLen = (strlen(resource_names[i]) + 1) * (cell->resources).res[i];
        oldLen = strlen(result);
        result = realloc(result, (resLen + oldLen + 1) * sizeof(char));
        result[oldLen] = '\0';
        for (int j = 0; j < (cell->resources).res[i]; j++) {
            result = strcat(result, " ");
            result = strcat(result, resource_names[i]);
        }
        result[oldLen + resLen] = '\0';
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