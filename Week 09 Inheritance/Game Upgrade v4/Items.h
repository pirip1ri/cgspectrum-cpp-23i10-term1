#pragma once
#include "Player.h"
#include"Enemy.h"
#include "IncDecHealth.h"

class Items 
{
public:
	std::string& CurrentItem(Player& player);
	
	void UseItem(Player& player, Enemy& enemy, int index); //Use the item currently in use. This can be a bomb that will subsequently decrease the player's health, or a potion that will increase the players health.

	void SwapItem(Player& player, int index); //A function to switch between the bomb item and the potion item.
};
	



