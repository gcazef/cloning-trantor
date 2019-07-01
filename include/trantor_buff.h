/*
** EPITECH PROJECT, 2019
** USP_cloning_trantor_2018
** File description:
** trantor_buff
*/

#ifndef TRANTOR_BUFF_H_
#define TRANTOR_BUFF_H_

#define BUFF_SIZE 64

typedef struct ring_buff {
    char * const buff;
    int reader;
    int writer;
} ring_buff_t;

void push_buff(ring_buff_t *res, char c);
void pop_buff(ring_buff_t *res, char *msg);

#endif /* !TRANTOR_BUFF_H_ */
