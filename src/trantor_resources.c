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

    ptr.food = rand() %5;
    ptr.linemate = rand() %5;
    ptr.deraumere = rand() %5;
    ptr.sibur = rand() %5;
    ptr.mendiane = rand() %5;
    ptr.phiras = rand() %5;
    ptr.thystame = rand()%5;
    return (ptr);
}

char *look_cell(cell_t *cell)
{
    char *result = calloc(cell->players * 7, sizeof(char));
    int resLen = 0;
    int oldLen = 0;

    for (int i = 0; i < cell->players; i++)
        result = strcat(result, " player");
    for (int i = 0; i < 7; i++) {
        resLen = (strlen(resource_names[i]) + 1) * (cell->resources).res[i];
        oldLen = strlen(result);
        result = realloc(result, (resLen + oldLen));
        for (int j = 0; j < (cell->resources).res[i]; j++) {
            result = strcat(result, " ");
            result = strcat(result, resource_names[i]);
        }
    }
    return (result);
}