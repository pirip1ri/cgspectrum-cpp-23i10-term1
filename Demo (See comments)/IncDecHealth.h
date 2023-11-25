#pragma once
#include "Player.h"
#include "Enemy.h"

class IncDecHealth 
{
public:
    void p_HitDamage(Player& player, int amount);

    void p_Heal(Player& player, int amount);

    void e_HitDamage(Enemy& enemy, int amount);
};