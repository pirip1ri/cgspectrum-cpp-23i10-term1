#include <iostream>

using namespace std;

int findLargestNumber(const int arr[], int size);

int main() 
{
    constexpr int size = 7; // Set the array size to a constant value

    int arr[size];

    cout << "Enter " << size << " integers: ";
    for (int i = 0; i < size; ++i) 
    {
        cin >> arr[i];
    }

    int largest = findLargestNumber(arr, size);

    cout << "The largest number in the array is: " << largest << endl;
}

int findLargestNumber(const int arr[], int size)
{
    int largest = arr[0]; // Assume the first element is the largest

    for (int i = 1; i < size; ++i)
    {
        if (arr[i] > largest)
        {
            largest = arr[i]; // Update 'largest' if a larger number is found
        }
    }

    return largest;
}