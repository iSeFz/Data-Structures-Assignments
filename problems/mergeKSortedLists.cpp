#include <vector>
#include "../structures/singleLinkedList.hpp"

// Merge K Sorted Linked Lists
template <typename T>
SingleLinkedList<T> mergeKSortedLLs(const vector<SingleLinkedList<T>> &lists){
    // Define the final merged list to be returned
    SingleLinkedList<T> finalSortedList;
    // Node to iterate over the lists
    Node<T> *current = nullptr;
    // Define a vector containing heads of all lists passed
    vector<Node<T> *> heads;
    for (const auto &list : lists)
        heads.push_back(list.getHead());
    // Define a pointer to the head of the list with the smallest element
    Node<T> *minHead = nullptr;
    int minIdx = -1;
    // Iterate over the heads until all lists are finished
    while (true){
        // Reset the minHead and minIdx
        minHead = nullptr;
        minIdx = -1;
        // Find the smallest value among all heads
        for (int i = 0; i < heads.size(); i++){
            if (heads[i] != nullptr and (minHead == nullptr or heads[i]->data < minHead->data)){
                minHead = heads[i];
                minIdx = i;
            }
        }
        // Stop when we've reached the end of all lists
        if (minHead == nullptr) break;
        // Append the first element to the finalSortedList
        if (current == nullptr){
            finalSortedList.insertAtHead(minHead->data);
            current = finalSortedList.getHead();
        } else{
            // Append the next smallest element to the finalSortedList
            current->next = new Node<T>(minHead->data);
            current = current->next;
        }
        // Move the head of the list with the smallest element
        heads[minIdx] = minHead->next;
    }
    return finalSortedList;
}

// Driver function to test the above function
int main(){
    // Define lists to test on
    SingleLinkedList<int> list1, list2, list3;
    // Insert elements to list1
    list1.insertAtTail(1);
    list1.insertAtTail(3);
    list1.insertAtTail(5);
    list1.insertAtTail(7);
    // Insert elements to list2
    list2.insertAtTail(2);
    list2.insertAtTail(4);
    list2.insertAtTail(6);
    list2.insertAtTail(8);
    // Insert elements to list3
    list3.insertAtTail(0);
    list3.insertAtTail(9);
    list3.insertAtTail(10);
    // Define a vector of Single Linked Lists
    vector<SingleLinkedList<int>> lists = {list1, list2, list3};
    // Store the resulted Linked List to see the results
    SingleLinkedList<int> output = mergeKSortedLLs(lists);
    output.print();
    return 0;
}
