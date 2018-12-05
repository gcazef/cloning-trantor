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
#include <string.h>
#include <pthread.h>
#include <stddef.h>
#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#include "trantor_world.h"
#include "trantor_player.h"
#include "trantor_vision.h"
#include "trantor_resources.h"
#include "trantor_server.h"

int checkcommand(char *client_message)
{
    int i = 0;
    char *command[8] = {"forward\n", "left\n", "right\n", "look\n",
        "inventory\n", "take", "drop", "exit\n"};
    char *comp = strdup(client_message);
    strtok(comp, " ");
    while (i < 8){
        if (strcmp(command[i], comp) == 0)
            return (1);
        else
            i++;
    }
    return (0);
}

void *connection_handler(void *my_socket)
{
    int sock = *(int*) my_socket;
    int read_size;
    char client_message[2000];
    while ((read_size = recv(sock, client_message, 2000, 0)) > 0) {
        client_message[read_size] = '\0';
        if (checkcommand(client_message) == 1)
            write(sock, "ok\n", 4);
        else
            write(sock, "ko\n", 4);
        if (strcmp("exit\n", client_message) == 0) {
            read_size = 0;
            break;
        }
        printf("%s", client_message);
        memset(client_message, 0, 2000);
    }
    close(sock);
    return 0;
}

int create_socket(int port, struct sockaddr_in sin, char *addr)
{
    int server_socket;
    server_socket = socket(AF_INET, SOCK_STREAM, 0);
    printf("Socket created\n");
    sin.sin_family = AF_INET;
    sin.sin_port = htons(port);
    sin.sin_addr.s_addr = inet_addr(addr);
    int connection_status = bind(server_socket, (struct sockaddr *) &sin,
    sizeof(sin));
    if (connection_status == -1){
        printf("There was an error making a connection to the remote socket");
        return (connection_status);
    }
    printf("Bind success\n");
    listen(server_socket, 3000);
    printf("Waiting for connection\n");
    return (server_socket);
}

int handling(struct sockaddr_in client, int my_socket)
{
    int new_socket;
    int cli_len = sizeof(client);
    pthread_t thread_id;
    while ((new_socket = accept(my_socket,
    (struct sockaddr *)&client, (socklen_t*)&cli_len))) {
        printf("Connection accepted\n");
        if (pthread_create(&thread_id, NULL,
        connection_handler, (void*) &new_socket) < 0){
            perror("could not create thread");
            return 1;
        }
        printf("Handler assigned\n");
    }
    if (new_socket < 0) {
        perror("accept failed");
    }
    return new_socket;
}

int trantor_server(char *ip, int port)
{
    //int client_socket;
    int my_socket;
    //int cli_len;
    struct sockaddr_in sin;
    struct sockaddr_in client;
    //cell_t *top_left = create_grid(10, 10);
    cell_t *top_left = create_grid(10, 10);
    player_t p = create_player("squad", top_left, 10, 10);


    my_socket = create_socket(port, sin, ip);
    if (my_socket == 0)
        return (0);
    handling(client, my_socket);
    return (0);
}
/*
{
    server(argc, argv[1], atoi(argv[2]));
    return (0);
int main(int argc, char **argv)
}
*/