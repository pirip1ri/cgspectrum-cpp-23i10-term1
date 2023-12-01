#include <iostream>
#include "Game.h"

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
			//PlayLoseSound();
		}
		else
		{
			cout << "You Win!" << endl;
			//PlayWinSound();
		}
	}
	else
	{
		cout << "Game did not load. Terminating program." << endl;
	}
}

//void PlayDoorClosedSound()
//{
//    Beep(500, 75);
//    Beep(500, 75);
//}
//void PlayDoorOpenSound()
//{
//    Beep(1397, 200);
//}
//void PlayKeyPickup()
//{
//    Beep(1568, 75);
//}
//void PlayWinSound()
//{
//    Beep(1568, 200);
//    Beep(1568, 200);
//    Beep(1568, 200);
//    Beep(1245, 1000);
//    Beep(1397, 200);
//    Beep(1397, 200);
//    Beep(1397, 200);
//    Beep(1175, 1000);
//}
