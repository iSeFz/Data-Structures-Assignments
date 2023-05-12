#ifndef _BST_HPP
#define _BST_HPP

#include <map>
#include <vector>
#include "Student.hpp"

// Binary Search Tree class
class BST{
private:
    // Node structure
    struct Node{
        Student studentInfo;
        Node *left;
        Node *right;
        Node(const Student &student) : studentInfo(student), left(nullptr), right(nullptr) {}
    };
    // Root node of the tree
    Node *root;
    // Map to count the number of students in each department
    map<string, int> deptCount;
public:
    // Constructor to initialize the tree with current students
    BST(const vector<Student> &students) {
        root = nullptr;
        for(const Student &student : students)
            addNewStudent(student);
    }
    // Add a new student to the tree
    Node* addNewStudent(Node *currentStudent, const Student &student) {
        // Base Case: If the tree is empty or it is a leaf node
        // Create a new node and assign it with the given student id
        if(currentStudent == nullptr){
            currentStudent = new Node(student);
            deptCount[currentStudent->studentInfo.getDept()]++;
        }
        // Move left if the id is less than current node id
        else if(student < currentStudent->studentInfo)
            currentStudent->left = addNewStudent(currentStudent->left, student);
        // Otherwise move right
        else
            currentStudent->right = addNewStudent(currentStudent->right, student);
        return currentStudent;
    }
    // User function to save final tree into root
    void addNewStudent(const Student &student) { root = addNewStudent(root, student); }
    // Get the maximum student ID in the left subtree
    Node* getMaxID(Node *currentStudent){
        // If the tree is empty, there is no max
        if(currentStudent == nullptr) return nullptr;
        // If there is no more nodes on the right
        // Then the current student node has the maximum ID, return this node
        else if(currentStudent->right == nullptr)
            return currentStudent;
        // Otherwise move to the right subtree till find the maximum ID
        else return getMaxID(currentStudent->right);
    }
    // Remove certain student by ID
    Node* removeStudent(Node *currentStudent, int id){
        // If the tree is empty, nothing to delete
        if(currentStudent == nullptr) return nullptr;
        // If the student is in the left subtree
        if(id < currentStudent->studentInfo.getId())
            currentStudent->left = removeStudent(currentStudent->left, id);
        // If the student is in the right subtree
        else if(id > currentStudent->studentInfo.getId())
            currentStudent->right = removeStudent(currentStudent->right, id);
        // If the student ID to remove is at the current node
        // Check for one of the following three states
        else{
            // If the current student node is a leaf node, remove it directly
            if(currentStudent->left == nullptr and currentStudent->right == nullptr){
                // Decrease number of students in the department from which the student is removed
                deptCount[currentStudent->studentInfo.getDept()]--;
                currentStudent = nullptr;
            }
            // If the current student node has only one child at the left subtree
            // Transfer child's data to current node and delete the child
            else if(currentStudent->left != nullptr and currentStudent->right == nullptr){
                // Decrease number of students in the department from which the student is removed
                deptCount[currentStudent->studentInfo.getDept()]--;
                currentStudent->studentInfo = currentStudent->left->studentInfo;
                delete currentStudent->left;
                // Adjust the pointer of left to point to the subtree of the removed child
                currentStudent->left = currentStudent->left->left;
            }
            // If the current student node has only one child at the right subtree
            // Transfer child's data to current node and delete the child
            else if(currentStudent->left == nullptr and currentStudent->right != nullptr){
                // Decrease number of students in the department from which the student is removed
                deptCount[currentStudent->studentInfo.getDept()]--;
                currentStudent->studentInfo = currentStudent->right->studentInfo;
                delete currentStudent->right;
                // Adjust the pointer of right to point to the subtree of the removed child
                currentStudent->right = currentStudent->right->right;
            }
            // If the current student node has two children, find the student node with the maximum ID in the left subtree
            // Transfer its data to the current student node, then remove the student node with the maximum ID
            else{
                // Decrease number of students in the department from which the student is removed
                deptCount[currentStudent->studentInfo.getDept()]--;
                Node *maxInLeft = getMaxID(currentStudent->left);
                currentStudent->studentInfo = maxInLeft->studentInfo;
                currentStudent->left = removeStudent(currentStudent->left, maxInLeft->studentInfo.getId());
            }
        }
        // Finally return the new tree after deleting the required student
        return currentStudent;
    }
    // User function to output the removal results
    void removeStudent(int id) {
        if(searchByID(id)){
            root = removeStudent(root, id);
            cout << "Student Deleted Successfully!\n";
        }
    }
    // Search for certain student by ID
    Node* searchByID(Node *currentStudent, int id) const {
        // If the tree is empty, nothing to search for
        if(currentStudent == nullptr) return nullptr;
        // If the student is found return its node
        if(id == currentStudent->studentInfo.getId())
            return currentStudent;
        // If the given id is less than current id, move left
        else if(id < currentStudent->studentInfo.getId())
            return searchByID(currentStudent->left, id);
        // Otherwise, move right
        else return searchByID(currentStudent->right, id);
    }
    // User function to output the search results
    bool searchByID(int id) const {
        Node *foundStudent = searchByID(root, id);
        // If the student is found, print its information
        if(foundStudent != nullptr){
            cout << "Student is found!\n";
            cout << foundStudent->studentInfo;
            return true;
        }
        cerr << "Student NOT found!\n";
        return false;
    }
    // Print students in order sorted by ID
    void printStudents(Node *start) const {
        if(start == nullptr) return;
        // Inorder traversal [left-root-right]
        printStudents(start->left);
        cout << start->studentInfo;
        printStudents(start->right);
    }
    // Print all students & number of students in each department
    void printAll() const {
        if(root != nullptr){
            printStudents(root);
            cout << "\nStudents per department:\n";
            for(auto &dept : deptCount){
                if(dept.second > 0)
                    cout << dept.first << " " << dept.second << " student(s)\n";
            }
        } else cerr << "\n\tTree is EMPTY! Nothing to print!\n";
    }
};

#endif