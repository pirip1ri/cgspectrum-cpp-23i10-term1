#include <iostream>

using namespace std;

void inputArray(int arr[], int index = 0);
void bubbleSort(int arr[], int n);
void swap(int& a, int& b);
void printArray(int arr[], int index = 0);

int main()
{
    int arr[5];

    cout << "Enter 5 numbers to be sorted: ";
    inputArray(arr);

    bubbleSort(arr, 5);

    cout << "Using bubblesort, the sorted numbers (from lowest to highest) are: ";
    printArray(arr);
    cout << "." << endl;
}

// Input the 5 numbers you want to sort from low to high in any order. Generate the array.
void inputArray(int arr[], int index)
{
    if (index < 5)
    {
        cin >> arr[index];
        inputArray(arr, index + 1);
    }
}

// Simple swap function
void swap(int& a, int& b)
{
    int temp = a;
    a = b;
    b = temp;
}

// Bubblesort implementation
//For an array arr[] with n elements, the code will loop round between i = 0 and i = n -2 (aka loops up until the penultimate position in the array)
//In this loop is a nested loop for the jth position in the array. It will increment the jth position by 1 up until, again, the penultimate array position.
//With every increment, it checks if the value above it is smaller or not. If the value above is smaller, it swaps places.
//This allows the largest value in the array to 'bubble up' to the top
//This continues until all the values are sorted from lowest to highest.
void bubbleSort(int arr[], int n)
{
    for (int i = 0; i < n - 1; i+=1)
    {
        for (int j = 0; j < n - i - 1; j+=1)
        {
            if (arr[j] > arr[j + 1])
            {
                swap(arr[j], arr[j + 1]);
            }
        }
    }
}

// Prints the values of the array in numerical order.
void printArray(int arr[], int index)
{
    if (index < 5)
    {
        cout << arr[index];
        if (index < 4)
        {
            cout << ", ";
        }
        printArray(arr, index + 1);
    }
}