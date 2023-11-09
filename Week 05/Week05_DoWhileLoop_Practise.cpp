
#include <iostream>

using namespace std;

int main()
{
    int number;
    bool isValid = false;
    do
    {
        cout << "Select a number between 10 and 20: ";

        cin >> number;

        isValid = ((number >= 10) && (number <= 20));

        if (!isValid)
        {
            cout << "That is not a number, please try again." << endl;
        }
    }while (!isValid);
    cout << "Cheers!" << endl;
}
