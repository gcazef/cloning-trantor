/*
** EPITECH PROJECT, 2018
** server.c
** File description:
** 
*/
#include <stdio.h>
#include <stdlib.h>
#include <sys/socket.h>
#include <sys/stat.h>
#include <errno.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <unistd.h>
#include <pthread.h>
#include <stddef.h>
#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#include <errno.h>
#include <signal.h>
#include "trantor_world.h"
#include "trantor_player.h"
#include "trantor_vision.h"
#include "trantor_resources.h"
#include "trantor_server.h"
#include "trantor_cmd.h"

void *connection_handler(void *player)
{
    player_t *p = (player_t *) player;
    int read_size = 0;
    char client_message[BUFF_SIZE];
    int cmd_val;

    while ((read_size = read_buffer(p->socket_fd, client_message)) > 0) {
        cmd_val = check_cmd(client_message, p);
        if (send_resp(p->socket_fd, cmd_val) < 0)
            break;
        if (cmd_val < 0)
            break;
        memset(client_message, 0, BUFF_SIZE);
    }
    p->position->players -= 1;
    close(p->socket_fd);
    free(p);
    pthread_detach(pthread_self());
    pthread_exit(NULL);
}

int create_socket(int port, struct sockaddr_in server)
{
    int server_socket;
    int conn;
    
    server_socket = socket(AF_INET, SOCK_STREAM, 0);
    if (server_socket == -1){
        perror("There was an error creating socket");
        return (84);
    }
    server.sin_family = AF_INET;
    server.sin_port = htons(port);
    server.sin_addr.s_addr = inet_addr(ADDR);
    conn = bind(server_socket, (struct sockaddr *) &server, sizeof(server));
    if (conn == -1){
        perror("There was an error making a connection to the remote socket");
        return (84);
    }
    listen(server_socket, MAX_CO);
    return (server_socket);
}

int init_conn(struct sockaddr_in client, int s_sckt, grid_t grid)
{
    int c_sckt;
    socklen_t cli_len;
    pthread_t thread_id;
    player_t *p;
    char client_message[BUFF_SIZE];
    
    c_sckt = accept(s_sckt, (struct sockaddr *)&client, &cli_len);
    if (c_sckt == -1) {
        perror("Could not accept connection");
        return (84);
    }
    p = create_player(grid.top_left, grid.height, grid.width);
    p->socket_fd = c_sckt;
    dprintf(p->socket_fd, "WELCOME\n");
    read_buffer(p->socket_fd, client_message);
    dprintf(p->socket_fd, "1\n%d %d\n", grid_entry.width, grid_entry.height);
    if (pthread_create(&thread_id, NULL, connection_handler, (void*)p) < 0) {
        perror("Could not create thread");
        return (84);
    }
    return (0);
}

int trantor_server(int port, grid_t grid)
{
    int my_socket;
    int nb_threads = 0;
    struct sockaddr_in server;
    struct sockaddr_in client;

    grid_entry = grid;
    signal(SIGINT, signal_handler);
    my_socket = create_socket(port, server);
    if (my_socket == 84)
        return (84);
    while (1) {
        init_conn(client, my_socket, grid);
        nb_threads++;
    }
    return (0);
}

void signal_handler()
{
    destroy_grid(grid_entry.top_left);
    exit(0);
}