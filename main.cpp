#include <fstream>
#include <sstream>
#include <vector>
#include "Student.hpp"
#include "Structures/AVL.cpp"

void readFile(ifstream& file, vector<Student>& students){
    int studentCount, count = 0;
    string line, data, name, dept, id, gpa;
    file >> studentCount;
    stringstream ss;
    file.ignore();
    while (getline(file,line)){
        count++;
        if(count == 2)
            name = line;
        else
            data += line + " ";
        if(count == 4){
            ss << data;
            ss >> id >> gpa >> dept;
            students.push_back(Student(name, gpa, dept, id));
            count = 0;
            data = "";
        }
    }

}

void useAVL(vector<Student>& students){
    AVL<Student>avl;
    for (int i = 0; i < students.size(); ++i) {
        avl.insert(students[i]);
    }
    avl.menu();
}




void mainMenu(vector<Student>& students){
    int choice;
    cout << "Choose Data Structure:\n\t"
    << "1. BST\n\t2. AVL\n\t3. Min Heap\n\t4. Max Heap\n\t5. Exit\n";
    cout << "\nEnter number of option: ";
    cin >> choice;
    while (choice != 5){
        switch (choice) {
            case 1: // BST menu
                break;
            case 2:
                useAVL(students);
                break;
            case 3: // Min heap
                break;
            case 4: // Max heap
                break;
            default: break;
        }
        cout << "Choose Data Structure:\n\t"
             << "1. BST\n\t2. AVL\n\t3. Min Heap\n\t4. Max Heap\n\t5. Exit\n";
        cout << "\nEnter number of option: ";
        cin >> choice;
    }
}




int main() {
    vector<Student> students;
    ifstream file;
    file.open("students.txt");
    readFile(file, students);
    mainMenu(students);
    return 0;
}