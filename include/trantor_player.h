/*
** EPITECH PROJECT, 2018
** trantor_player
** File description:
** Headers related to the player
*/

#ifndef TRANTOR_PLAYER_H_
#define TRANTOR_PLAYER_H_

player_t create_player(cell_t *top_left, int height, int width);
void rotate_left(player_t *player);
void rotate_right(player_t *player);
void move_forward(player_t *player);
void display_inventory(player_t *player, int sockfd);

#endif /* !TRANTOR_PLAYER_H_ */
