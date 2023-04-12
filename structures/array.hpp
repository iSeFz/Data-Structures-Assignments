#include <iostream>
using namespace std;

template<class T>
class Array{
private:
    T* data;
    int size;
    int length;
public:
    // Constructor for the Array class that takes an integer parameter called size
    Array(int size){
        // Check if the size is greater than 0
        if(size > 0){
            // If it is, set the size of the array to the value of the size parameter
            this->size = size;
        }else{
            // If it is not, print an error message and set the size of the array to 100
            cout << "Invalid size The array initialized with size 100\n";
            this->size = 100;
        }
        // Initialize the length of the array to 0
        length = 0;
        // Create a new array of type T with the specified size using the new operator
        data = new T[size];
    }


    // This function inserts an element of type T into the array
    void insert(T element){
        // Check if the array is not full
        if(!isFull())
            // If the array is not full, insert the element at the end of the array
            // and increment the length variable
            data[length++] = element;
        else{
            // If the array is full, print an error message using cerr
            cerr << "Array is Full\n";
        }
    }

    // This function inserts an element at a given index in the array
    void insertAt(T element, int index){

        // Check if the array is not full
        if(!isFull()) {

            // Shift all the elements from the given index to the end of the array one position to the right
            for (int i = length - 1; i >= index; --i) {
                data[i] = data[i - 1];
            }

            // Insert the given element at the given index
            data[index] = element;

            // Increment the length of the array
            length++;
        }
        else{
            // Print an error message to the console if the array is full
            cerr << "Array is Full\n";
        }
    }

    // This function retrieve an element at a given index in the array
    T retrieveAt(int index){ return data[index]; }

    // This function removes an element from the array at the specified index
    void removeAt (int index){

        // Check if the array is not empty
        if(!isEmpty()){

            // Shift all the elements to the left starting from the index to be removed
            for (int i = index + 1; i < length; ++i) {
                data[i - 1] = data[i];
            }

            // Decrease the length of the array by 1
            length--;
        }

        // If the array is empty, print an error message to the console
        else{
            cerr << "Array is Empty\n";
        }
    }

    // This function replaces an element in the array at the specified index with a new element
    void replaceAt (T newElement, int index){

        // Check if the index is valid (within the bounds of the array)
        if(index >= 0 || index < length){

            // Replace the element at the specified index with the new element
            data[index] = newElement;
        }

        // If the index is invalid, print an error message to the console
        else{
            cerr << "Index is invalid";
        }
    }

    // This function checks if the element at the specified index is equal to the given element
    bool isItemAtEqual (T element, int index){

        // Check if the index is valid (within the bounds of the array)
        if(index >= 0 || index < length){

            // Compare the element at the specified index with the given element
            return (data[index] == element);
        }

        // If the index is invalid, print an error message to the console and return false
        else{
            cerr << "Index is invalid";
            return false;
        }
    }

    // This function checks if array empty or not
    bool isEmpty(){ return (listSize() == 0); }

    // This function checks if array full or not
    bool isFull(){ return (listSize() == maxListSize()); }

    // This function returns number of elements in array
    int listSize(){ return length; }

    // This function returns max capacity of array
    int maxListSize(){ return size; }

    // This function clear array
    void clear(){ length = 0; }

    // This function prints array
    void print(){
        if(isEmpty()){
            cout << "[]";
            return;
        }
        cout << "[";
        for (int i = 0; i < length - 1; ++i) {
            cout << data[i] << ",";
        }
        cout << data[length - 1] << "]";
    }
};