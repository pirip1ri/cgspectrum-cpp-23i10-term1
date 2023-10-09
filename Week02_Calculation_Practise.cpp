#include <iostream>

using namespace std;

int main()
{
    int a = 10;
    int b = 3;

    int add = a + b;
    int subtract = a - b;
    int multiply = a * b;
    int division = a / b;
    float division2 = a / 3.0f;
    int mod = a % b;

    cout << division2 << endl;

    int result = a + (b * 2) - 4;
    cout << result << endl;


    int x = 10;
    x += 20;
    x -= 10;
    x *= 10;
    x /= 10;
    x %= 10;

    cout << x << endl;

    float myFloat = 30.5f;
    int myInt = (int)myFloat;

    int a = 20;
    float b = (float)a;

    int result = (int)(2.4 + 1.6);

    cout << result << endl;

}