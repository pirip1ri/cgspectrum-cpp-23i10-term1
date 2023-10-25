#include <iostream>

using namespace std;

template <typename T>
T Add(T v);
template <typename T, typename... Args>
T Add(T first, Args...rest);

void displayMessage(string message);

template <typename T>
void displayMessage(string message, T number);

int main()
{
    int i = Add(2, 3, 4);
    float f = Add(9.9f, -2.4f);
    double d = Add(4.4, 2.4);

    displayMessage("Testing Overloaded functions");
    displayMessage("Integer Addition: ", i);
    displayMessage("Float Addition: ", f);
    displayMessage("Double Addition: ", d);
}

template <typename T>
T Add(T v)
{
    return v;
}
template <typename T, typename... Args>
T Add(T first, Args...rest)
{
    return first + Add(rest...);
}

void displayMessage(string message)
{
    cout << message << endl;
}

template <typename T>
void displayMessage(string message, T number)
{
    cout << message << number << endl;
}