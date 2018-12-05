/*
** EPITECH PROJECT, 2018
** trantor_elements
** File description:
** Definition of the constants
*/

#include "trantor_elements.h"
#include "trantor_player.h"
#include "trantor_vision.h"
#include "trantor_resources.h"

char const *resource_names[7] =
{
    "food",
    "linemate",
    "deraumere",
    "sibur",
    "mendiane",
    "phiras",
    "thystame"
};

char const *cmd_names[7] = 
{
    "forward",
    "left",
    "right",
    "look",
    "inventory",
    "take",
    "drop"
};

int const (*no_arg_cmd[5])(player_t *player) = 
{
    move_forward,
    rotate_left,
    rotate_right,
    look,
    display_inventory
};

int const (*arg_cmd[2])(player_t *player, char *name) = 
{
    take_resource,
    drop_resource
};