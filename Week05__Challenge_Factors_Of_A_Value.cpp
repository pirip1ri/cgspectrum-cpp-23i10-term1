#include <iostream>

using namespace std;

int retrieveNumber();
void factorCalc(int number);

int main()
{
    int number = retrieveNumber();
    factorCalc(number);
}


//A function to retrieve a valid (positive whole) number. Includes what to do when a negative value has been used and when a non-integer value has been used.
int retrieveNumber()
{
    int number;
    do
    {
        cout << "Enter a positive number: ";
        cin >> number;

        if (number <= 0)
        {
            cin.clear();
            cin.ignore(100, '\n');
            system("cls");
            cout << "Invalid input, that is not a positive number. Please try again." << endl;
        }
        else if (cin.fail())
        {
            cin.clear();
            cin.ignore(100, '\n');
            system("cls");
            cout << "Invalid input, that is not a positive number. Please try again." << endl;
        }
        else
        {
            break;
        }
    } while (true);

    return number;
}

//A function to calculate the number % i and spits out all the numbers where it equals zero, and stops at i = number.
void factorCalc(int number)
{
    cout << "Factors of " << number << " are: ";
    for (int i = 1; i < number; i++)
    {
        if (number % i == 0)
        {
            cout << i << " ";
        }
    }

    cout << "and " << number << endl;
}
