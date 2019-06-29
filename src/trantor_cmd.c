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
    char temp = 0;
    int read_bytes = 1;

    while (temp != '\n' && read_bytes > 0) {
        read_bytes = read(sockfd, &temp, 1);
        if (read_bytes <= 0)
            return (-1);
        result->buff[result->writer] = temp;
        if (result->writer == BUFF_SIZE - 1)
            result->writer = 0;
        else
            result->writer++;
    }
    return (read_bytes);
}

void pop_buff(ring_buff_t *res, char *msg)
{
    int i = 0;

    while (res->reader != res->writer) {
        if (msg != NULL)
            msg[i] = res->buff[res->reader];
        if (res->reader == BUFF_SIZE - 1)
            res->reader = 0;
        else
            res->reader++;
        i++;
    }
    if (msg == NULL)
        res->writer = res->reader;
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