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

void print(vector<Student> students){
    for (auto el : students){
        el.print();
    }
}



void mainMenu(int choice, vector<Student>& students){
    cout << "Choose Data Structure:\n\t"
    << "1. BST\n\t2. AVL\n\t3. Min Heap\n\t4. Max Heap\n\t5. Exit";
    switch (choice) {
        case 1: // BST menu
            break;
        case 2: // AVL menu
            break;
        case 3: // Min heap
            break;
        case 4: // Max heap
            break;
        default: break;
    }
}




int main() {
    vector<Student> students;
    int choice = 0;
    ifstream file;
    file.open("students.txt");
    readFile(file, students);
    while (choice != 5){
        mainMenu(choice, students);
        cout << "\nEnter number of option: ";
        cin >> choice;
    }
    return 0;
}