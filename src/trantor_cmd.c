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
#include "trantor_cmd.h"

int send_resp(int sockfd, int cmd_val)
{
    int ret = 0;

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

    memset(result, 0, BUFF_SIZE);
    while (temp != '\n' && read_bytes > 0) {
        read_bytes = read(sockfd, &temp, 1);
        if (read_bytes <= 0)
            return (-1);
        result[i] = temp;
        i++;
    }
    return (i);
}

int send_cmd(int indice, char *item, player_t *player)
{
    if (indice < 3) {
        (no_arg_cmd[indice])(player);
        return (0);
    }
    else if ((indice >= 3) && (indice < 5)) {
        (socket_cmd[indice - 3])(player, player->socket_fd);
        return (1);
    }
    else {
        strtok(item, "\n");
        return ((arg_cmd[indice - 5])(player, item));
    }
}

int check_cmd(char *client_message, player_t *player)
{
    char *comp = strdup(client_message);
    int item_pos = 0;

    strtok(comp, " ");
    item_pos = strlen(comp) + 1;
    for (int i = 0; i < 7; i++) {
        if (strcmp(cmd_names[i], comp) == 0) {
            free(comp);
            return (send_cmd(i, &client_message[item_pos], player));
        }
    }
    return (84);
}