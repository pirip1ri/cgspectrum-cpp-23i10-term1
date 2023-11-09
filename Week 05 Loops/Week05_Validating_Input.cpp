#include <iostream>

using namespace std; 

int main()
{
    int number;

    do
    {
        cout << "Please enter a number: ";
        cin >> number;

        if (cin.fail())
        {
            cin.clear();
            cin.ignore(99, '\n');
            cout << "That is not a number! Try again." << endl;
        }
        else
        {
            cout << "Thanks so much! That is a number! That's a great number.";
            break;
        }
    } while (true);
}