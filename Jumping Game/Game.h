#pragma once
#include "Player.h"
#include "Level.h"
#include "PlacableActor.h"
#include <fstream>

class Game
{
protected:
	Player m_player;
	Level m_level;
	bool m_isGameOver;
	bool m_UserQuit;
	bool m_FloorBelow;
	bool m_Jumping;
	bool m_floating;

public:
	Game();
	~Game();

	bool Load();
	void Run();

	bool IsGameOver();
	bool DidUserQuit()
	{
		return m_UserQuit;
	}
	int GetPlayerLives()
	{
		return m_player.GetLives();
	}

private:
	bool Update();
	void Draw();

	bool HandleCollision(int newPlayerX, int newPlayerY);
};