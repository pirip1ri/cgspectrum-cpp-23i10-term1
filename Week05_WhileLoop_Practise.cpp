#include <iostream>

using namespace std;
int main()
{
    cout << "Enter rows" << endl;
    int rows;
    cin >> rows;

    cout << "Enter columns" << endl;
    int columns;
    cin >> columns;

    int currentColumn = 0;
    while (currentColumn < columns)
    {
        int currentRow = 0;
        while (currentRow < rows)
        {
            cout << '#';
            currentRow++;
        }
        cout << endl;
        currentColumn++;
    }
}

