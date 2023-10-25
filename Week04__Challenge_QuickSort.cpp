#include <iostream>

using namespace std;

void inputArray(int arr[], int index = 0);

void quicksort(int arr[], int low, int high);

void swap(int& a, int& b);

int partition(int arr[], int low, int high, int i);

void printArray(int arr[], int index = 0);

int main()
{
    int arr[5];

    cout << "Enter 5 numbers to be sorted: ";
    inputArray(arr);

    quicksort(arr, 0, 4);

    cout << "Using quicksort, the sorted numbers (from lowest to highest) are: ";
    printArray(arr);
    cout << "." << endl;

}

//Input the 5 numbers you want to sort from low to high in any order. Generate the array.
void inputArray(int arr[], int index)
{
    if (index < 5)
    {
        cin >> arr[index];
        inputArray(arr, index + 1);
    }
}

//The quicksort function: allows us to define the pivot, as well as select the range of the partition. Recursion will occur. This means that this function will call for new partitions after the pivot has been sorted to...
//...its correct index position. These new partitions will be both above and below the previous pivot's new index number.
void quicksort(int arr[], int low, int high)
{
    if (low < high)
    {
        int pi = partition(arr, low, high, low);
        quicksort(arr, low, pi - 1);
        quicksort(arr, pi + 1, high);
    }
}

//Simple swap function
void swap(int& a, int& b)
{
    int temp = a;
    a = b;
    b = temp;
}

//In this partition, the pivot is [high]. The function then goes through the list from the low index to the high index and compares each element to the pivot.
//If an element is smaller than the pivot, it's swapped with the element at the low index, which is initially set to the low value. This places the smaller element on the left side of the low index.
//If an element is not smaller than the pivot, we move on to the next element.
//Once we've gone through all elements, the pivot is swapped with the element at the low index. This means all elements less than the pivot are on its left, and all elements greater than the pivot are on its right.
int partition(int arr[], int low, int high, int i)
{
    if (i < high)
    {
        if (arr[i] < arr[high])
        {
            swap(arr[low], arr[i]);
            return partition(arr, low + 1, high, i + 1);
        }
        else
        {
            return partition(arr, low, high, i + 1);
        }
    }
    else
    {
        swap(arr[low], arr[high]);
        return low;
    }
}

//Prints the values of the array in numerical order.
void printArray(int arr[], int index)
{
    if (index < 5)
    {
        cout << arr[index] << ", ";
        printArray(arr, index + 1);
    }
}