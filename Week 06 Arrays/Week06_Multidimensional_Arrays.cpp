#include <iostream>

using namespace std;

void displayMap(char map[], int width, int height);

int getIndexFromXY(int x, int y, int width);

int main()
{
    constexpr int kHeight = 5;
    constexpr int kWidth = 6;

    char myMap[] = { '+', '-','-','-','-','+',
                     '|', '@',' ',' ',' ','|',
                     '|', ' ',' ',' ',' ','|',
                     '|', ' ',' ',' ',' ','|',
                     '+', '-','-','-','-','+',
    };
    displayMap(myMap, kWidth, kHeight);
}

void displayMap(char map[], int width, int height)
{
    for (int y = 0; y < height; y++)
    {
        for (int x = 0; x < width; x++)
        {
            int index = getIndexFromXY(x, y, width);
            cout << map[index];
        }
        cout << endl;
    }
}

int getIndexFromXY(int x, int y, int width)
{
    return x + y * width;
}