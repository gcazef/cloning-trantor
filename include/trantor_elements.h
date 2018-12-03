/*
** EPITECH PROJECT, 2018
** trantor_elements
** File description:
** Structs for the trantor resources and players
*/

#ifndef TRANTOR_ELEMENTS_H_
#define TRANTOR_ELEMENTS_H_

char const *resource_names[7] =
{
    "food",
    "linemate",
    "deraumere",
    "sibur",
    "mendiane",
    "phiras",
    "thystame"
};

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
    int x_pos;
    int y_pos;
    struct cell *up;
    struct cell *down;
    struct cell *left;
    struct cell *right;
    resource_t resources;
    int players;
} cell_t;

typedef struct player {
    cell_t *position;
    cell_t *front_cell;
    int up;
    int down;
    int left;
    int right;
    resource_t inventory;
    char *team;
} player_t;

/*
typedef struct grid {
    cell_t **cells;
    int width;
    int height;
} grid_t;
*/

#endif /* !TRANTOR_ELEMENTS_H_ */
