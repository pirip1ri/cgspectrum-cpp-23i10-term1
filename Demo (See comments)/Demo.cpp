#include <iostream>
#include "Player.h"
#include "Enemy.h"
#include "Game.h"
#include "IncDecHealth.h"
#include "Items.h"
#include "Level.h"
#include "Point.h"

int main()
{
	Game myGame;

	if (myGame.Load())
	{
		while (!myGame.IsGameOver())
		{
			myGame.Run();
		}
		std::cout << "You Win!" << std::endl;
		//PlayWinSound()
	}
	else
	{
		std::cout << "Game did not load. Terminating program." << std::endl;
	}
}

// Edit demo so that you can piece all of the elements together.
// 
//Implement retrieving key from enemy and using it to open a door