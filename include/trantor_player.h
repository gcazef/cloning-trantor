/*
** EPITECH PROJECT, 2018
** trantor_player
** File description:
** Headers related to the player
*/

#ifndef TRANTOR_PLAYER_H_
#define TRANTOR_PLAYER_H_

#include "trantor_elements.h"

int rotate_left(player_t *player);
int rotate_right(player_t *player);
int move_forward(player_t *player);
char *look(player_t *player);
//char *display_inventory(player_t *player);

#endif /* !TRANTOR_PLAYER_H_ */
