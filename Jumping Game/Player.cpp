#include "Player.h"
#include <iostream>

using namespace std;

constexpr char kStartingNumberOfLives = 3;

Player::Player()
	:PlacableActor(0, 0)
	, m_pCurrentKey(nullptr)
	, m_money(0)
	, m_lives(kStartingNumberOfLives)
{

}

bool Player::HasKey()
{
	return m_pCurrentKey != nullptr;
}

bool Player::HasKey(int colour)
{
	return HasKey() && m_pCurrentKey->GetColour() == colour;
}

void Player::PickUpKey(Key* key)
{
	m_pCurrentKey = key;
}

void Player::UseKey()
{
	m_pCurrentKey->Remove();
	m_pCurrentKey = nullptr;
}

void Player::DropKey()
{

}

void Player::Draw()
{
	cout << "@" << endl;
}