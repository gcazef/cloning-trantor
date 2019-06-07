/*
** EPITECH PROJECT, 2019
** USP_cloning_trantor_2018
** File description:
** test_trantor_ressources
*/

#include <criterion/criterion.h>
#include "trantor_elements.h"
#include "trantor_resources.h"

// create_inventory
Test(create_inventory, inventory_is_well_created)
{
    resource_t inv = create_inventory();

    cr_assert_eq(inv.food, 10);
}