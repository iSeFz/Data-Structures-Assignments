#include <fstream>
#include <sstream>
#include <vector>
#include "BST.hpp"
#include "AVL.hpp"
#include "MaxHeap.hpp"
#include "MinHeap.hpp"

// Append student data from file into vector
void readFile(ifstream& file, vector<Student>& students){
    int studentCount, lineCount = -1;
    file >> studentCount;
    string line, data, id, name, gpa, dept;
    stringstream ss;
    file.ignore();
    while (getline(file, line)){
        lineCount++;
        if(lineCount == 2)
            name = line;
        else
            data += line + " ";
        if(lineCount == 4){
            ss << data;
            ss >> id >> gpa >> dept;
            students.push_back(Student(id, name, gpa, dept));
            lineCount = 0;
            data = "";
        }
    }
}

// Driver function for the BST data structure
void useBST(const vector<Student>& students){
    BST bst;
    for(auto stud : students)
        bst.addNewStudent(stud);
    bst.menu();
}

// Driver function for the AVL data structure
void useAVL(const vector<Student>& students){
    AVL<Student>avl;
    for(auto stud : students)
        avl.insert(stud);
    avl.menu();
}

// Driver function for the max heap data structure
void maxHeap(const vector<Student>& students){
    MaxBinaryHeap maxBinaryHeap(students);
    while (true){
        cout << "\n\tMax Heap Menu\n"
        << "1. Add new student\n"
        << "2. Print All Students (Sorted by GPA)\n"
        << "3. Return to main menu\n"
        << "Choose one of the above options (1-3) >> ";
        int option;
        cin >> option;
        if (option == 1){
            cout << "\n";
            Student newStudent;
            cin >> newStudent;
            maxBinaryHeap.insert(newStudent);
            cout << "Student Added Successfully!\n";
        } else if (option == 2){
            maxBinaryHeap.printSorted();
        } else if (option == 3) break;
        else cerr << "\n\tINVALID INPUT!! Enter ONLY numbers from 1 to 3\n";
    }
}

// Driver function for the min heap data structure
void minHeap(const vector<Student>& students){
    MinBinaryHeap minBinaryHeap(students);
    while (true){
        cout << "\n\tMin Heap Menu\n"
             << "1. Add new student\n"
             << "2. Print All Students (Sorted by GPA)\n"
             << "3. Return to main menu\n"
             << "Choose one of the above options (1-3) >> ";
        int option;
        cin >> option;
        if (option == 1){
            cout << "\n";
            Student newStudent;
            cin >> newStudent;
            minBinaryHeap.insert(newStudent);
            cout << "Student Added Successfully!\n";
        } else if (option == 2){
            minBinaryHeap.printSorted();
        } else if (option == 3) break;
        else cerr << "\n\tINVALID INPUT!! Enter ONLY numbers from 1 to 3\n";
    }
}
// Main function to test the whole program
int main() {
    vector<Student> students;
    ifstream file("students.txt");
    readFile(file, students);
    // Output the main menu
    short choice;
    while(true){
        cout << "\tAvailable Data Structures\n"
        << "1. BST\n"
        << "2. AVL\n"
        << "3. Min Heap\n"
        << "4. Max Heap\n"
        << "5. Exit\n"
        << "Choose one of the above options (1-5) >> ";
        choice = 0;
        cin >> choice;
        if(choice == 1)
            useBST(students);
        else if(choice == 2)
            useAVL(students);
        else if(choice == 3)
            minHeap(students);
        else if(choice == 4)
            maxHeap(students);
        else if(choice == 5) break;
        else cerr << "\n\tINVALID INPUT!! Enter ONLY numbers from 1 to 5\n";
    }
    cout << "\tThank you for using our program!\n";
    return 0;
}
