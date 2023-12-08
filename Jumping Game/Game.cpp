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
#include "Movement.h"

using namespace std;
constexpr int kEscapeKey = 27;
constexpr int kViewportWidth = 36;
constexpr int kViewportHeight = 14;

Movement movement;
bool FacingLeft = false;
bool FacingRight = false;

Game::Game()
    : m_isGameOver(false)
    , m_FloorBelow(true)
    , m_Jumping(false)
    , m_UserQuit(false)
    , m_floating(false)
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



    switch (input)
    {
    case 'w':
    case 'W':
    {
        movement.MovingUp(newPlayerX, newPlayerY, m_FloorBelow, m_Jumping, m_floating);
        break;
    }
    case 's':
    case 'S':
    {
        m_Jumping = false;
        m_floating = false;
        newPlayerY++;

        break;
    }
    case 'a':
    case 'A':
    {
        movement.MovingLeft(newPlayerX, newPlayerY, m_FloorBelow, m_Jumping, m_floating);
        FacingLeft = true;
        break;
    }
    case 'd':
    case 'D':
    {
        movement.MovingRight(newPlayerX, newPlayerY, m_FloorBelow, m_Jumping, m_floating);
        FacingRight = true;
        break;
    }
    case 'Q':
    case 'q':
    {
        if (FacingLeft || FacingRight)
        {
            m_bullet.Activate(m_player.GetXPosition(), m_player.GetYPosition());
        }
        break;
    }
    default:
        break;
    }

    if (input == kEscapeKey)
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

    int viewportLeft = m_player.GetXPosition() - kViewportWidth / 2; //Where the draw mechanic will start from in the array
    int viewportTop = m_player.GetYPosition() - kViewportHeight / 2; //Where the draw mechanic will start from in the array

    // Ensure the viewport boundaries stay within the level bounds
    if (viewportLeft < 0) //Keeps the viewport from leaving the array on the left
    {
        viewportLeft = 0;
    }
    else if (viewportLeft + kViewportWidth > m_level.GetWidth()) //Keeps the viewport from leaving the array on the right
    {
        viewportLeft = m_level.GetWidth() - kViewportWidth;
    }

    if (viewportTop < 0)
    {
        viewportTop = 0;
    }
    else if (viewportTop + kViewportHeight > m_level.GetHeight())
    {
        viewportTop = m_level.GetHeight() - kViewportHeight;
    }

    m_level.Draw(viewportLeft, viewportTop, kViewportWidth, kViewportHeight);

    COORD actorCursorPosition;
    actorCursorPosition.X = m_player.GetXPosition() - viewportLeft;
    actorCursorPosition.Y = m_player.GetYPosition() - viewportTop;
    SetConsoleCursorPosition(console, actorCursorPosition);
    m_player.Draw();

    m_bullet.UpdateBullet(FacingLeft, FacingRight);
}

bool Game::HandleCollision(int newPlayerX, int newPlayerY)
{
    bool isGameDone = false;

    if (m_level.IsWall(newPlayerX, (newPlayerY + 1)))
    {
        m_FloorBelow = true;
    }
    else
    {
        m_FloorBelow = false;
    }

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


