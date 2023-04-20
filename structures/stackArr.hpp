#include <iostream>

// Implementing a stack using an array
template <typename T>
class StackArr{
private:
    T *data;
    int size; // number of elements in the stack
    int arrSize; // the size of the allocated array
public:
    StackArr();
    ~StackArr();
    void push(T elem);
    T pop();
    T top() const;


    bool isEmpty() const;
    int stackSize() const;
    void clear();
    void print() const;
};

template<typename T>
StackArr<T>::StackArr() {
    arrSize = 10;
    size = 0;
    data = new T[arrSize];
}

template<typename T>
StackArr<T>::~StackArr() {
    delete[] data;
}

template<typename T>
void StackArr<T>::push(T elem) {
    // increase arrSize by 1.5x when only one space is remaining in the existing array
    if (size+1>=arrSize){
        arrSize = 1.5*arrSize;

        T *newData = new T[arrSize];
        for (int i = 0; i < size; ++i) {
            newData = data[i];
        }

        T *tmp = data;
        delete tmp;
        data = newData;
    }
    data[size++] = elem;
}

template<typename T>
T StackArr<T>::pop() {
    return data[--size];
}

template<typename T>
T StackArr<T>::top() const {
    return data[size-1];
}

template<typename T>
bool StackArr<T>::isEmpty() const {
    return size == 0;
}

template<typename T>
int StackArr<T>::stackSize() const {
    return size;
}

template<typename T>
void StackArr<T>::clear() {
    size = 0;
}

template<typename T>
void StackArr<T>::print() const {
    for (int i = 0; i < size; ++i) {
        std::cout << data[i] << " ";
    }
}
