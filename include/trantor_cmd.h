/*
** EPITECH PROJECT, 2018
** trantor_cmd
** File description:
** Header file for the reception of commands
*/

#ifndef TRANTOR_CMD_H_
#define TRANTOR_CMD_H_

#include "trantor_elements.h"
#include "trantor_buff.h"

int send_resp(int sockfd, int cmd_val);
int read_buffer(int sockfd, ring_buff_t *result);
int send_cmd(int indice, char *item, player_t *player);
int check_cmd(ring_buff_t *result, player_t *player);

#endif /* !TRANTOR_CMD_H_ */
