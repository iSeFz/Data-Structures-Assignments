#include <iostream>
using namespace std;

// Queue implementation using Linked List
template <class elementType>
class Queue{
private:
    // Node structure
    template <typename T = elementType>
    struct Node{
        T data;
        Node *next;
    };
    // Track the number of elements in the queue
    int length;
    // Front and back pointers
    Node<elementType> *front;
    Node<elementType> *back;
public:
    // Constructor
    Queue(){
        front = back = nullptr;
        length = 0;
    }
    // Destructor
    ~Queue(){ this->clear(); }
    // Add an item to the queue
    void enqueue(elementType element){
        Node<elementType>* newNode = new Node<elementType>();
        newNode->data = element;
        newNode->next = nullptr;
        if(isEmpty())
            front = newNode;
        else
            back->next = newNode;
        back = newNode;
        length++;
    }
    // Remove an item from the queue
    elementType dequeue(){
        elementType temp = front->data;
        if(isEmpty()){
            cerr << "Queue is already EMPTY!!\n";
            exit(0);
        }
        // If there is only one item in the queue
        else if(front == back){
            delete front;
            front = back = nullptr;
        }
        // If there are more than one item in the queue
        else {
            Node<elementType>* delPtr = front;
            front = front->next;
            delete delPtr;
        }
        length--;
        return temp;
    }
    // Peek the first element of the queue
    elementType first() const {
        if(isEmpty()){
            cerr << "Queue is EMPTY!! No elements to show!\n";
            exit(0);
        }
        return front->data;
    }
    // Check if the queue is empty
    bool isEmpty() const { return length == 0; }
    // Get the size of the queue
    int queueSize() const { return length; }
    // Clear all items in the queue
    void clear(){
        while(!isEmpty())
            this->dequeue();
        length = 0;
    }
    // Display items in the queue
    void print() const {
        if(isEmpty()){
            cerr << "Queue is EMPTY!! No elements to show!\n";
            return;
        }
        // Traverse the queue and print the items
        Node<elementType>* temp = front;
        while(temp != nullptr){
            cout << temp->data << " ";
            temp = temp->next;
        }
        cout << "\n";
    }
};