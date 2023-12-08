#include <windows.h>
#include <assert.h>
#include <iostream>
#include <fstream>
#include "Level.h"
#include "Player.h"
#include "Enemy.h"
#include "Key.h"
#include "Door.h"
#include "Goal.h"
#include "Money.h"

using namespace std;

constexpr char WAL = (char)219;
constexpr char kTopRightBorder = (char)187;
constexpr char kTopLeftBorder = (char)201;
constexpr char kBottomRightBorder = (char)188;
constexpr char kBottomLeftBorder = (char)200;
constexpr char kHorizontalBorder = (char)205;
constexpr char kVerticalBorder = (char)186;

Level::Level()
	: m_pLevelData(nullptr)
	, m_height(0)
	, m_width(0)
{

}

Level::~Level()
{
	if (m_pLevelData != nullptr)
	{
		delete[] m_pLevelData;
		m_pLevelData = nullptr;
	}

	while (!m_pActors.empty())
	{
		delete m_pActors.back();
		m_pActors.pop_back();
	}
}

bool Level::Load(std::string levelName, int* playerX, int* playerY)
{
	levelName.insert(0, "../");
	ifstream levelFile;
	levelFile.open(levelName);
	if (!levelFile)
	{
		cout << "Opening file failed: " << levelName << endl;
		return false;
	}
	else
	{
		constexpr int tempSize = 25;
		char temp[tempSize];

		// Read width
		levelFile.getline(temp, tempSize, '\n');
		m_width = atoi(temp);

		// Read height 
		levelFile.getline(temp, tempSize, '\n');
		m_height = atoi(temp);

		// Read level
		m_pLevelData = new char[m_width * m_height];
		levelFile.read(m_pLevelData, (long long)m_width * (long long)m_height);

		// Convert level
		bool anyWarnings = ConvertLevel(playerX, playerY);
		if (anyWarnings)
		{
			cout << "There were some warnings in the level data, see above." << endl;
			system("pause");
		}
		return true;
	}
}

void Level::Draw(int viewportLeft, int viewportTop, int viewportWidth, int viewportHeight)
{
	HANDLE console = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleTextAttribute(console, (int)ActorColour::RegularColour);

	DisplayTopBorder(m_width);
	for (int y = viewportTop; y < viewportTop + viewportHeight; ++y) // y < viewportTop + viewportHeight is the same as saying viewportTop <= y < viewportHeight
	{
		DisplayLeftBorder();
		for (int x = viewportLeft; x < viewportLeft + viewportWidth; ++x) // same with x
		{
			if (x >= 0 && x < m_width && y >= 0 && y < m_height) // so long as x and y are in the array
			{
				int indexToPrint = GetIndexFromCoordinates(x, y);
				cout << m_pLevelData[indexToPrint]; // print out the array at that position
			}
		}
		DisplayRightBorder();
		cout << endl; // next line
	}
	DisplayBottomBorder(m_width);

	COORD actorCursorPosition;

	// Draw actors within the viewport
	for (auto actor = m_pActors.begin(); actor != m_pActors.end(); ++actor)
	{
		if ((*actor)->IsActive() && (*actor)->GetXPosition() >= viewportLeft && (*actor)->GetXPosition() < viewportLeft + viewportWidth &&
			(*actor)->GetYPosition() >= viewportTop && (*actor)->GetYPosition() < viewportTop + viewportHeight)
		{
			actorCursorPosition.X = (*actor)->GetXPosition() - viewportLeft;
			actorCursorPosition.Y = (*actor)->GetYPosition() - viewportTop;
			SetConsoleCursorPosition(console, actorCursorPosition);
			(*actor)->Draw();
		}
	}
}

bool Level::IsSpace(int x, int y)
{
	return m_pLevelData[GetIndexFromCoordinates(x, y)] == ' ';
}

bool Level::IsWall(int x, int y)
{
	return m_pLevelData[GetIndexFromCoordinates(x, y)] == WAL;
}

