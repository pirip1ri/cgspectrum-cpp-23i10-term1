#pragma once

class GameState;

class GameStateMachine
{
public:
	virtual ~GameStateMachine() = default;

	virtual bool Init() = 0; //initialise the state
	virtual bool UpdateCurrentState(bool processInput = true) = 0; //update the current state
	virtual void DrawCurrentState() = 0; //draw the current state
	virtual void ChangeState(GameState* pNewState) = 0; //shift from one state to the other
	virtual bool Cleanup() = 0; //clears the screen
};

//While all the different states will be inherited through GameState, the game we will be running will...
//...inherit from this GameStateMachine
