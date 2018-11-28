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

void link_borders(cell_t *top_left)
{
    cell_t *curr = top_left;
    cell_t *end = top_left;

    while (curr != NULL) {
        while (end->down != NULL)
            end = end->down;
        end->down = curr;
        curr->up = end;
        curr = curr->right;
        if (end->right != NULL)
            end = end->right;
    }
    curr = top_left->up;
    while (top_left->left != end) {
        end->right = curr;
        curr->left = end;
        curr = curr->up;
        end = end->up;
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
        if (i < (height - 1))
            head = create_cell();
    }
    if (curr != NULL)
        link_borders(curr);
    return (curr);
}

int destroy_grid(cell_t *top_left)
{
    cell_t *top_right = top_left->left;
    cell_t *curr = top_right->up;

    top_left->left = NULL;
    while (curr != NULL) {
        top_right->up = NULL;
        while (curr->up != NULL) {
            curr = curr->up;
            free(curr->down);
            curr->down = NULL;
        }
        if (top_right->left != NULL) {
            top_right = top_right->left;
            free(curr);
            curr = top_right->up;
            
        } else {
            free(curr);
            curr = NULL;
        }
    }
    return (0);
}