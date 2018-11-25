/*
** EPITECH PROJECT, 2018
** trantor_elements
** File description:
** Structs for the trantor resources and players
*/

#ifndef TRANTOR_ELEMENTS_H_
#define TRANTOR_ELEMENTS_H_
/*
typedef struct player {
    struct element base;
    char *team;
    int id;
} player_t;
*/

typedef struct resource {
    int food;
    int linemate;
    int deraumere;
    int sibur;
    int mendiane;
    int phiras;
    int thystame;
} resource_t;

typedef struct cell {
    int x_pos;
    int y_pos;
    cell_t *up;
    cell_t *down;
    cell_t *left;
    cell_t *right;
    resource_t resources;
    int players;
} cell_t;

/*
typedef struct grid {
    cell_t **cells;
    int width;
    int height;
} grid_t;
*/

#endif /* !TRANTOR_ELEMENTS_H_ */
