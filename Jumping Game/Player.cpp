#include "Player.h"
#include "AudioManager.h"
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

bool Player::HasKey(ActorColour colour)
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
	if (m_pCurrentKey)
	{
		AudioManager::GetInstance()->PlayKeyDropSound();
		m_pCurrentKey->Place(m_pPosition->x, m_pPosition->y);
		m_pCurrentKey = nullptr;
	}
}

void Player::Draw()
{
	cout << "@" << endl;
}