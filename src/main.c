/*
** EPITECH PROJECT, 2018
** main
** File description:
** Entry point for trantor server v1
*/

#include "trantor.h"

int main(int ac, char **av)
{
    if (trantor(ac, av) == -1)
        return (84);
    return (0);
}