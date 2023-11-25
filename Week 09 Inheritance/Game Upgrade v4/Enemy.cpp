#include "Enemy.h"
#include <iostream>

Enemy::Enemy()
{
	totalHealth = new int(30);
}

Enemy::~Enemy()
{
	delete totalHealth;
}

int Enemy::Health()
{
	return *totalHealth;
}