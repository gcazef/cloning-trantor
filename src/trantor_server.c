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
#include "trantor_world.h"
#include "trantor_player.h"
#include "trantor_vision.h"
#include "trantor_resources.h"
#include "trantor_server.h"
#include "trantor_cmd.h"

#define ADDR "127.0.0.1"
#define MAX_CO 1000

void *connection_handler(void *player)
{
    player_t *p = (player_t *) player;
    int sock = p->socket_fd;
    int read_size;
    char client_message[2000];
    
    while ((read_size = recv(sock, client_message, 2000, 0)) > 0) {
        client_message[read_size] = '\0';
        if (check_cmd(client_message, p) == 1) {
            write(sock, "ok\n", 4);
        }
        else
            write(sock, "ko\n", 4);
        printf("%d\n", sock);
        if (strcmp("exit\n", client_message) == 0) {
            read_size = 0;
            break;
        }
        //printf("%s", client_message);
        memset(client_message, 0, 2000);
    }
    free(p);
    close(sock);
    return 0;
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

pthread_t init_conn(struct sockaddr_in client, int s_sckt, grid_t grid)
{
    int c_sckt;
    socklen_t cli_len;
    pthread_t thread_id;
    player_t *p;
    
    c_sckt = accept(s_sckt, (struct sockaddr *)&client, &cli_len);
        if (c_sckt == -1) {
        perror("Could not accept connection");
        return (84);
    }
    p = create_player(grid.top_left, grid.height, grid.width);
    p->socket_fd = c_sckt;
    if (pthread_create(&thread_id, NULL, connection_handler, (void*)p) < 0) {
        perror("Could not create thread");
        return (84);
    }
    return (thread_id);
}

int trantor_server(int port, grid_t grid)
{
    int my_socket;
    int nb_threads = 0;
    pthread_t threads[MAX_CO];
    struct sockaddr_in server;
    struct sockaddr_in client;
    char command[10];

    my_socket = create_socket(port, server);
    if (my_socket == 84)
        return (84);
    while (fgets(command, 10, stdin) != NULL) {
        threads[nb_threads] = init_conn(client, my_socket, grid);
        nb_threads++;
    }
    for (int i = 0; i < nb_threads; i++) {
        pthread_join(threads[i], NULL);
    }
    return (0);
}