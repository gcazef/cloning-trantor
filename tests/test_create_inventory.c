/*
** EPITECH PROJECT, 2018
** test_create_inventory
** File description:
** Unit tests for the create inventory function
*/

#include <criterion/criterion.h>
#include "trantor_elements.h"
#include "trantor_resources.h"

Test(create_inventory, inventory_is_well_created)
{
    resource_t inv = create_inventory();

    cr_assert_eq(inv.food, 10);
}