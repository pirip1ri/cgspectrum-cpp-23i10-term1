#include <iostream>
#include <string> 

using namespace std;

void displayWelcomeMessage();
double retrieveValue();
double calculation(double base);
void displayAnswer(double base, double answer); 

int main()
{
    displayWelcomeMessage();
    double base = retrieveValue();
    double answer = calculation(base);
    displayAnswer(base, answer);
}

void displayWelcomeMessage()
{
    cout << "Cube Calculator" << endl;
    cout << "This program will calculate the cube of a value that you enter." << endl;
    cout << "Please enter any value: ";
}

double retrieveValue()
{
    double base;
    cin >> base;
    return base;
}

double calculation(double base)
{
    double answer = base * base * base;
    return answer;
}

void displayAnswer(double base, double answer)
{
    cout << "The cube of " << base << " is " << answer << endl;
}