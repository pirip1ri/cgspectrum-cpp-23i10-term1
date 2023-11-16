#include <iostream>
#include <fstream>
#include <Windows.h>
#include "Level.h"

using namespace std;

constexpr char WAL = (char)219;
constexpr char KEY = (char)232;
constexpr char DOR = (char)179;
constexpr char GOL = (char)36;

Level::Level()
	:m_plevelData(nullptr)
	,m_height(0)
	,m_width(0)
{

}

Level::~Level()
{
	if (m_plevelData != nullptr)
	{
		delete[] m_plevelData;
		m_plevelData = nullptr;
	}
}

bool Level::Load(std::string levelName, int* playerX, int* playerY)
{
    levelName.insert(0, "../");
    ifstream levelFile;
    levelFile.open(levelName);
    if (!levelFile)
    {
        cout << "Opening file failed" << endl;
        return false;
    }
    else
    {
        constexpr int tempSize = 25;
        char temp[tempSize];

        levelFile.getline(temp, tempSize, '\n');
        m_width = atoi(temp);

        levelFile.getline(temp, tempSize, '\n');
        m_height = atoi(temp);

        char* m_plevelData = new char[m_width * m_height];
        levelFile.read(m_plevelData,(long long) m_width * (long long) m_height);
    }

    bool anyWarnings = Convert(playerX, playerY);
    if (anyWarnings)
    {
        cout << "There were some warnings in the level data, see above." << endl;
        system("pause");
    }
    return true;

}

void Level::Draw(int x, int y)
{
    int index = GetIndexFromCoordinates(x, y);
    cout << m_plevelData[index];
}

bool Level::isSpace(int x, int y)
{
    return m_plevelData[GetIndexFromCoordinates(x, y)] == ' ';
}

bool Level::isDoor(int x, int y)
{
    return m_plevelData[GetIndexFromCoordinates(x, y)] == DOR;
}

bool Level::isKey(int x, int y)
{
    return m_plevelData[GetIndexFromCoordinates(x, y)] == KEY;
}

bool Level::isGoal(int x, int y)
{
    return m_plevelData[GetIndexFromCoordinates(x, y)] == GOL;
}

void Level::PickupKey(int x, int y)
{
    m_plevelData[GetIndexFromCoordinates(x, y)] == ' ';
}

void Level::OpenDoor(int x, int y)
{
    m_plevelData[GetIndexFromCoordinates(x, y)] == ' ';
}

bool Level::Convert(int* playerX, int* playerY)
{
    bool anyWarnings = false;

    for (int y = 0; y < m_height; y++)
    {
        for (int x = 0; x < m_width; x++)
        {
            int index = GetIndexFromCoordinates(x, y);

            switch (m_plevelData[index])
            {
            case '+':
            case '-':
            case '|':
            case '_':
                m_plevelData[index] = WAL;
                break;
            case '*':
                m_plevelData[index] = KEY;
                break;
            case 'D':
                m_plevelData[index] = DOR;
                break;
            case 'X':
                m_plevelData[index] = GOL;
                break;
            case '@':
                m_plevelData[index] = ' ';
                if (playerX != nullptr && playerY != nullptr)
                {
                    *playerX = x;
                    *playerY = y;
                }
                break;
            case ' ':
                break;
            default:
                cout << "Invalid character in levelfile." << m_plevelData[index] << endl;
                anyWarnings = true;
                break;
            }

        }
    }
}
int Level::GetIndexFromCoordinates(int x, int y)
{
     return x + y * m_width;
}
