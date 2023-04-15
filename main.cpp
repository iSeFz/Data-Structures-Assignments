#include "structures/array.hpp"
#include "structures/singleLinkedList.hpp"
#include "structures/stack.hpp"
#include "structures/queue.hpp"
#include "structures/circularLinkedList.hpp"

// Test the implementation of Array-based List data structure
void testArray(){
    // Create an array of integers with a size of 5
    Array<int> arr(5);

    // Insert some elements into the array
    arr.insert(10);
    arr.insert(20);
    arr.insert(30);

    // Print the array
    cout << "Array after insertions: ";
    arr.print();
    cout << endl;

    // Retrieve an element from the array
    int elem = arr.retrieveAt(1);
    cout << "Element retrieved from index 1: " << elem << endl;

    // Replace an element in the array
    arr.replaceAt(25, 1);
    cout << "Array after replacing element at index 1: ";
    arr.print();
    cout << endl;

    // Check if an element in the array is equal to a given element
    bool isEqual = arr.isItemAtEqual(25, 1);
    cout << "Is element at index 1 equal to 25? " << isEqual << endl;

    // Insert an element at a specific index in the array
    arr.insertAt(15, 1);
    cout << "Array after inserting element 15 at index 1: ";
    arr.print();
    cout << endl;

    // Remove an element from the array
    arr.removeAt(2);
    cout << "Array after removing element at index 2: ";
    arr.print();
    cout << endl;

    // Clear the array
    arr.clear();
    cout << "Array after clearing: ";
    arr.print();
    cout << endl;
}

// Test the implementation of Linked List data structure
void testSLL(){
    SingleLinkedList<int> sll;
    sll.insertAtHead(21);
    sll.insertAtHead(11);
    sll.insertAtTail(32);
    sll.insertAtTail(44);
    sll.insertAtTail(53);
    cout << "List elements: "; sll.print();
    cout << "Does 2 exist in the list? ";
    sll.isExist(2) ? cout << "found\n" : cout << "nope\n";
    cout << "Element at index 3 is " << sll.retrieveAt(3) << "\n";
    cout << "Is 3 at index 4? ";
    sll.isItemAtEqual(44, 4) ? cout << "yes\n" : cout << "nope\n";
    sll.insertAt(25, 3);
    cout << "After inserting 25 at position 3:\n";
    sll.print();
    sll.replaceAt(100, 5);
    cout << "After replacing 100 at position 5:\n";
    sll.print();
    sll.removeAt(2);
    cout << "After removing element at position 2:\n";
    sll.print();
    cout << "List size is " << sll.linkedListSize() << "\n";
    cout << "Clearing the list...\n";
    sll.clear();
    cout << "List size is " << sll.linkedListSize() << "\n";
}

// Test the implementation of Circular Linked List data structure
void testCLL(){
    CircularLinkedList<int> sll;
    sll.insertAtHead(21);
    sll.insertAtHead(11);
    sll.insertAtTail(32);
    sll.insertAtTail(44);
    sll.insertAtTail(53);
    cout << "List elements: "; sll.print();
    cout << "Does 2 exist in the list? ";
    sll.isExist(2) ? cout << "found\n" : cout << "nope\n";
    cout << "Element at index 3 is " << sll.retrieveAt(3) << "\n";
    cout << "Is 44 at index 4? ";
    sll.isItemAtEqual(44, 4) ? cout << "yes\n" : cout << "nope\n";
    sll.insertAt(25, 3);
    cout << "After inserting 25 at position 3:\n";
    sll.print();
    sll.replaceAt(100, 4);
    cout << "After replacing 100 at position 4:\n";
    sll.print();
    sll.swap(1, 4);
    cout << "After swapping elements at positions 1 and 4:\n";
    sll.print();
    sll.removeAt(2);
    cout << "After removing element at position 2:\n";
    sll.print();
    cout << "List size is " << sll.circularLinkedListSize() << "\n";
    cout << "Clearing the list...\n";
    sll.clear();
    cout << "List size is " << sll.circularLinkedListSize() << "\n";
}

// Test the implementation of Stack data structure
void testStack(){
    Stack<int> myStack;

    // Test push() function
    myStack.push(10);
    myStack.push(20);
    myStack.push(30);
    myStack.push(40);
    myStack.push(50);

    cout << "Initial stack elements: ";
    myStack.print();

    // Test pop() function
    cout << "Popped element: " << myStack.pop() << "\n";

    cout << "Current stack elements: ";
    myStack.print();
    
    // Test top() function
    cout << "Top element: " << myStack.top() << "\n";

    // Test stackSize() function
    cout << "Size of stack: " << myStack.stackSize() << "\n";

    // Test clear() function
    myStack.clear();
    cout << "After clearing the stack:\n";
    cout << "Size of stack: " << myStack.stackSize() << "\n";
    myStack.print();
}

// Test the implementation of Queue data structure
void testQueue(){
    Queue<int> q;
    q.enqueue(5);
    q.enqueue(10);
    q.enqueue(15);
    q.enqueue(20);
    cout << "Queue Elements: "; q.print();
    cout << "Queue size: " << q.queueSize() << endl;
    cout << "First element: " << q.first() << endl;
    q.dequeue();
    cout << "After dequeue: "; q.print();
    cout << "Queue size: " << q.queueSize() << endl;
    cout << "First element: " << q.first() << endl;
    q.enqueue(25);
    cout << "After enqueue: "; q.print();
    cout << "Queue size: " << q.queueSize() << endl;
    cout << "Clearing Queue....\n";
    q.clear();
    q.print();
    cout << "Queue size: " << q.queueSize() << endl;
}

int main(){
    cout << "Which structure do you want to test?\n";
    cout << "1. Array-based List\n"
            "2. Single Linked List\n"
            "3. Doubly Linked List\n"
            "4. Circular Linked List\n"
            "5. Stack\n"
            "6. Queue\n";
    cout << "Your choice ==> ";
    short choice;
    cin >> choice;
    switch(choice){
        case 1:
            cout << "\tTesting the Array-based List\n";
            testArray();
            break;
        case 2:
            cout << "\tTesting the Single Linked List\n";
            testSLL();
            break;
        case 3:
            cout << "\tDoubly Linked List! Coming Soon!!\n";
            // testDLL();
            break;
        case 4:
            cout << "\tCircular Linked List Coming Soon!!\n";
            testCLL();
            break;
        case 5:
            cout << "\tTesting the Stack\n";
            testStack();
            break;
        case 6:
            cout << "\tTesting the Queue\n";
            testQueue();
            break;
        default:
            cerr << "Invalid Choice!\n";
    }
    cout << "\n\tThank you for using our program!!\n";
    return 0;
}