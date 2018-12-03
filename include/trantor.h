/*
** EPITECH PROJECT, 2018
** trantor
** File description:
** Header for the main functions of trantor server
*/

#ifndef TRANTOR_H_
#define TRANTOR_H_
#include "trantor_elements.h"

resource_t create_inventory(void);
player_t create_player(char *team, cell_t *top_left, int height, int width);
int trantor(void);

#endif /* !TRANTOR_H_ */
