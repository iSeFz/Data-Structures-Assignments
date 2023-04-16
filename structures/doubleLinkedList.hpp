#include<iostream>

template <typename T>
class doubleLinkedList {
private:
    template<typename elemType = T>
    struct Node{
        elemType info;
        Node *prev, *next;
    };
    Node<T> *head;
    Node<T> *tail;
    int size;
public:
    doubleLinkedList();
    void insertAtHead(T elem);
    void insertAtTail(T elem);
    void insertAt(T elem, int index);
    void insertAfter(Node<T> *prevNode, T data);
    void removeAtHead();
    void removeAtTail();
    void removeAt(int index);
    T retrieveAt(int index) const;
    void replaceAt(T newElem, int index);
    bool isExist(T elem) const;
    bool isItemAtEqual(T otherElem, int index) const;
    void swap(int firstItemIndex, int secondItemIndex);
    void reverse();
    bool isEmpty() const;
    int doubleLinkedListSize() const;
    void clear();
    void forwardTraversal();
    void backwardTraversal();
};

template<typename T>
doubleLinkedList<T>::doubleLinkedList() {
    head = tail = nullptr;
    size = 0;
}

template<typename T>
void doubleLinkedList<T>::insertAtHead(T elem) {
    Node<T> *newNode = new Node<T>;
    newNode->info = elem;
    if (head == nullptr){
        // if list is empty
        newNode->prev = newNode->next = nullptr;
        head = tail = newNode;
    } else {
        // else list not empty
        newNode->next = head;
        newNode->prev = nullptr;
        head = newNode;
    }
    size++;
}

template<typename T>
void doubleLinkedList<T>::insertAtTail(T elem) {
    Node<T> *newNode = new Node<T>;
    newNode->info = elem;
    if (head == nullptr){
        // list is empty
        newNode->next = newNode->prev = nullptr;
        head = tail = newNode;
    } else {
        // list not empty
        tail->next = newNode;
        newNode->prev = tail;
        newNode->next = nullptr;
        tail = newNode;
    }
    size++;
}
// after insertion, element that was previously at index becomes at index+1
template<typename T>
void doubleLinkedList<T>::insertAt(T elem, int index) {
    if (index<0 || index>size) {
        std::cerr << "Index out of range\n";
        return;
    }
    if (index == 0){
        insertAtHead(elem);
        return;
    }
    if (index == size){
        insertAtTail(elem);
        return;
    }

    Node<T> *currNode = head;
    int count = 0;
    while (count < index){
        currNode = currNode->next;
        count++;
    }
    // currNode is the node to be inserted at
    Node<T> *newNode = new Node<T>;
    newNode->info = elem;

    // linking b/w newNode and the node previous to currNode
    newNode->prev = currNode->prev;
    currNode->prev->next = newNode;

    // linking b/w newNode and currNode
    newNode->next = currNode;
    currNode->prev = newNode;

    size++;
}

template<typename T>
void doubleLinkedList<T>::insertAfter(Node<T> *prevNode, T data) {
    if (prevNode == nullptr){
        std::cerr << "Pointer is NULL!\n";
        return;
    }
    if (prevNode == tail){
        insertAtTail(data);
        return;
    }

    Node<T> *newNode = new Node<T>;
    newNode->info = data;

    // linking b/w newNode and the element to its right
    newNode->next = prevNode->next;
    prevNode->next->prev = newNode;

    // linking b/w newNode and prevNode
    prevNode->next = newNode;
    newNode->prev = prevNode;

    size++;
}

template<typename T>
void doubleLinkedList<T>::removeAtHead() {
    Node<T> *tmp = head;
    head = head->next;
    delete tmp;
    size--;
}

template<typename T>
void doubleLinkedList<T>::removeAtTail() {
    Node<T> *tmp = tail;
    tail = tail->prev;
    delete tmp;
    size--;
}

