/*
** EPITECH PROJECT, 2018
** trantor_elements
** File description:
** Structs for the trantor resources and players
*/

#ifndef TRANTOR_ELEMENTS_H_
#define TRANTOR_ELEMENTS_H_

typedef struct element {
    char *type;
    struct element *prev;
    struct element *next;
} element_t;

typedef struct player {
    struct element base;
    char *team;
    int id;
} player_t;

#endif /* !TRANTOR_ELEMENTS_H_ */
