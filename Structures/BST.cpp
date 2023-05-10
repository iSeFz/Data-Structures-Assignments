#include "../Student.hpp"

// Binary Search Tree class
class BST{
private:
    // Node structure
    struct Node{
        Student studInfo;
        Node *left;
        Node *right;
        Node(Student student) : studInfo(student), left(nullptr), right(nullptr) {}
    };
    // Root node of the tree
    Node *root;
public:
    // Constructor
    BST() : root(nullptr) {}
    // Check if the tree is empty
    bool isEmpty() { return root == nullptr; }
    // Add a new student to the tree
    Node* addNewStudent(Node* currentStudent, Student stud) {
        // Create a new node with the given student id
        Node* newNode = new Node(stud);
        // If the tree is empty, add the new node as root
        if(currentStudent == nullptr)
            currentStudent = newNode;
        // Move left if the id is less than current node id
        else if(stud < currentStudent->studInfo)
            currentStudent->left = this->addNewStudent(currentStudent->left, stud);
        // Otherwise move right
        else
            currentStudent->right = this->addNewStudent(currentStudent->right, stud);
        return currentStudent;
    }
    // User function to save final tree into root
    void addNewStudent(Student stud){ root = addNewStudent(root, stud); }
    // TODO: Remove a student by ID
    // Search for a student by ID
    Node* searchByID(Node *currentStudent, int id){
        // If the tree is empty, nothing to search for
        if(currentStudent == nullptr) return nullptr;
        // If the student is found return its node
        if(id == currentStudent->studInfo.getId())
            return currentStudent;
        // If the given id is less than current id, move left
        else if(id < currentStudent->studInfo.getId())
            return searchByID(currentStudent->left, id);
        // Otherwise, move right
        else
            return searchByID(currentStudent->right, id);
    }
    // User function to output the search results
    bool searchByID(int id){
        Node *foundStudent = searchByID(this->root, id);
        // If the student is found, print its information
        if(foundStudent != nullptr){
            cout << "Student is found!\n";
            cout << foundStudent->studInfo;
            return true;
        }
        cerr << "Student NOT found!\n";
        return false;
    }
    // Print all students in order
    void printAllStudents(Node *start) {
        if(start == nullptr) return;
        // Inorder traversal [left-root-right]
        printAllStudents(start->left);
        cout << start->studInfo;
        printAllStudents(start->right);
    }
    // Binary Search Tree User Menu
    void menu(){
        short choice;
        while(true){
            cout << "\n\tBinary Search Tree Menu\n"
            << "1. Add new student\n"
            << "2. Remove student by ID\n"
            << "3. Search student by ID\n"
            << "4. Print All Students\n"
            << "5. Return to main menu\n"
            << "Choose one of the above options (1-5) >> ";
            choice = 0;
            cin >> choice;
            // Get student data from the user
            if(choice == 1){
                cout << "\n";
                Student newStudent;
                cin >> newStudent;
                this->addNewStudent(newStudent);
                cout << "Student Added Successfully!\n";
            }
            else if(choice == 2)
                cout << "Coming Soon!!\n";
            // Search for certain student using ID
            else if(choice == 3){
                short id;
                cout << "\nEnter ID to search for >> ";
                cin >> id;
                searchByID(id);
            }
            // Output all current students sorted by ID
            else if(choice == 4)
                this->printAllStudents(this->root);
            else if(choice == 5) break;
            else
                cerr << "\n\tINVALID INPUT!! Enter ONLY numbers from 1 to 5\n";
        }
    }
};
