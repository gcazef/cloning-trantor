/*
** EPITECH PROJECT, 2018
** trantor_cmd
** File description:
** Functions for command reception
*/

#include <string.h>
#include "trantor_elements.h"

int check_cmd(char *client_message, player_t *player)
{
    char *comp = strdup(client_message);
    char *item;

    strtok(comp, " ");
    for (int i = 0; i < 7; i++) {
        if (strcmp(cmd_names[i], comp) == 0){
            if (i < 3) {
                (no_arg_cmd[i])(player);
                return (0);
            }
            else if ((i >= 3) && (i < 5)) {
                (socket_cmd[i-3])(player, player->socket_fd);
                return (1);
            }
            else {
                item = &client_message[strlen(comp) + 1];
                strtok(item, "\n");
                return((arg_cmd[i-5])(player, item));
            }
        }
    }
    return (84);
}