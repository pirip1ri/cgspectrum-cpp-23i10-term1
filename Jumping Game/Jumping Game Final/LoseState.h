#pragma once
#include "GameState.h"

class StateMachineExampleGame;

class LoseState : public GameState
{
	StateMachineExampleGame* m_pOwner;

public:
	LoseState(StateMachineExampleGame* pOwner);
	~LoseState() = default;

	virtual bool Update(bool processInput = true) override;
	virtual void Draw() override;
};

//State when the player loses all lives, returning to main menu state after