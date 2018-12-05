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

int create_socket(int port, struct sockaddr_in server);
pthread_t init_conn(struct sockaddr_in client, int my_socket, grid_t grid);
void *connection_handler(void *player);
int checkcommand(char *client_message);
int trantor_server(int port, grid_t grid);

#endif