PlacableActor* Level::UpdateActors(int x, int y)
{
	PlacableActor* collidedActor = nullptr;

	for (auto actor = m_pActors.begin(); actor != m_pActors.end(); ++actor)
	{
		if (!(*actor)->IsActive())
		{
			continue;
		}

		if (x == (*actor)->GetXPosition() && y == (*actor)->GetYPosition())
		{
			// should only be able to collide with one actor
			assert(collidedActor == nullptr);
			collidedActor = (*actor);
		}
	}

	return collidedActor;
}

bool Level::ConvertLevel(int* playerX, int* playerY)
{
	bool anyWarnings = false;
	for (int y = 0; y < m_height; ++y)
	{
		for (int x = 0; x < m_width; ++x)
		{
			int index = GetIndexFromCoordinates(x, y);
			switch (m_pLevelData[index])
			{
			case '+':
			case '|':
			case '-':
				m_pLevelData[index] = WAL;
				break;
			case 'r':
				m_pLevelData[index] = ' ';
				m_pActors.push_back(new Key(x, y, ActorColour::RedColour));
				break;
			case 'g':
				m_pLevelData[index] = ' ';
				m_pActors.push_back(new Key(x, y, ActorColour::GreenColour));
				break;
			case 'b':
				m_pLevelData[index] = ' ';
				m_pActors.push_back(new Key(x, y, ActorColour::BlueColour));
				break;
			case 'R':
				m_pLevelData[index] = ' ';
				m_pActors.push_back(new Door(x, y, ActorColour::RedColour, ActorColour::RedColourSolid));
				break;
			case 'G':
				m_pLevelData[index] = ' ';
				m_pActors.push_back(new Door(x, y, ActorColour::GreenColour, ActorColour::GreenColourSolid));
				break;
			case 'B':
				m_pLevelData[index] = ' ';
				m_pActors.push_back(new Door(x, y, ActorColour::BlueColour, ActorColour::BlueColourSolid));
				break;
			case 'X':
				m_pLevelData[index] = ' ';
				m_pActors.push_back(new Goal(x, y));
				break;
			case '$':
				m_pLevelData[index] = ' ';
				m_pActors.push_back(new Money(x, y, 1 + rand() % 5));
				break;
			case '@':
				m_pLevelData[index] = ' ';
				if (playerX != nullptr && playerY != nullptr)
				{
					*playerX = x;
					*playerY = y;
				}
				break;
			case 'e':
				m_pActors.push_back(new Enemy(x, y));
				m_pLevelData[index] = ' '; // clear the level
				break;
			case 'h':
				m_pActors.push_back(new Enemy(x, y, 3, 0));
				m_pLevelData[index] = ' '; // clear the level
				break;
			case 'v':
				m_pLevelData[index] = ' ';
				m_pActors.push_back(new Enemy(x, y, 0, 2));
				m_pLevelData[index] = ' '; // clear the level
				break;
				break;
			case ' ':
				break;
			default:
				cout << "Invalid character in level file: " << m_pLevelData[index] << endl;
				anyWarnings = true;
				break;
			}
		}
	}

	return anyWarnings;
}

int Level::GetIndexFromCoordinates(int x, int y)
{
	return x + y * m_width;
}

PlacableActor* Level::CheckForCollision(int x, int y)
{
	PlacableActor* collidedActor = nullptr;

	for (auto actor = m_pActors.begin(); actor != m_pActors.end(); ++actor)
	{
		if (!(*actor)->IsActive())
		{
			continue;
		}

		if (x == (*actor)->GetXPosition() && y == (*actor)->GetYPosition())
		{
			// should only be able to collide with one actor
			assert(collidedActor == nullptr);
			collidedActor = (*actor);
		}
	}

	return collidedActor;
}

void DisplayTopBorder(int width)
{
	cout << kTopLeftBorder;
	for (int i = 0; i < width; i++)
	{
		cout << kHorizontalBorder;
	}
	cout << kTopRightBorder << endl;
}

void DisplayBottomBorder(int width)
{
	cout << kBottomLeftBorder;
	for (int i = 0; i < width; i++)
	{
		cout << kHorizontalBorder;
	}
	cout << kBottomRightBorder << endl;
}
void DisplayLeftBorder()
{
	cout << kVerticalBorder;
}
void DisplayRightBorder()
{
	cout << kVerticalBorder << endl;
}