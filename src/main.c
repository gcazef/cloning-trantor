/*
** EPITECH PROJECT, 2018
** main
** File description:
** Entry point for trantor server v1
*/

#include "trantor.h"
#include <stdlib.h>

int main(int argv, char **argc)
{
    if (argv < 0)
        return(84);
    return (trantor(argc[1], atoi(argc[2])));
}