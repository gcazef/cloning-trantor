/*
** EPITECH PROJECT, 2018
** trantor_cmd
** File description:
** Header file for the reception of commands
*/

#ifndef TRANTOR_CMD_H_
#define TRANTOR_CMD_H_

#include "trantor_elements.h"

#define BUFF_SIZE 16

typedef struct ring_buff {
    char * const buff;
    int reader;
    int writer;
} ring_buff_t;

int send_resp(int sockfd, int cmd_val);
int read_buffer(int sockfd, ring_buff_t *result);
void pop_buff(ring_buff_t *res, char *msg);
int send_cmd(int indice, char *item, player_t *player);
int check_cmd(ring_buff_t *result, player_t *player);

#endif /* !TRANTOR_CMD_H_ */
