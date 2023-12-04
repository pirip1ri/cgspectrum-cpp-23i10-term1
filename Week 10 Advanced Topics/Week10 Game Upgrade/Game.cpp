#include <conio.h>
#include <windows.h>
#include <assert.h>
#include <thread>

#include "Game.h"
#include "Enemy.h"
#include "Key.h"
#include "Door.h"
#include "Goal.h"
#include "Money.h"
#include "AudioManager.h"

using namespace std;

constexpr int kOpenDoorColour = 10;
constexpr int kClosedDoorColour = 12;;
constexpr int kRegularDoorColour = 7;

constexpr int kArrowInput = 224;
constexpr int kLeftArrow = 75;
constexpr int kRightArrow = 77;
constexpr int kUpArrow = 72;
constexpr int kDownArrow = 80;
constexpr int kEscapeKey = 27;


Game::Game()
    : m_isGameOver(false)
{

}

Game::~Game()
{

}

bool Game::Load()
{
    return m_level.Load("Level1.txt", m_player.GetXPositionPointer(), m_player.GetYPositionPointer());
}

void Game::Run()
{
    Draw();

    m_isGameOver = Update();

    if (m_isGameOver)
    {
        Draw();
    }
}

bool Game::IsGameOver()
{
    return m_isGameOver;
}

bool Game::Update()
{
    int input = _getch();
    int arrowInput = 0;
    int newPlayerX = m_player.GetXPosition();
    int newPlayerY = m_player.GetYPosition();

    if (input == kArrowInput)
    {
        arrowInput = _getch();
    }

    if ((input == kArrowInput && arrowInput == kLeftArrow) || (char)input == 'A' || (char)input == 'a')
    {
        newPlayerX--;
    }

    else if ((input == kArrowInput && arrowInput == kRightArrow) || (char)input == 'D' || (char)input == 'd')
    {
        newPlayerX++;
    }

    else if ((input == kArrowInput && arrowInput == kUpArrow) || (char)input == 'W' || (char)input == 'w')
    {
        newPlayerY--;
    }

    else if ((input == kArrowInput && arrowInput == kDownArrow) || (char)input == 'S' || (char)input == 's')
    {
        newPlayerY++;
    }


    else if (input == kEscapeKey)
    {
        m_UserQuit = true;
        return true;
    }

    else if ((char)input == 'Z' || (char)input == 'z')
    {
        m_player.DropKey();
    }

    if (newPlayerX == m_player.GetXPosition() && newPlayerY == m_player.GetYPosition())
    {
        return false;
    }
    else
    {
        return HandleCollision(newPlayerX, newPlayerY);
    }
}

void Game::Draw()
{
    HANDLE console = GetStdHandle(STD_OUTPUT_HANDLE);
    system("cls");

    m_level.Draw();

    // Set cursor position for player 
    COORD actorCursorPosition;
    actorCursorPosition.X = m_player.GetXPosition();
    actorCursorPosition.Y = m_player.GetYPosition();
    SetConsoleCursorPosition(console, actorCursorPosition);
    m_player.Draw();

    // Set the cursor to the end of the level
    COORD currentCursorPosition;
    currentCursorPosition.X = 0;
    currentCursorPosition.Y = m_level.GetHeight();
    SetConsoleCursorPosition(console, currentCursorPosition);
}

bool Game::HandleCollision(int newPlayerX, int newPlayerY)
{
    bool isGameDone = false;
    PlacableActor* collidedActor = m_level.UpdateActors(newPlayerX, newPlayerY);
    if (collidedActor != nullptr && collidedActor->IsActive())
    {
		switch (collidedActor->GetType())
		{
		case ActorType::Enemy:
		{
			Enemy* collidedEnemy = dynamic_cast<Enemy*>(collidedActor);
			assert(collidedEnemy);
			AudioManager::GetInstance()->PlayLoseLivesSound();
			collidedEnemy->Remove();
			m_player.SetPosition(newPlayerX, newPlayerY);

			m_player.DecrementLives();
			if (m_player.GetLives() < 0)
			{
				isGameDone = true;
			}
			break;
		}
		case ActorType::Money:
		{
			Money* collidedMoney = dynamic_cast<Money*>(collidedActor);
			assert(collidedMoney);
			AudioManager::GetInstance()->PlayMoneySound();
			collidedMoney->Remove();
			m_player.AddMoney(collidedMoney->GetWorth());
			m_player.SetPosition(newPlayerX, newPlayerY);
			break;
		}
		case ActorType::Key:
		{
			Key* collidedKey = dynamic_cast<Key*>(collidedActor);
			assert(collidedKey);
			if (!m_player.HasKey())
			{
				m_player.PickUpKey(collidedKey);
				collidedKey->Remove();
				m_player.SetPosition(newPlayerX, newPlayerY);
				AudioManager::GetInstance()->PlayKeyPickupSound();
			}
			break;
		}
		case ActorType::Door:
		{
			Door* collidedDoor = dynamic_cast<Door*>(collidedActor);
			assert(collidedDoor);
			if (!collidedDoor->IsOpen())
			{
				if (m_player.HasKey(collidedDoor->GetColour()))
				{
					collidedDoor->Open();
					collidedDoor->Remove();
					m_player.UseKey();
					m_player.SetPosition(newPlayerX, newPlayerY);
					AudioManager::GetInstance()->PlayDoorOpenSound();
				}
				else
				{
					AudioManager::GetInstance()->PlayDoorClosedSound();
				}
			}
			else
			{
				m_player.SetPosition(newPlayerX, newPlayerY);
			}
			break;
		}
		case ActorType::Goal:
		{
			Goal* collidedGoal = dynamic_cast<Goal*>(collidedActor);
			assert(collidedGoal);
			collidedGoal->Remove();
			m_player.SetPosition(newPlayerX, newPlayerY);
            isGameDone = true;
			break;
		}
		default:
			break;
		}
    }
    else if (m_level.IsSpace(newPlayerX, newPlayerY)) // no collision
    {
        m_player.SetPosition(newPlayerX, newPlayerY);
    }
    else if (m_level.IsWall(newPlayerX, newPlayerY))
    {
        //collide with wall, do nothing.
    }
    return isGameDone;
}
