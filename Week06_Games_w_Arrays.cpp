#include <iostream>
#include <conio.h>

using namespace std;
constexpr char kPlayerSymbol = '@';

int getIndexFromCoordinates(int x, int y, int width);
void drawLevel(char level[], int width, int height, int playerX, int playerY);
bool updatePlayerPosition(char level [], int& playerX, int& playerY, int width, bool& playerHasKey);

int main()
{
    constexpr int kwidth = 25;
    constexpr int kheight = 15;

    char levelArray[]{ '+', '-', '-', '-', '-', '-', '-', '-', '-', '-', '-', '-', '-', '-', '-', '-', '-', '-', '-', '-', '-', '-', '-', '-', '+',
                       '|', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', '|', ' ', '*', '|',
                       '|', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', '|', ' ', ' ', '|',
                       '|', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', '|', ' ', ' ', '|',
                       '|', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', '+', '-', ' ', '|',
                       '|', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', '|',
                       '|', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', '|',
                       '|', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', '|',
                       '|', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', '|',
                       '|', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', '|',
                       '|', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', '+', '-', '-', '-', '-', '-', '-', '-', '-', '-', '|',
                       '|', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', '|', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', '|',
                       '|', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', '|', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', '|',
                       '|', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', 'D', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', 'X', '|',
                       '+', '-', '-', '-', '-', '-', '-', '-', '-', '-', '-', '-', '-', '-', '-', '-', '-', '-', '-', '-', '-', '-', '-', '-', '+'
    };

    int playerX = 1;
    int playerY = 1;

    bool playerHasKey = false;

    bool gameOver = false;

    while (!gameOver)
    {
        system("cls");
        drawLevel(levelArray, kwidth, kheight, playerX, playerY);
        gameOver = updatePlayerPosition(levelArray, playerX, playerY, kwidth, playerHasKey);
    }

    system("cls");
    drawLevel(levelArray, kwidth, kheight, playerX, playerY);
    cout << "You Win!" << endl;
}

int getIndexFromCoordinates(int x, int y, int width)
{
    return x + y * width;
}

void drawLevel(char level[], int width, int height, int playerX, int playerY)
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
                int index = getIndexFromCoordinates(x, y, width);
                cout << level[index];
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
    else if (level[index] == '*')
    {
        playerHasKey = true;
        level[index] = ' ';
        playerX = newPlayerX;
        playerY = newPlayerY;
    }
    else if (level[index] == 'D' && playerHasKey)
    {
        level[index] = ' ';
        playerHasKey = false;
        playerX = newPlayerX;
        playerY = newPlayerY;
    }
    else if (level[index] == 'X')
    {
        level[index] = ' ';
        playerX = newPlayerX;
        playerY = newPlayerY;
        return true;
    }
    return false;
}