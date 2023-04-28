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
        head->prev = newNode;
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
    head->prev = nullptr;
    delete tmp;
    size--;
}

template<typename T>
void doubleLinkedList<T>::removeAtTail() {
    Node<T> *tmp = tail;
    tail = tail->prev;
    tail->next = nullptr;
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

template<typename T>
void doubleLinkedList<T>::swap(int firstItemIndex, int secondItemIndex) {
    if (firstItemIndex == secondItemIndex){
        std::cerr << "Indices are the same\n";
        return;
    }
    if (firstItemIndex>secondItemIndex){
        int tmp = firstItemIndex;
        firstItemIndex = secondItemIndex;
        secondItemIndex = tmp;
    }
    int count = 0;
    Node<T> *firstNode = head, *secondNode;
    while (count < firstItemIndex){
        firstNode = firstNode->next;
        count++;
    }
    secondNode = firstNode;
    while (count < secondItemIndex){
        secondNode = secondNode->next;
        count++;
    }
    // firstNode and secondNode now points at the nodes corresponding
    // to firstItemIndex and secondItemIndex respectively

    if (firstNode!=head && secondNode!=tail){
        firstNode->prev->next = secondNode;
        firstNode->next->prev = secondNode;

        secondNode->prev->next = firstNode;
        secondNode->next->prev = firstNode;

    } else if (firstNode==head && secondNode!=tail){
        secondNode->prev->next = firstNode;
        secondNode->next->prev = firstNode;

        firstNode->next->prev = secondNode;
        head = secondNode;

    } else if (firstNode!=head && secondNode==tail){
        firstNode->prev->next = secondNode;
        firstNode->next->prev = secondNode;

        secondNode->prev->next = firstNode;
        tail = firstNode;
    } else if (firstNode==head && secondNode==tail){
        firstNode->next->prev = secondNode;
        secondNode->prev->next = firstNode;
        head = secondNode;
        tail = firstNode;
    }

    // swapping next and prev links of the nodes
    Node<T> tmp = *firstNode;
    firstNode->next = secondNode->next;
    firstNode->prev = secondNode->prev;
    secondNode->next = tmp.next;
    secondNode->prev = tmp.prev;
}

template<typename T>
void doubleLinkedList<T>::reverse() {
    Node<T> *tmp, *currNode = head;
    while (currNode != nullptr){
        tmp = currNode->next;
        currNode->next = currNode->prev;
        currNode->prev = tmp;
        currNode = currNode->prev;
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
    while (head != nullptr){
        tmp = head;
        head = head->next;
        delete tmp;
    }
    tail = nullptr;
    size = 0;
}

template<typename T>
void doubleLinkedList<T>::forwardTraversal() {
    if (size == 0){
        std::cerr << "Empty List!\n";
        return;
    }
    Node<T> *currNode = head;
    while (currNode!= nullptr){
        std::cout << currNode->info << " ";
        currNode = currNode->next;
    }
}

template<typename T>
void doubleLinkedList<T>::backwardTraversal() {
    if (size == 0){
        std::cerr << "Empty List!\n";
        return;
    }
    Node<T> *currNode = tail;
    while (currNode!=nullptr){
        std::cout << currNode->info << " ";
        currNode = currNode->prev;
    }
}



