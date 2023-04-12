#include <iostream>
using namespace std;

// Stack implementation using Linked List
template <class elementType>
class Stack{
private:
    // Node structure
    template <typename T = elementType>
    struct Node{
        T data;
        Node *next;
    };
    // Track the number of elements in the stack
    int length;
    // Head pointer
    Node<elementType> *head;
public:
    // Constructor
    Stack() : head(nullptr), length(0) {}
    // Destructor
    ~Stack(){ this->clear(); }
    // Add item to the stack
    void push(elementType element){
        Node<elementType>* newNode = new Node<elementType>();
        newNode->data = element;
        newNode->next = head;
        head = newNode;
        length++;
    }
    // Remove the first element from the stack
    elementType pop(){
        if(isEmpty()) exit(0);
        Node<elementType>* delPtr = head;
        elementType temp = head->data;
        head = head->next;
        delete delPtr;
        length--;
        return temp;
    }
    // Return the first element of the stack
    elementType top() const { return head->data; }
    // Check if the stack is empty
    bool isEmpty() const { return length == 0; }
    // Get the size of the stack
    int stackSize() const { return length; }
    // Delete all elements of the stack
    void clear(){
        while(!isEmpty())
            this->pop();
        length = 0;
    }
    // Display elements in the stack
    void print() const {
        if(isEmpty()){
            cerr << "Stack is EMPTY!! No elements to show!\n";
            return;
        }
        // Traverse the stack and print the items
        Node<elementType>* temp = head;
        while(temp != nullptr){
            cout << temp->data << " ";
            temp = temp->next;
        }
        cout << "\n";
    }
};