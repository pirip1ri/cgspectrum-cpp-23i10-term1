#include <iostream>

using namespace std;

int retrieveA();
int retrieveB();

int main()
{
    int a = retrieveA();
    int b = retrieveB();

    int* ptrA = &a;
    int* ptrB = &b;

    cout << "Value a = " << *ptrA << endl;
    cout << "Value b = " << *ptrB << endl;
}

int retrieveA()
{
    cout << "Please enter your first variable, a: ";
    float a;
    cin >> a;
    return a;
}

int retrieveB()
{
    cout << "Please enter your second variable, b: ";
    float b;
    cin >> b;
    return b;
}