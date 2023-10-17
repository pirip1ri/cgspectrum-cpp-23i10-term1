#include <iostream>

using namespace std;

int main()
{
    int number;
    cout << "Please enter a value: " << endl;
    cin >> number;

    if (number == 0)
    {
        cout << "The number is zero." << endl;
    }
    else
    {
        cout << "The number is non-zero." << endl;
    }

    bool isEven = (number % 2) == 0;
    if (isEven == true)
    {
        cout << "The number is even." << endl;
    }
    else
    {
        cout << "The number is odd." << endl;
    }
}

