#include <iostream>
#include "Game.h"
#include "AudioManager.h"

using namespace std;

//void PlayDoorClosedSound();
//void PlayDoorOpenSound();
//void PlayKeyPickup();
//void PlayWinSound();

int main()
{
	Game myGame;

	if (myGame.Load())
	{
		while (!myGame.IsGameOver())
		{
			myGame.Run();
		}
		if (myGame.DidUserQuit())
		{
			cout << "Thanks for Playing!" << endl;
		}
		else if (myGame.GetPlayerLives() <= 0)
		{
			cout << "You Lose!" << endl;
			AudioManager::GetInstance()->PlayLoseSound();
		}
		else
		{
			cout << "You Win!" << endl;
			AudioManager::GetInstance()->PlayWinSound();
		}
	}
	else
	{
		cout << "Game did not load. Terminating program." << endl;
	}

	AudioManager::DestroyInstance();

	return 0;
}

