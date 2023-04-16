// Circular Linked List Implementation
template <class elementType>
class CircularLinkedList{
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
    CircularLinkedList() : head(nullptr), tail(nullptr), length(0) {}
    // Destructor
    ~CircularLinkedList(){ this->clear(); }
    // Insert node at the beginning of the list
    void insertAtHead(elementType element){
        Node<elementType>* newNode = new Node<elementType>();
        newNode->data = element;
        if(isEmpty())
            tail = newNode;
        else
            newNode->next = head;
        head = newNode;
        tail->next = head;
        length++;
    }
    // Insert node at the end of the list
    void insertAtTail(elementType element){
        Node<elementType>* newNode = new Node<elementType>();
        newNode->data = element;
        newNode->next = head;
        if(isEmpty())
            head = newNode;
        else
            tail->next = newNode;
        tail = newNode;
        length++;
    }
    // Insert node at certain position
    void insertAt(elementType element, int index){
        if(index < 0 or index > length) return;
        Node<elementType>* newNode = new Node<elementType>();
        newNode->data = element;
        if(isEmpty())
            head = tail = newNode;
        else if(index == 0){
            this->insertAtHead(element);
            return;
        }
        else if(index == length - 1){
            this->insertAtTail(element);
            return;
        }
        else{
            Node<elementType>* current = head;
            Node<elementType>* previous = nullptr;
            for(int i = 0; i < index; ++i){
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
            tail->next = head;
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
            tail->next = head;
        }
        length--;
    }
    // Remove node at certain position
    void removeAt(int index){
        if(index < 0 or index > length) return;
            // If the index is at the first node
        else if(index == 0){
            this->removeAtHead();
            return;
        }
            // If the index is at the last node
        else if(index == length - 1){
            this->removeAtTail();
            return;
        }
        else{
            Node<elementType>* current = head;
            Node<elementType>* previous = nullptr;
            // Loop until reaching the desired position
            for(int i = 0; i < index; ++i){
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
        if(index < 0 or index > length) exit(0);
            // If the index is at the first node
        else if(index == 0)
            return head->data;
            // If the index is at the last node
        else if(index == length - 1)
            return tail->data;
        else{
            Node<elementType>* temp = head;
            // Loop until reaching the desired position
            for(int i = 0; i < index; ++i)
                temp = temp->next;
            return temp->data;
        }
    }
    // Replace certain node with another new value
    void replaceAt(elementType newElement, int index){
        if(index < 0 or index > length) return;
            // If the index is at the first node
        else if(index == 0)
            head->data = newElement;
            // If the index is at the last node
        else if(index == length - 1)
            tail->data = newElement;
        else{
            Node<elementType>* temp = head;
            // Loop until reaching the desired position
            for(int i = 0; i < index; ++i)
                temp = temp->next;
            temp->data = newElement;
        }
    }
    // Check if the item exists in the list
    bool isExist(elementType element){
        Node<elementType>* temp = head;
        // Loop until reaching the end of the list
        for(int i = 0; i < length; i++){
            if(temp->data == element)
                return true;
            temp = temp->next;
        }
        return false;
    }
    // Check if certain element is at certain position
    bool isItemAtEqual(elementType element, int index){
        if(index < 0 or index > length) return false;
        return retrieveAt(index) == element;
    }
    // Swap two nodes without swapping data
    void swap(int firstItemIdx, int secondItemIdx){
        // If the list is empty
        if(isEmpty()) return;
        // If two indexes are the same
        if (firstItemIdx == secondItemIdx) return;
        // If one of the indexes is invalid
        if(firstItemIdx < 0 || firstItemIdx > length) return;
        if(secondItemIdx < 0 || secondItemIdx > length) return;

        Node<elementType>* prevX = nullptr , * prevY = nullptr , * currX = head , * currY = head;
        int count = 0;
        while(count < firstItemIdx){
            prevX = currX;
            currX = currX->next;
            count++;
        }
        count = 0;
        while(count < secondItemIdx){
            prevY = currY;
            currY = currY->next;
            count++;
        }
        if(currX == nullptr || currY == nullptr) return;
        // currX is not head of the list
        if(prevX != nullptr)
            prevX->next = currY;
        else
            tail->next = head = currY;
        // currY is not head of the list
        if(prevY != nullptr)
            prevY->next = currX;
        else
            tail->next = head = currX;
        // swap data
        Node<elementType>* temp;
        temp = currY->next;
        currY->next = currX->next;
        currX->next = temp;
    }
    // Check if the list is empty
    bool isEmpty() const { return length == 0; }
    // Get the size of the linked list
    int circularLinkedListSize() const { return length; }
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
        while(temp->next != head){
            cout << temp->data << " ";
            temp = temp->next;
        }
        cout << temp->data << "\n";
    }
};