template<typename T>
void doubleLinkedList<T>::removeAt(int index) {
    if (index<0 || index>=size){
        std::cerr << "Index out of range!\n";
        return;
    }

    if (index == 0)
        removeAtHead();
    if (index == size-1)
        removeAtTail();

    Node<T> *currNode = head;
    int count = 0;
    while (count<index){
        currNode=currNode->next;
        count++;
    }
    // now currNode is the node to be removed
    currNode->prev->next = currNode->next;
    currNode->next->prev = currNode->prev;
    delete currNode;
    size--;
}

template<typename T>
T doubleLinkedList<T>::retrieveAt(int index) const {
    Node<T> *currNode = head;
    int count = 0;
    while (count<index){
        currNode=currNode->next;
        count++;
    }
    // now currNode is the node to be retrieved
    return currNode->info;
}

template<typename T>
void doubleLinkedList<T>::replaceAt(T newElem, int index) {
    if (index<0 || index>=size){
        std::cerr << "Index out of range\n";
        return;
    }
    Node<T> *currNode = head;
    int count = 0;
    while (count<index){
        currNode=currNode->next;
        count++;
    }
    // now currNode is the node to have its info modified
    currNode->info = newElem;
}

template<typename T>
bool doubleLinkedList<T>::isExist(T elem) const {
    Node<T> *currNode = head;
    while (currNode!= nullptr){
        if (currNode->info == elem)
            return true;
        currNode = currNode->next;
    }
    return false;
}

template<typename T>
bool doubleLinkedList<T>::isItemAtEqual(T otherElem, int index) const {
    Node<T> *currNode = head;
    int count = 0;
    while (count<index){
        currNode = currNode->next;
        count++;
    }
    return otherElem == currNode->info;
}

// TO DO !!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!! - case when firstNode or secondNode is head or tail is NOT handled
template<typename T>
void doubleLinkedList<T>::swap(int firstItemIndex, int secondItemIndex) {
    if(firstItemIndex<0||firstItemIndex>=size||secondItemIndex<0||secondItemIndex>=size||firstItemIndex==secondItemIndex){
        std::cerr << "Invalid index(es)\n";
        return;
    }

    // firstNode and secondNode holds the nodes to be swapped
    Node<T> *firstNode = head, *secondNode;
    int count = 0;
    int index = (firstItemIndex<secondItemIndex)?firstItemIndex:secondItemIndex;
    while (count<index){
        firstNode=firstNode->next;
        count++;
    }
    secondNode = firstNode;
    index = (firstItemIndex<secondItemIndex)?secondItemIndex:firstItemIndex;
    while (count<index){
        secondNode=secondNode->next;
        count++;
    }

    // swapping the nodes without swapping the data

    firstNode->prev->next = secondNode;
    firstNode->next->prev = secondNode;

    secondNode->prev->next = firstNode;
    secondNode->next->prev = firstNode;

    Node<T> tmpNode = secondNode;

    secondNode->next = firstNode->next;
    secondNode->prev = firstNode->prev;

    firstNode->next = tmpNode.next;
    firstNode->prev = tmpNode.prev;
}


template<typename T>
void doubleLinkedList<T>::reverse() {
    Node<T> *tmp, *currNode = head;
    while (currNode!=tail){
        tmp = currNode->next;
        currNode->next = currNode->prev;
        currNode->prev = tmp;
    }
    tmp = head;
    head = tail;
    tail = tmp;
}

template<typename T>
bool doubleLinkedList<T>::isEmpty() const {
    return size == 0;
}

template<typename T>
int doubleLinkedList<T>::doubleLinkedListSize() const {
    return size;
}

template<typename T>
void doubleLinkedList<T>::clear() {
    Node<T> *tmp;
    while (size--){
        tmp = head;
        head = head->next;
        delete tmp;
    }
}

template<typename T>
void doubleLinkedList<T>::forwardTraversal() {
    Node<T> *currNode = head;
    while (currNode!= nullptr){
        std::cout << currNode->info << " ";
        currNode = currNode->next;
    }
}

template<typename T>
void doubleLinkedList<T>::backwardTraversal() {
    Node<T> *currNode = tail;
    while (currNode!=nullptr){
        std::cout << currNode->info << " ";
        currNode = currNode->prev;
    }
}



