/*
** EPITECH PROJECT, 2018
** trantor
** File description:
** Main functions of the trantor server
*/

#include <stdlib.h>
#include <stdio.h>
#include <getopt.h>
#include <stddef.h>
#include "trantor_world.h"
#include "trantor_elements.h"

void print_usage(void)
{
    printf("Usage: trantor -w <width> -h <height> -p <port>\n");
    exit(1);
}

args_t parse_args(int ac, char **av)
{
    args_t result;
    int opt;

    if (ac < 7)
        print_usage();
    while ((opt = getopt(ac, av, "w:h:p:")) != -1) {
        switch (opt) {
            case 'w':
                result.width = atoi(optarg);
                break;
            case 'h':
                result.height = atoi(optarg);
                break;
            case 'p':
                result.port = atoi(optarg);
                break;
            default:
                print_usage();
        }
    }
    return (result);
}

int trantor(int ac, char **av)
{
    grid_t grid;
    args_t args = parse_args(ac, av);

    printf("%d", args.width);
    printf("%d", args.height);
    printf("%d", args.port);
    /*grid.height = args.height;
    grid.width = args.width;
    grid.top_left = create_grid(10, 10);    
    destroy_grid(grid.top_left);*/
    return (0);
}