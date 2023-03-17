/* Assignment #1 - Data Structures - Spring 2023 - FCAI-CU
Author(s): Seif Yahia -- 20210172, Mohamed Amgad -- 20210330
Description: Implementation of some sorting algorithms
Last Modified Date: 17 March 2023
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

    // Shell sort function
    template <typename T>
    void shellSort(T data[], int arrSize){
        // Divide the array in half
        for (int gap = arrSize / 2; gap > 0; gap /= 2){
            // Iterate through the array
            for (int i = gap, j; i < arrSize; i += gap){
                // Store the current element
                T temp = data[i];
                // Iterate through the sorted subarray
                for (j = i - gap; j >= 0 && temp < data[j]; j -= gap){
                    // Shift the element to the right if it is larger than the current element
                    data[j + gap] = data[j];
                }
                // Place the current element in its proper location
                data[j + gap] = temp;
            }
        }
    }

    // function that merge two arrays to one array
    template <typename T>
    void merge (T data[], int start, int mid, int end){
        // find the size of the left and right arrays
        const int n1 = mid - start + 1;
        const int n2 = end - mid;
        T lArr[n1] , rArr[n2];
        // copy the data to the left and right arrays
        for (int i = 0; i < n1; i++)
        {
            lArr[i] = data[start + i];
        }
        for (int j = 0; j < n2; j++)
        {
            rArr[j] = data[mid + j + 1];
        }
        // initialize the left and right arrays index
        int i = 0, j = 0, k = start;
        // merge the left and right arrays to the data array
        while (i < n1 && j < n2)
        {
            if(lArr[i] < rArr[j])
                data[k++] = lArr[i++];
            else
                data[k++] = rArr[j++];

        }
        // copy the remaining elements in the left array to the data array
        while(i < n1){
            data[k++] = lArr[i++];
        }
        // copy the remaining elements in the right array to the data array
        while(j < n2){
            data[k++] = rArr[j++];
        }
    }
    template <typename T>
    void mergeSort(T data[], int start, int end){
        if(start >= end)
            return;
        int mid = (start + end)/2;
        // Sort the left side of the array
        mergeSort(data,start,mid);
        // Sort the right side of the array
        mergeSort(data,mid + 1,end);
        // Merge the two sorted arrays
        merge(data,start,mid,end);
    }

    template <typename T>
    int Partitioning(T data[], int start, int end){
        int i = start; //i is the index of the leftmost element
        int j = end; //j is the index of the rightmost element
        int pivot = start; //pivot is the index of the first element
        while(true){
            while(data[i] < data[j] && i != j){
                if(pivot == i)
                    j--; //move j to the left one element
                else
                    i++; //move i to the right one element
            }
            if(i == j) //if i and j are the same, then the pivot element is at its final position
                return pivot;
            if(pivot == i){ //if the pivot element is at the left, then swap it with the element at the index j
                swap(data[i],data[j]);
                pivot = j; //then update the pivot to the new position
                i++; //move i to the right one element
            }
            else{ //if the pivot element is at the right, then swap it with the element at the index i
                swap(data[i],data[j]);
                pivot = i; //then update the pivot to the new position
                j--; //move j to the left one element
            }
        }
    }
    template <typename T>
    void quickSort(T data[], int start, int end){
        if(start < end){
            // Divide and conquer
            int pivot = Partitioning(data,start,end);
            quickSort(data,start,pivot - 1); //recursively sort the left
            quickSort(data,pivot + 1,end); //recursively sort the right
        }
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
        cout << "Shell Sort! Coming Soon ---\n";
        cout << ">> Original Array <<\n"; printArr(arr, arraySize);
        shellSort(arr, arraySize);
        cout << ">> Sorted Array <<\n"; printArr(arr, arraySize);
        break;
    case 5:
        cout << "\t--- Counting Sort! Coming Soon ---\n";
        break;
    case 6:
        cout << "\t--- Merge Sort! Coming Soon ---\n";
        cout << ">> Original Array <<\n"; printArr(arr, arraySize);
        mergeSort(arr, 0, arraySize - 1);
        cout << ">> Sorted Array <<\n"; printArr(arr, arraySize);
        break;
    case 7:
        cout << "\t--- Quick Sort! Coming Soon ---\n";
        cout << ">> Original Array <<\n"; printArr(arr, arraySize);
        quickSort(arr, 0, arraySize - 1);
        cout << ">> Sorted Array <<\n"; printArr(arr, arraySize);
        break;
    default:
        cout << "Invalid choice!\n";
    }
    cout << "\n\tThank you for using the Sorting Algorithms Library!\n";
    return 0;
}
