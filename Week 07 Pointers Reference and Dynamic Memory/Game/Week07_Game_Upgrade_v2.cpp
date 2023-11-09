#include <iostream>
#include <conio.h>
#include <Windows.h>
#include <fstream>

using namespace std;
constexpr char kPlayerSymbol = '@';
constexpr char WAL = 219;
constexpr char KEY = 232;
constexpr char DOR = 179;
constexpr char GOL = 36;
constexpr int kOpenDoorColour = 10;
constexpr int kClosedDoorColour = 12;;
constexpr int kRegularDoorColour = 7;

int getIndexFromCoordinates(int x, int y, int width);
void drawLevel(char level[], int width, int height, int playerX, int playerY, bool playerHasKey);
bool updatePlayerPosition(char level [], int& playerX, int& playerY, int width, bool& playerHasKey);
void PlayDoorClosedSound();
void PlayDoorOpenSound();
void PlayKeyPickup();
void PlayWinSound();
char* loadLevel(string levelName, int& levelWidth, int& levelHeight);
bool ConvertLevel(char* level, int levelWidth, int levelHeight, int& playerX, int& playerY);

int main()
{
    int levelWidth = 25;
    int levelHeight = 15;

    char* levelArray = loadLevel("level1.txt", levelWidth, levelHeight);

    int playerX = 1;
    int playerY = 1;

    bool anyWarnings = ConvertLevel(levelArray, levelWidth, levelHeight, playerX, playerY);
    if (anyWarnings)
    {
        cout << "There were some warnings in the level data, see above." << endl;
        system("pause");
    }
    bool playerHasKey = false;

    bool gameOver = false;

    while (!gameOver)
    {
        system("cls");
        drawLevel(levelArray, levelWidth, levelHeight, playerX, playerY, playerHasKey);
        gameOver = updatePlayerPosition(levelArray, playerX, playerY, levelWidth, playerHasKey);
    }

    system("cls");
    drawLevel(levelArray, levelWidth, levelHeight, playerX, playerY, playerHasKey);
    cout << "You Win!" << endl;
    PlayWinSound();

    delete[] levelArray;
}

int getIndexFromCoordinates(int x, int y, int width)
{
    return x + y * width;
}

void drawLevel(char level[], int width, int height, int playerX, int playerY, bool playerHasKey)
{
    for (int y = 0; y < height; y++)
    {
        for (int x = 0; x < width; x++)
        {
            if ((playerX == x) && (playerY == y))
            {
                cout << kPlayerSymbol;
            }
            else
            {
                int indexToPrint = getIndexFromCoordinates(x, y, width);
                HANDLE console = GetStdHandle(STD_OUTPUT_HANDLE);
                if (level[indexToPrint] == DOR)
                {
                    if (playerHasKey)
                    {
                        SetConsoleTextAttribute(console, kOpenDoorColour);
                    }
                    else
                    {
                        SetConsoleTextAttribute(console, kClosedDoorColour);
                    }
                }
                else
                {
                    SetConsoleTextAttribute(console, kRegularDoorColour);
                }

                cout << level[indexToPrint];
            }
        }
        cout << endl;
    }
}

bool updatePlayerPosition(char level[], int& playerX, int& playerY, int width, bool& playerHasKey)
{
    char input = _getch();

    int newPlayerX = playerX;
    int newPlayerY = playerY;


    switch (input)
    {
        case 'w':
        case 'W': 
        {
            newPlayerY--;
            break;
        }
        case 's':
        case 'S':
        {
            newPlayerY++;
            break;
        }
        case 'a':
        case 'A':
        {
            newPlayerX--;
            break;
        }
        case 'd':
        case 'D':
        {
            newPlayerX++;
            break;
        }
        default:
        break;
    }

    int index = getIndexFromCoordinates(newPlayerX, newPlayerY, width);
    if (level[index] == ' ')
    {
        playerX = newPlayerX;
        playerY = newPlayerY;
    }
    else if (level[index] == KEY)
    {
        playerHasKey = true;
        level[index] = ' ';
        playerX = newPlayerX;
        playerY = newPlayerY;
        PlayKeyPickup();
    }
    else if (level[index] == DOR && playerHasKey)
    {
        level[index] = ' ';
        playerHasKey = false;
        playerX = newPlayerX;
        playerY = newPlayerY;
        PlayDoorOpenSound();

    }
    else if (level[index] == DOR && !playerHasKey)
    {
        PlayDoorClosedSound();
    }
    else if (level[index] == GOL)
    {
        level[index] = ' ';
        playerX = newPlayerX;
        playerY = newPlayerY;
        return true;
        PlayWinSound();
    }
    return false;
}

void PlayDoorClosedSound()
{
    Beep(500, 75);
    Beep(500, 75);
}
void PlayDoorOpenSound()
{
    Beep(1397, 200);
}
void PlayKeyPickup()
{
    Beep(1568, 75);
}
void PlayWinSound()
{
    Beep(1568, 200);
    Beep(1568, 200);
    Beep(1568, 200);
    Beep(1245, 1000);
    Beep(1397, 200);
    Beep(1397, 200);
    Beep(1397, 200);
    Beep(1175, 1000);
}
char* loadLevel(string levelName, int& levelWidth, int& levelHeight)
{
    levelName.insert(0, "../");
    ifstream levelFile;
    levelFile.open(levelName);
    if (!levelFile)
    {
        cout << "Opening file failed" << endl;
        return nullptr;
    }
    else
    {
        constexpr int tempSize = 25;
        char temp[tempSize];

        levelFile.getline(temp, tempSize, '\n');
        levelWidth = atoi(temp);

        levelFile.getline(temp, tempSize, '\n');
        levelHeight = atoi(temp);

        char* levelData = new char[levelWidth * levelHeight];
        levelFile.read(levelData, levelWidth * levelHeight);
        return levelData;
    }
}
bool ConvertLevel(char* level, int levelWidth, int levelHeight, int& playerX, int& playerY)
{
    bool anyWarnings = false;

    for (int y = 0; y < levelHeight; y++)
    {
        for (int x = 0; x < levelWidth; x++)
        {
            int index = getIndexFromCoordinates(x, y, levelWidth);

            switch (level[index])
            {
            case '+':
            case '-':
            case '|':
            case '_':
                level[index] = WAL;
                break;
            case '*':
                level[index] = KEY;
                break;
            case 'D':
                level[index] = DOR;
                break;
            case 'X':
                level[index] = GOL;
                break;
            case '@':
                level[index] = ' ';
                playerX = x;
                playerY = y;
                break;
            case ' ':
                break;
            default:
                cout << "Invalid character in levelfile." << level[index] << endl;
                anyWarnings = true;
                break;
            }

        }
    }
    return anyWarnings;
}