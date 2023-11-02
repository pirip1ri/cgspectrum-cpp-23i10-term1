#include <iostream>

using namespace std;

int main()
{
    float myGrades[5] = { 45.5, 81.0, 69.0, 61.5, 60.0 };

    float sum = 0;

    for (int i = 0; i < 5; i++)
    {
        sum = sum + myGrades[i];
    }

    float average = sum / 5;

    cout << "My grades for each module are: ";

    for (int i = 0; i < 5; i++)
    {
        cout << myGrades[i] << " ";
    }
    cout << endl;

    cout << "My average grade is " << average << endl;
}
