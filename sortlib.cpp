/* Assignment #1 - Data Structures - Spring 2023 - FCAI-CU
Author(s): Seif Yahia -- 20210172
Description: Implementation of some sorting algorithms
Last Modified Date: 12 March 2023
*/

#include <iostream>
using namespace std;

// Main package that contains all required sorting algorithms
namespace sortlib
{
    // Output the elements of the array
    template <typename T>
    void printArr(T data[], int arrSize)
    {
        for (int i = 0; i < arrSize; ++i)
            cout << data[i] << " ";
        cout << endl;
    }

    // Insertion sort algorithm
    template <typename T>
    void insertionSort(T data[], int arrSize)
    {
        // Traverse the whole array
        for (int i = 1, j; i < arrSize; ++i)
        {
            // Store the value of the current element
            T temp = data[i];
            // Compare the value of current element with the previous elements
            for (j = i; j > 0 and temp < data[j - 1]; --j)
                // If the current element is smaller swap the two values
                data[j] = data[j - 1];
            // After reaching the correct location of the current element
            // Override the value of that index to be the current element
            data[j] = temp;
        }
    }

    // Selection sort algorithm
    template <typename T>
    void selectionSort(T data[], int arrSize)
    {
        // Traverse the whole array
        int i, j, min;
        for (i = 0; i < arrSize; ++i)
        {
            // Traverse the array but with one step ahead of the outer loop
            for (j = i + 1, min = i; j < arrSize; ++j)
                // Check for the smallest element
                if (data[j] < data[min])
                    min = j;
            // Swap the smallest element with the current element
            swap(data[min], data[i]);
        }
    }

    // Bubble sort algorithm
    template <typename T>
    void bubbleSort(T data[], int arrSize)
    {
        // Traverse the whole array
        for (int i = 0; i < arrSize; ++i)
            for (int j = i + 1; j < arrSize; ++j)
                // Check if the first one is greater than the second one
                if (data[i] > data[j])
                    // Swap the two elements
                    swap(data[i], data[j]);
    }

}

using namespace sortlib;

// Driver program to test sorting algorithms
int main()
{
    short choice;
    int arr[] = {2023, -1, 122, 8, 12};
    int arraySize = sizeof(arr) / sizeof(arr[0]);
    cout << "Welcome to the Sorting Algorithms Library!\n";
    cout << "The library contains the following sorting algorithms:\n";
    cout << "1. Insertion Sort\n"
            "2. Selection Sort\n"
            "3. Bubble Sort\n"
            "4. Shell Sort\n"
            "5. Counting Sort\n"
            "6. Merge Sort\n"
            "7. Quick Sort\n";
    cout << "Choose one of the above algorithms to test (1-7): ";
    cin >> choice;
    switch (choice)
    {
    case 1:
        cout << "\t--- Insertion Sort ---\n";
        cout << ">> Original Array <<\n"; printArr(arr, arraySize);
        insertionSort(arr, arraySize);
        cout << ">> Sorted Array <<\n"; printArr(arr, arraySize);
        break;
    case 2:
        cout << "\t--- Selection Sort ---\n";
        cout << ">> Original Array <<\n"; printArr(arr, arraySize);
        selectionSort(arr, arraySize);
        cout << ">> Sorted Array <<\n"; printArr(arr, arraySize);
        break;
    case 3:
        cout << "\t--- Bubble Sort ---\n";
        cout << ">> Original Array <<\n"; printArr(arr, arraySize);
        bubbleSort(arr, arraySize);
        cout << ">> Sorted Array <<\n"; printArr(arr, arraySize);
        break;
    case 4:
        cout << "Shell Sort! Coming Soon...\n";
        break;
    case 5:
        cout << "Counting Sort! Coming Soon...\n";
        break;
    case 6:
        cout << "Merge Sort! Coming Soon...\n";
        break;
    case 7:
        cout << "Quick Sort! Coming Soon...\n";
        break;
    default:
        cout << "Invalid choice!\n";
    }
    cout << "\n\tThank you for using the Sorting Algorithms Library!\n";
    return 0;
}
