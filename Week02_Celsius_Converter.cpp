#include <iostream>

using namespace std;

int main()
{
    //Prompt user to enter temperature in celsius
    cout << "Enter the temperature in celsius: ";
    //Retrieve temperature
    float celsius;
    cin >> celsius;
    //convert to fahrenheit
    float fahrenheit = (celsius * 1.8f) + 32;
    //Display temps
    cout << celsius << "oC is equivalent to " << fahrenheit << "oF." << endl;
}
