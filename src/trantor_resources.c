/*
** EPITECH PROJECT, 2018
** trantor_resources
** File description:
** Generation of trantor resources
*/
#include <time.h>
#include <stdlib.h>
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
