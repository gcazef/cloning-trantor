/*
** EPITECH PROJECT, 2019
** USP_cloning_trantor_2018
** File description:
** trantor_server
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <sys/stat.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <unistd.h>
#include <pthread.h>
#include <stddef.h>
#include <time.h>
#include <signal.h>
#include "trantor_world.h"
#include "trantor_player.h"
#include "trantor_vision.h"
#include "trantor_resources.h"
#include "trantor_server.h"
#include "trantor_cmd.h"
#include "trantor_errors.h"

void *connection_handler(void *player)
{
    player_t *p = (player_t *) player;
    int read_size = 0;
    char client_message[BUFF_SIZE];
    int cmd_val = 0;

    read_buffer(p->socket_fd, client_message);
    dprintf(p->socket_fd, "1\n%d %d\n", grid_entry.width, grid_entry.height);
    while ((read_size = read_buffer(p->socket_fd, client_message)) > 0) {
        cmd_val = check_cmd(client_message, p);
        if (cmd_val < 0)
            break;
        if (send_resp(p->socket_fd, cmd_val) < 0)
            break;
    }
    pthread_mutex_lock(&(p->position->player_mutex));
    p->position->players -= 1;
    pthread_mutex_unlock(&(p->position->player_mutex));
    close(p->socket_fd);
    free(p);
    pthread_detach(pthread_self());
    pthread_exit(NULL);
}

int create_socket(int port)
{
    struct sockaddr_in server;
    int server_socket;
    int conn;

    server_socket = socket(AF_INET, SOCK_STREAM, 0);
    if (server_socket == -1)
        return print_error("There was an error creating socket");
    server.sin_family = AF_INET;
    server.sin_port = htons(port);
    server.sin_addr.s_addr = inet_addr(ADDR);
    conn = bind(server_socket, (struct sockaddr *) &server, sizeof(server));
    if (conn == -1) {
        close(server_socket);
        return print_error("There was an error connecting to remote socket");
    }
    listen(server_socket, MAX_CO);
    return (server_socket);
}

int init_conn(struct sockaddr_in client, int s_sckt, grid_t grid)
{
    int c_sckt;
    socklen_t cli_len = 0;
    pthread_t thread_id;
    player_t *p;

    c_sckt = accept(s_sckt, (struct sockaddr *)&client, &cli_len);
    if (c_sckt == -1)
        return print_error("Could not accept connection");
    p = create_player(grid.top_left, grid.height, grid.width);
    if (p == NULL)
        return (-1);
    p->socket_fd = c_sckt;
    dprintf(p->socket_fd, "WELCOME\n");
    if (pthread_create(&thread_id, NULL, connection_handler, (void*)p) < 0) {
        close(c_sckt);
        return print_error("Could not create thread");
    }
    return (0);
}

int trantor_server(int port, grid_t grid)
{
    int my_socket;
    struct sockaddr_in client;

    grid_entry = grid;
    signal(SIGINT, signal_handler);
    my_socket = create_socket(port);
    if (my_socket == -1)
        return (-1);
    while (1)
        //test return value
        init_conn(client, my_socket, grid);
    return (0);
}

void signal_handler(int signo)
{
    if (signo == SIGINT) {
        destroy_grid(grid_entry.top_left);
        exit(0);
    }
}