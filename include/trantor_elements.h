/*
** EPITECH PROJECT, 2018
** trantor_elements
** File description:
** Structs for the trantor resources and players
*/

#ifndef TRANTOR_ELEMENTS_H_
#define TRANTOR_ELEMENTS_H_

#include <pthread.h>

typedef union {
    struct {
        int food;
        int linemate;
        int deraumere;
        int sibur;
        int mendiane;
        int phiras;
        int thystame;
    };
    int res[7];
} resource_t;

typedef struct cell {
    struct cell *up;
    struct cell *down;
    struct cell *left;
    struct cell *right;
    resource_t resources;
    int players;
    pthread_mutex_t res_mutex[7];
    pthread_mutex_t player_mutex;
} cell_t;

typedef enum look {
    UP,
    RIGHT,
    DOWN,
    LEFT
} look_t;

typedef struct player {
    cell_t *position;
    cell_t *front_cell;
    look_t look;
    resource_t inventory;
    int socket_fd;
} player_t;

typedef struct grid {
    cell_t *top_left;
    int height;
    int width;
} grid_t;

typedef struct args {
    int height;
    int width;
    int port;
} args_t;

char const *resource_names[7];
char const *cmd_names[7];
void (*no_arg_cmd[3])(player_t *player);
void (*socket_cmd[2])(player_t *player);
int (*arg_cmd[2])(player_t *player, char *name);

#endif /* !TRANTOR_ELEMENTS_H_ */
