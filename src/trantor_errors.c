/*
** EPITECH PROJECT, 2019
** USP_cloning_trantor_2018
** File description:
** trantor_errors
*/

#include <stdio.h>
#include <errno.h>
#include <unistd.h>
#include <stdlib.h>
#include "trantor_elements.h"
#include "trantor_errors.h"

void print_usage(void)
{
    printf("Usage: ./trantor -w <width> -h <height> -p <port>\n");
}

int print_error(char *msg)
{
    perror(msg);
    return (-1);
}

int add_player(player_t *player, player_t **all_players, int nb_clients)
{
    for (int i = 0; i <= MAX_CO; i++) {
        if (all_players[i] == NULL) {
            all_players[i] = player;
            nb_clients++;
            break;
        }
    }
    return (nb_clients);
}

int delete_player(player_t *player, player_t **all_players, int nb_clients)
{
    for (int i = 0; i <= MAX_CO; i++) {
        if (all_players[i] == player) {
            all_players[i] = NULL;
            break;
        }
    }
    if (player != NULL) {
        pthread_mutex_lock(&(player->position->player_mutex));
        player->position->players -= 1;
        pthread_mutex_unlock(&(player->position->player_mutex));
        close(player->socket_fd);
        pthread_detach(player->thread_id);
        pthread_cancel(player->thread_id);
        free(player);
    }
    return (nb_clients - 1);
}

void remove_all_players(player_t **all_players, int nb_clients)
{
    for (int i = 0; i < MAX_CO; i++) {
        if (all_players[i] != NULL)
            delete_player(all_players[i], all_players, nb_clients);
    }
}
