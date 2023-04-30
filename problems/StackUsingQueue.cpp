#include <iostream>
#include <queue.hpp>

template <typename T>
class StackQ{
private:
    Queue<T> q;
public:
    void push(T elem);
    T pop();
    T top();
    bool isEmpty() const;
    int stackSize() const;
    void clear();
    void print() const;
};

template<typename T>
void StackQ<T>::push(T elem) {
    q.enqueue(elem);
}

template<typename T>
T StackQ<T>::pop() {
    int size = q.queueSize();
    for (int i = 0; i < size - 1; ++i) {
        q.enqueue(q.dequeue());
    }
    return q.dequeue();
}

template<typename T>
T StackQ<T>::top() {
    int size = q.queueSize();
    for (int i = 0; i < size - 1; ++i) {
        q.enqueue(q.dequeue());
    }
    T topElem = q.dequeue();
    q.enqueue(topElem);
    return topElem;
}

template<typename T>
bool StackQ<T>::isEmpty() const {
    return q.isEmpty();
}

template<typename T>
int StackQ<T>::stackSize() const {
    return q.queueSize();
}

template<typename T>
void StackQ<T>::clear() {
    q.clear();
}

template<typename T>
void StackQ<T>::print() const {
    if (q.queueSize()!=0)
        q.print();
    else
        cerr << "Stack is Empty!\n";
}

int main(){
    StackQ<int> stkQ;
    cout << "\nIs stack empty?\n";
    cout << (stkQ.isEmpty()?"YES":"NO") << '\n';

    cout << "\nPushing 5 8 2 0 1 -20\n";
    stkQ.push(5);
    stkQ.push(8);
    stkQ.push(2);
    stkQ.push(0);
    stkQ.push(1);
    stkQ.push(-20);

    cout << "\nCurrent stack contents\n";
    stkQ.print();

    cout << "\nCurrent stack size is:\n";
    cout << stkQ.stackSize() << '\n';

    cout << "\nPopping 2 elements from the stack\n";
    cout << "popped " << stkQ.pop() << " and popped " << stkQ.pop() << "\n";

    cout << "\nCurrent stack contents\n";
    stkQ.print();

    cout << "\nTop element in the stack is:\n";
    cout << stkQ.top() << '\n';


    cout << "\nIs stack empty?\n";
    cout << (stkQ.isEmpty()?"YES":"NO") << '\n';

    cout << "\nCurrent stack contents\n";
    stkQ.print();
}

