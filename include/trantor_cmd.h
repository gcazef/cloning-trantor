/*
** EPITECH PROJECT, 2018
** trantor_cmd
** File description:
** Header file for the reception of commands
*/

#ifndef TRANTOR_CMD_H_
#define TRANTOR_CMD_H_

#include "trantor_elements.h"

#define BUFF_SIZE 2048

int send_resp(int sockfd, int cmd_val);
int read_buffer(int sockfd, char *result);
int send_cmd(int indice, char *item, player_t *player);
int check_cmd(char *client_message, player_t *player);

#endif /* !TRANTOR_CMD_H_ */
