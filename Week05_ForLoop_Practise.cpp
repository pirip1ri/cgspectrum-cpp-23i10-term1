#include <iostream>

using namespace std;

int main()
{
    cout << "Enter a number: ";    
    int number;
    cin >> number;


    for (int i = 0; i <= number; i++)
    {
        cout << i << ' ';
    }

    cout << endl;

    for (int i = number; i >= 0; i--)
    {
        cout << i << ' ';
    }
}
