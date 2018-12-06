/*
** EPITECH PROJECT, 2018
** trantor_server.h
** File description:
** Functions related to trantor server
*/

#ifndef TRANTOR_SERVER_H_
#define TRANTOR_SERVER_H_

#include "trantor_elements.h"
#include <stdio.h>
#include <stdlib.h>
#include <sys/socket.h>
#include <sys/stat.h>
#include <errno.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <unistd.h>
#include <string.h>
#include <pthread.h>

void signal_handler();
void *connection_handler(void *player);
int create_socket(int port, struct sockaddr_in server);
pthread_t init_conn(struct sockaddr_in client, int s_sckt, grid_t grid);
int trantor_server(int port, grid_t grid);

#endif