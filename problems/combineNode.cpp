#include <iostream>
#include "../structures/singleLinkedList.hpp"
using namespace std;

void combineNodes(SingleLinkedList<int> &sll){
    // declare needed variables
    Node<int>* focused = sll.getHead();
    Node<int>* incremented = focused;
    Node<int>* temp = nullptr;
    int sum = 0;
    // iterate through the linked list until the end
    while (focused->next != nullptr){
        // if focused at the beginning of sequence
        if(focused->data == 0){
            if(focused == incremented){
                incremented = focused->next;
            }
            else{
                incremented = incremented->next;
            }
            // get the sum of the sequence between focused and incremented
            sum += incremented->data;
        }
        // if increment is at end of sequence
        if(incremented->data == 0){
            // put sum at focused which is first node in sequence
            focused->data = sum;
            sum = 0;
            Node<int>* accumulatedNode = focused;
            // delete nodes between focused and incremented
            while(focused != incremented){
                focused = focused->next;
                delete temp;
                temp = focused;
            }
            // made focused->next equal to end of sequence
            accumulatedNode->next = incremented;
            // move focused to end of sequence
            focused = incremented;
            temp = nullptr;
        }
    }
    // remove last node in sequence which is zero
    sll.removeAtTail();
}






int main() {
    int arr[] =  {0, 3, 1, 0, 4, 0, 2, 0};
    int size = sizeof (arr)/ sizeof (arr[0]);
    SingleLinkedList<int> sll;
    for (int i = 0; i < size; ++i) {
        sll.insertAtTail(arr[i]);
    }
    cout << "List elements before combination: "; sll.print();
    combineNodes(sll);
    cout << "List elements after combination: "; sll.print();
    return 0;
}