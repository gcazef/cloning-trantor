/*
** EPITECH PROJECT, 2019
** USP_cloning_trantor_2018
** File description:
** trantor_errors
*/

#ifndef TRANTOR_ERRORS_H_
#define TRANTOR_ERRORS_H_

#define MAX_CO 254

void print_usage(void);
int print_error(char *msg);
int add_player(player_t *player, player_t **all_players, int nb_clients);
int delete_player(player_t *player, player_t **all_players, int nb_clients);
void remove_all_players(player_t **all_players, int nb_clients);

#endif /* !TRANTOR_ERRORS_H_ */
