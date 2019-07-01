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

int read_buffer(int sockfd, ring_buff_t *result)
{
    char temp[BUFF_SIZE + 1] = { 0 };
    char curr = 0;
    int read_bytes = 1;
    int i = 0;

    read_bytes = read(sockfd, temp, BUFF_SIZE);
    while (curr != '\n' && read_bytes > 0) {
        while (temp[i - 1] != '\n' && temp[i] != 0) {
            curr = temp[i];
            push_buff(result, curr);
            i++;
        }
        i = 0;
        if (curr != '\n') {
            read_bytes = read(sockfd, temp, BUFF_SIZE);
            temp[read_bytes] = 0;
        }
    }
    return (read_bytes);
}

int send_cmd(int indice, char *item, player_t *player)
{
    if (indice < 3) {
        (no_arg_cmd[indice])(player);
        return (0);
    }
    else if ((indice >= 3) && (indice < 5)) {
        (socket_cmd[indice - 3])(player);
        return (1);
    }
    else {
        strtok(item, "\n");
        return ((arg_cmd[indice - 5])(player, item));
    }
}

int check_cmd(ring_buff_t *result, player_t *player)
{
    char msg[BUFF_SIZE] = { 0 };
    char *comp;
    int item_pos = 0;

    pop_buff(result, msg);
    comp = strdup(msg);
    if (comp == NULL)
        return (-1);
    strtok(comp, " ");
    item_pos = strlen(comp) + 1;
    for (int i = 0; i < 7; i++) {
        if (strcmp(cmd_names[i], comp) == 0) {
            free(comp);
            return (send_cmd(i, &msg[item_pos], player));
        }
    }
    return (84);
}