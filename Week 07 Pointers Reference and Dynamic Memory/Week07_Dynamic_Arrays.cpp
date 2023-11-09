#include <iostream>

using namespace std;

int* CreateGrades(int size);
void Populate(int* pMyGrades, int size);
void DisplayGrades(int* pMyGrades, int size);

int main()
{
    int size;
    cout << "How many classes do you have: " << endl;
    cin >> size;

    cout << "Please enter your grades :";

    int* pMyGrades = CreateGrades(size);

    Populate(pMyGrades, size);
    DisplayGrades(pMyGrades, size);

    delete[] pMyGrades;
    pMyGrades = nullptr;
}

int* CreateGrades(int size)
{
    int* pointer = new int[size];
    return pointer;
}
void Populate(int* pMyGrades, int size)
{
    for (int i = 0; i < size; i++)
    {
        cin >> pMyGrades[i];
    }
}
void DisplayGrades(int* pMyGrades, int size)
{
    for (int i = 0; i < size; i++)
    {
        cout << pMyGrades[i] << " ";
    }
    cout << endl;
}