#pragma once
#include <string>

class Enemy
{
public:

    Enemy(); // Constructor
    ~Enemy(); // Destructor

    int Health(); //The total amount of health the enemy has
    
private:
    int* totalHealth;
    const int e_attackDamage = 15;
    const int p_bombDamage = 30;

    //friend function allows other classes to use private items
    friend class Items; // Grant access to Items class
    friend class IncDecHealth; // Grant access to IncDecHealth class
};
