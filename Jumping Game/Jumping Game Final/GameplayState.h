#pragma once
#include "GameState.h"
#include "Player.h"

#include <windows.h>
#include <vector>
#include <string>

namespace std
{
	class thread;
}

class Level;
class StateMachineExampleGame;

class GameplayState : public GameState
{
	StateMachineExampleGame* m_pOwner; //Manages interactions from player's input

	Player m_player; //Manages what the player's charcter does pending player's input
	Level* m_pLevel; //Manages level and updating it pending variables
	bool m_FloorBelow;
	bool m_Jumping;
	bool m_floating;

	bool m_didBeatLevel; //Whether the level is complete or not
	int m_skipFrameCount; 
	static constexpr int kFramesToSkip = 2;

	int m_currentLevel;

	std::vector<std::string> m_LevelNames;

public:
	GameplayState(StateMachineExampleGame* pOwner);
	~GameplayState();

	virtual void Enter() override; //Loads game
	virtual bool Update(bool processInput = true) override; //Calls for: updates actors, check collisions, check if the level has been beaten
	virtual void Draw() override; //Draws level
	void ProcessInput() override; //Controls e.g. movement

protected:
	void CheckBeatLevel();

	bool m_shouldProcessInput = true;
	std::thread* m_inputThread = nullptr;
private:
	void HandleCollision(int newPlayerX, int newPlayerY);
	bool Load(); //Loads the level of the game, ready to be drawn, checks for errors
	void DrawHUD(const HANDLE& console); // Draws the HUD
};

//This class is an instance of a state. This is specifically the gameplay state. It manages what happens during gameplay.
