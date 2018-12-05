/*
** EPITECH PROJECT, 2018
** trantor
** File description:
** Header for the main functions of trantor server
*/

#ifndef TRANTOR_H_
#define TRANTOR_H_
#include "trantor_elements.h"

void print_usage(void);
args_t parse_args(int ac, char **av);
int trantor(int ac, char **av);

#endif /* !TRANTOR_H_ */
