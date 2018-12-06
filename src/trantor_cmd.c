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
    int i = 0;
    
    char *comp = strdup(client_message);
    char *item;

    strtok(comp, " ");
    while (i < 7){
        if (strcmp(cmd_names[i], comp) == 0){
            if (i < 3) {
                (no_arg_cmd[i])(player);
                return 0;
            }
            else if ((i >= 3) && (i < 5)) {
                (socket_cmd[i-3])(player, player->socket_fd);
                return (0);
            }
            else {
                item = &client_message[strlen(comp) + 1];
                strtok(item, "\n");
                return((arg_cmd[i-5])(player, item));
            }
        }
        else
            i++;
    }
    return (1);
}