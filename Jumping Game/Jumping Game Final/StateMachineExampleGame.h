#pragma once
#include "GameStateMachine.h"

class Game;
class GameState;

class StateMachineExampleGame : public GameStateMachine
{
public:
	enum class SceneName //all the different states
	{
		None,
		MainMenu,
		Gameplay,
		Settings,
		HighScore,
		Lose,
		Win,
	};

private:
	Game* m_pOwner; //Instance of "game". Pending on which state the player is in, the player will need to be able to interact with the game. 

	GameState* m_pCurrentState; //Instance of what state the game is in
	GameState* m_pNextState; //Instance of which state the player wants to go to next

public:
	StateMachineExampleGame(Game* pOwner);

	virtual bool Init() override; //Initialiser (main menu)
	virtual bool UpdateCurrentState(bool processInput = true) override; //if m_pNextState, starts "ChangeState" function, and sets m_pNextstate to nullptr
	virtual void DrawCurrentState() override; //draws the current state on screen
	virtual void ChangeState(GameState* pNewState) override; // deletes current state, and sets current state to next state
	void LoadScene(SceneName scene); //pending scenename above, it will load any of the states specified
	virtual bool Cleanup() override;
};

//In general, this class allows the selection of different states.