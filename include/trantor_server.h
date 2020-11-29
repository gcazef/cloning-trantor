/*
** EPITECH PROJECT, 2018
** trantor_server.h
** File description:
** Functions related to trantor server
*/

#ifndef TRANTOR_SERVER_H_
#define TRANTOR_SERVER_H_

#include <netinet/in.h>
#include "trantor_elements.h"
#include "trantor_errors.h"

#define ADDR "127.0.0.1"

void signal_handler(int signo);
void *connection_handler(void *player);
int create_socket(int port);
int init_conn(struct sockaddr_in client, int s_sckt, grid_t grid);
int trantor_server(int port, grid_t grid);

#endif
