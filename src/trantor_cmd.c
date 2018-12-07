/*
** EPITECH PROJECT, 2018
** trantor_cmd
** File description:
** Functions for command reception
*/

#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include "trantor_elements.h"

int send_resp(int sockfd, int cmd_val)
{
    int ret;

    if (cmd_val == 0)
        ret = dprintf(sockfd, "ok\n");
    else if (cmd_val == 84)
        ret = dprintf(sockfd, "ko\n");
    if (ret < 0)
        return (-1);
    return (0);
}

int read_buffer(int sockfd, char *result)
{
    char temp = 0;
    int read_bytes = 1;
    int i = 0;

    while (temp != '\n' && read_bytes > 0) {
        read_bytes = read(sockfd, &temp, 1);
        if (read_bytes <= 0)
            return (-1);
        result[i] = temp;
        i++;
    }
    return (i);
}

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
                (socket_cmd[i - 3])(player, player->socket_fd);
                return (1);
            }
            else {
                item = &client_message[strlen(comp) + 1];
                strtok(item, "\n");
                return((arg_cmd[i - 5])(player, item));
            }
        }
    }
    free(comp);
    return (84);
}