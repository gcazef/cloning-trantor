/*
** EPITECH PROJECT, 2018
** trantor_world
** File description:
** Functions for generating the trantor world
*/

#include <stdlib.h>
#include <stddef.h>
#include "trantor_elements.h"

cell_t *create_cell(void)
{
    cell_t *new_cell = malloc(sizeof(cell_t));

    new_cell->up = NULL;
    new_cell->down = NULL;
    new_cell->left = NULL;
    new_cell->right = NULL;
    new_cell->players = 0;
    return (new_cell);
}

void link_lines(cell_t *prev, cell_t *curr)
{
    while (curr != NULL) {
        curr->down = prev;
        prev->up = curr;
        curr = curr->right;
        prev = prev->right;
    }
}

cell_t *create_grid(int width, int height)
{
    cell_t *head = create_cell();
    cell_t *prev = NULL;
    cell_t *curr = NULL;

    for (int i = 0; i < height; i++) {
        curr = head;
        for (int j = 0; j < (width - 1); j++) {
            curr->left = create_cell();
            (curr->left)->right = curr;
            curr = curr->left;
        }
        if (prev != NULL)
            link_lines(prev, curr);
        prev = curr;
        if (i < (height - 1)) {
            head->up = create_cell();
            (head->up)->down = head;
            head = head->up;
        }
    }
    return (curr);
}

int destroy_grid(cell_t *top_left)
{
    cell_t *curr = top_left;
    cell_t *prev = NULL;

    while (curr != NULL) {
        while (curr->down != NULL)
            curr = curr->down;
        while (curr->up != NULL) {
            curr = curr->up;
            free(curr->down);
            curr->down = NULL;
        }
        prev = curr;
        curr = curr->right;
        free(prev);
        prev = NULL;
        
    }
    free(curr);
    return (0);
}