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

    strtok(comp, " ");
    while (i < 7){
        if (strcmp(cmd_names[i], comp) == 0){
            if (i < 5) {
                (no_arg_cmd[i])(player);
                return 0;
            }
            else 
                return((arg_cmd[i-5])(player, &client_message[strlen(comp) + 1]));
        }
        else
            i++;
    }
    return (1);
}