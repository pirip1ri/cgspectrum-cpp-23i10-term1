#pragma once
#include <string>
#include "Point.h"

class Player 
{
    Point m_position;
    bool m_hasKey;
public:
    
    Player(); // Constructor
    ~Player(); // Destructor
    
    int Health(); //The total amount of health the player has
    void PrintContents();// Prints the player's total health, and the quantities of bombs/potions the player has.

    int GetXPosition()
    {
        return m_position.x;
    }
    int GetYPosition()
    {
        return m_position.y;
    }

    int* GetXPositionPointer()
    {
        return &(m_position.x);
    }
    int* GetYPositionPointer()
    {
        return &(m_position.y);
    }
   
    void SetPosition(int x, int y);

    bool HasKey();
    void PickupKey();
    void UseKey();

    void Draw();

private:
    int* totalHealth;
    std::string* currentItem;
    int* numBombs;
    int* numPotions;
    const int potionHeal = 10;
    std::string inventory[2];

    //friend function allows other classes to use private items
    friend class Items; // Grant access to Items class
    friend class IncDecHealth; // Grant access to IncDecHealth class
};


