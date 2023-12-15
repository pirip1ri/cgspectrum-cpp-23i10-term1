#pragma once
#include "GameStateMachine.h"
#include "Player.h"
#include "Level.h"

class Game
{
	GameStateMachine* m_pStateMachine;
public:
	Game();
	void Initialize(GameStateMachine* pStateMachine);
	void RunGameLoop();
	void Deinitialize();

private:
	bool Update(bool processInput = true);
	void Draw();
};

// This class calls for certain functions e.g. draw, update, etc. pending on certain variables, e.g. isGameOver, during the Game state