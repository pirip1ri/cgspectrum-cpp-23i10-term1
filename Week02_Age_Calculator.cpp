#include <iostream>

using namespace std;

int main()
{
    // Prompt user for the name
    cout << "Please enter your name: ";
    //Retrieve name
    string name;
    cin >> name;
    //Prompt user for year or birth
    cout << "Please enter the year of your birth: ";
    //Retrieve year of birth
    int yearOfBirth;
    cin >> yearOfBirth;
    //Prompt user for the current year
    cout << "Please enter the year we arew currently in: ";
    //Retrieve current year
    int currentYear;
    cin >> currentYear;
    //Display results
    int age = currentYear - yearOfBirth;

    cout << "Hi " << name << "! You are (or will be) " << age << " years old this year!";
}

