#include <iostream>

using namespace std;

int main()
{
    int variable = 10;
    int* pointer = &variable;

    int newVariable = *pointer; // 10
    *pointer = 20; // variable = 20

    cout << "The variable is " << variable << endl;
    cout << "&Variable: " << &variable << endl;
    cout << "Pointer: " << pointer << endl;
    cout << "*pointer: " << *pointer << endl;
    cout << "&pointer: " << &pointer << endl;
    cout << "New Variable: " << newVariable << endl;
}
