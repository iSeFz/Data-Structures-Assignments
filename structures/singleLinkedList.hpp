#include <iostream>
using namespace std;

// Single Linked List Implementation
template <class elementType>
class SingleLinkedList{
private:
    // Node structure
    template <typename T = elementType>
    struct Node{
        T data;
        Node *next;
    };
    // Track the number of elements in the list
    int length;
    // Head and tail pointers
    Node<elementType> *head;
    Node<elementType> *tail;
public:
    // Constructor
    SingleLinkedList() : head(nullptr), tail(nullptr), length(0) {}
    // Destructor
    ~SingleLinkedList(){ this->clear(); }
    // Insert node at the beginning of the list
    void insertAtHead(elementType element){
        Node<elementType>* newNode = new Node<elementType>();
        newNode->data = element;
        if(isEmpty())
            tail = newNode;
        else
            newNode->next = head;
        head = newNode;
        length++;
    }
    // Insert node at the end of the list
    void insertAtTail(elementType element){
        Node<elementType>* newNode = new Node<elementType>();
        newNode->data = element;
        newNode->next = nullptr;
        if(isEmpty())
            head = newNode;
        else
            tail->next = newNode;
        tail = newNode;
        length++;
    }
    // Insert node at certain position
    void insertAt(elementType element, int index){
        if(index <= 0 or index > length) return;
        Node<elementType>* newNode = new Node<elementType>();
        newNode->data = element;
        if(isEmpty())
            head = tail = newNode;
        else if(index == 1){
            this->insertAtHead(element);
            return;
        }
        else{
            Node<elementType>* current = head;
            Node<elementType>* previous = nullptr;
            for(int i = 1; i < index; ++i){
                previous = current;
                current = current->next;
            }
            previous->next = newNode;
            newNode->next = current;
        }
        length++;
    }
    // Remove node from the beginning of the list
    void removeAtHead(){
        if(isEmpty()) return;
        // If there is only one item in the list
        else if(head == tail){
            delete head;
            head = tail = nullptr;
        }
        // If there are more than one item in the list
        else{
            Node<elementType>* delPtr = head;
            head = head->next;
            delete delPtr;
        }
        length--;
    }
    // Remove node from the end of the list
    void removeAtTail(){
        if(isEmpty()) return;
        // If there is only one node in the list
        else if(head == tail){
            delete tail;
            head = tail = nullptr;
        }
        // If there are more than one node in the list
        else{
            Node<elementType>* temp = head;
            // Loop to reach the element before the tail
            while(temp->next != tail)
                temp = temp->next;
            delete tail;
            tail = temp;
            tail->next = nullptr;
        }
        length--;
    }
    // Remove node at certain position
    void removeAt(int index){
        if(index <= 0 or index > length) return;
        // If the index is at the first node
        else if(index == 1){
            this->removeAtHead();
            return;
        }
        // If the index is at the last node
        else if(index == length){
            this->removeAtTail();
            return;
        }
        else{
            Node<elementType>* current = head;
            Node<elementType>* previous = nullptr;
            // Loop until reaching the desired position
            for(int i = 1; i < index; ++i){
                previous = current;
                current = current->next;
            }
            previous->next = current->next;
            delete current;
        }
        length--;
    }
    // Retrieve certain element by position
    elementType retrieveAt(int index){
        if(index <= 0 or index > length) exit(0);
        // If the index is at the first node
        else if(index == 1)
            return head->data;
        // If the index is at the last node
        else if(index == length)
            return tail->data;
        else{
            Node<elementType>* temp = head;
            // Loop until reaching the desired position
            for(int i = 1; i < index; ++i)
                temp = temp->next;
            return temp->data;
        }
    }
    // Replace certain node with another new value
    void replaceAt(elementType newElement, int index){
        if(index <= 0 or index > length) return;
        // If the index is at the first node
        else if(index == 1)
            head->data = newElement;
        // If the index is at the last node
        else if(index == length)
            tail->data = newElement;
        else{
            Node<elementType>* temp = head;
            // Loop until reaching the desired position
            for(int i = 1; i < index; ++i)
                temp = temp->next;
            temp->data = newElement;
        }
    }
    // Check if the item exists in the list
    bool isExist(elementType element){
        Node<elementType>* temp = head;
        // Loop until reaching the end of the list
        while(temp != nullptr){
            if(temp->data == element)
                return true;
            temp = temp->next;
        }
        return false;
    }
    // Check if certain element is at certain position
    bool isItemAtEqual(elementType element, int index){
        if(index <= 0 or index > length) return false;
        return retrieveAt(index) == element;
    }
    // TODO: Swap two nodes without swapping data
    // void swap(int firstItemIdx, int secondItemIdx){}
    // Check if the list is empty
    bool isEmpty() const { return length == 0; }
    // Get the size of the linked list
    int linkedListSize() const { return length; }
    // Clear all nodes in the list
    void clear(){
        while(!isEmpty())
            this->removeAtHead();
        length = 0;
    }
    // Display nodes of the linked list
    void print() const {
        if(isEmpty()){
            cerr << "List is EMPTY!! No elements to show!\n";
            return;
        }
        // Traverse the queue and print the items
        Node<elementType>* temp = head;
        while(temp != nullptr){
            cout << temp->data << " ";
            temp = temp->next;
        }
        cout << "\n";
    }
};