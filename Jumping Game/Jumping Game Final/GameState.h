#pragma once

//Updatable
class GameState
{
public:
	virtual ~GameState() {}

	virtual void Enter() {} //when a state is starting
	virtual bool Update(bool processInput = true) //depending on the input, the state may or may not need updating
	{
		return false;
	}
	virtual void ProcessInput() { } //input function
	virtual void Draw() = 0; //write up on screen
	virtual void Exit() {} //when you want to end a state
};

//This state is used as practically the "foundation" of the game states. Each state will need an enter, update, input, draw and exit function.



//Explaining states:

//State design patterns enable us to encapsulate an objects behaviour into a series of seperate objects, which are called states and are independent from each other

//We will be using states to create different screens for the game