#include "Items.h"
#include <iostream>
#include <string>
void Items::UseItem(Player& player, Enemy& enemy, int index)
{
    IncDecHealth healthManager; // Create an instance of IncDecHealth
    if (index == 0) 
    {
        healthManager.e_HitDamage(enemy, enemy.p_bombDamage); // Access Damage through IncDecHealth instance
    }
    else if (index == 1) 
    {
        healthManager.p_Heal(player, player.potionHeal); // Access Heal through IncDecHealth instance
    }
}

void swap(std::string& a, std::string& b)
{
    std::string temp = a;
    a = b;
    b = temp;
}

void Items::SwapItem(Player& player, int index)
{
    if (index == 0)
    {
        if (*player.currentItem == "Bomb")
        {
            swap(*player.currentItem, player.inventory[1]); // Swap currentItem with inventory[1]
        }
        else
        {
            swap(*player.currentItem, player.inventory[0]); // Swap currentItem with inventory[0]
        }
    }
}