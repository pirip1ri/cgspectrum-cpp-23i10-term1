#include <iostream>

using namespace std;

int main()
{
    cout << "------------ Welcome to my program! ------------" << endl;
    cout << "Which of the three options would you like to do:" << endl;
    cout << "1) Check if a value is even." << endl;
    cout << "2) Check if a value is positive." << endl;
    cout << "3) Check if a value is a multiple of 7." << endl;
    cout << "Please enter 1, 2 or 3 to select the option you want: " << endl;
    int option;
    cin >> option;

    int value;
    switch (option)
    {
    case 1:
    {
        cout << "Please enter a value: " << endl;
        cin >> value;

        if (value % 2 == 0)
        {
            cout << "The value you have entered is even." << endl;
        }
        else if (value % 2 == 1)
        {
            cout << "The value you entered is odd." << endl;
        }
        else
        {
            cout << "Invalid input. Goodbye." << endl;
        }
        break;
    }

    case 2:
    {
        cout << "Please enter a value: " << endl;
        cin >> value;

        if (value > 0)
        {
            cout << "The value you have entered is positive." << endl;
        }
        else if (value < 0)
        {
            cout << "The value you have entered is negative." << endl;
        }
        else
        {
            cout << "Invalid input. Goodbye." << endl;
        }
        break;
    }
    
    case 3:
    {
        cout << "Please enter a value: " << endl;
        cin >> value;

        if (value % 7 == 0)
        {
            cout << "The value you have entered is a multiple of 7." << endl;
        }
        else if (value % 7 != 0)
        {
            cout << "The value you have entered is not a multiple of 7." << endl;
        }
        else
        {
            cout << "Invalid input. Goodbye." << endl;
        }
        break;
    }
    default:
    {
        cout << "Invalid input. Goodbye." << endl;
        break;
    }
    }
}
