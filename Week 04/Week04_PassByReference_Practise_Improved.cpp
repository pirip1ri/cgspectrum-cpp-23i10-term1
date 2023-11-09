#include <iostream>

using namespace std;

bool g_isEven = false;
bool g_isOdd = false;
bool g_isZero = false;
bool g_isPositive = false;
bool g_isNegative = false;

//Declare function
void analyseNumber(int number);

int main()
{
    // function calls
    cout << "Please enter a number: ";
    int number;
    cin >> number;

 

    analyseNumber(number);


    if (g_isEven)
    {
        cout << number << " is even!" << endl;
    }
    if (g_isOdd)
    {
        cout << number << " is odd!" << endl;
    }
    if (g_isZero)
    {
        cout << number << " is zero!" << endl;
    }
    if (g_isPositive)
    {
        cout << number << " is positive!" << endl;
    }
    if (g_isNegative)
    {
        cout << number << " is negative!" << endl;
    }
}

//Define function
void analyseNumber(int number)
{
    if (number % 2 == 0)
    {
        g_isEven = true;
        g_isOdd = false;
    }
    else
    {
        g_isEven = false;
        g_isOdd = true;
    }
    if (number == 0)
    {
        g_isZero = true;
        g_isPositive = false;
        g_isNegative = false;
    }
    else if (number > 0)
    {
        g_isZero = false;
        g_isPositive = true;
        g_isNegative = false;
    }
    else
    {
        g_isZero = false;
        g_isPositive = false;
        g_isNegative = true;
    }
}