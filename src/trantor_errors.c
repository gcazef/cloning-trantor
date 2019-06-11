/*
** EPITECH PROJECT, 2019
** USP_cloning_trantor_2018
** File description:
** trantor_errors
*/

#include <stdio.h>
#include <errno.h>

void print_usage(void)
{
    printf("Usage: ./trantor -w <width> -h <height> -p <port>\n");
}

int print_error(char *msg)
{
    perror(msg);
    return (-1);
}