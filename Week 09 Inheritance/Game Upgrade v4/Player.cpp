#include "Player.h"
#include <iostream>

constexpr char kPlayerSymbol = '@';

Player::Player()
    : m_hasKey(false)
{
    totalHealth = new int(100);
    currentItem = new std::string("Bomb");
    numBombs = new int(5);
    numPotions = new int(2);
}

Player::~Player() 
{
    delete totalHealth;
    delete currentItem;
    delete numBombs;
    delete numPotions;
}

int Player::Health() 
{
    return *totalHealth;
}

void Player::PrintContents() 
{
    std::cout << "Total Health: " << *totalHealth << std::endl;
    std::cout << "Current Item: " << *currentItem << std::endl;
    std::cout << "Bombs: " << *numBombs << std::endl;
    std::cout << "Potions: " << *numPotions << std::endl;
}

void Player::SetPosition(int x, int y)
{
    m_position.x = x;
    m_position.y = y;
}

bool Player::HasKey()
{
    return m_hasKey;
}

void Player::PickupKey()
{
    m_hasKey = true;
}

void Player::UseKey()
{
    m_hasKey = false;
}

void Player::Draw()
{
    std::cout << kPlayerSymbol;
}