/*
** EPITECH PROJECT, 2019
** USP_cloning_trantor_2018
** File description:
** trantor_buff
*/

#include <stdlib.h>
#include "trantor_buff.h"

void push_buff(ring_buff_t *res, char c)
{
    res->buff[res->writer] = c;
    if (res->writer == BUFF_SIZE - 1)
        res->writer = 0;
    else
        res->writer++;
}

void pop_buff(ring_buff_t *res, char *msg)
{
    int i = 0;

    while (res->reader != res->writer) {
        if (msg != NULL)
            msg[i] = res->buff[res->reader];
        if (res->reader == BUFF_SIZE - 1)
            res->reader = 0;
        else
            res->reader++;
        i++;
    }
    if (msg == NULL)
        res->writer = res->reader;
}