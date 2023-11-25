#include "IncDecHealth.h"

void IncDecHealth::p_HitDamage(Player& player, int amount) //Decreases the health of the Player's health by x amount
{
    *player.totalHealth -= amount;
}

void IncDecHealth::p_Heal(Player& player, int amount) //Increases the health of the Player's health by y amount
{
    *player.totalHealth += amount;
}

void IncDecHealth::e_HitDamage(Enemy& enemy, int amount) //Decreases the health of the Enemy's health by z amount
{
    *enemy.totalHealth -= amount;
}

