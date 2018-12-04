/*
** EPITECH PROJECT, 2018
** trantor_resources.h
** File description:
** Functions for generation of trantor resources
*/

#ifndef TRANTOR_RESOURCES_H_
#define TRANTOR_RESOURCES_H_

resource_t generate_resource(void);
char *display_resources(cell_t *cell);
resource_t create_inventory(void);
int take_resource(player_t *player, char *name);
int drop_resource(player_t *player, char *name);

#endif /* !TRANTOR_RESOURCES_H_ */
