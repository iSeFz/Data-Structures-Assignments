#include <fstream>
#include <sstream>
#include <vector>
#include "Structures/AVL.cpp"
#include "Structures/BST.cpp"

// Append student data from file into vector
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

// Driver function for the AVL data structure
void useAVL(vector<Student>& students){
    AVL<Student>avl;
    for (int i = 0; i < students.size(); ++i) {
        avl.insert(students[i]);
    }
    avl.menu();
}

// Driver function for the BST data structure
void useBST(vector<Student>& students){
    BST bst;
    for(auto stud : students)
        bst.addNewStudent(stud);
    bst.menu();
}

// Main function to test the whole program
int main() {
    vector<Student> students;
    ifstream file;
    file.open("students.txt");
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
            cout << "Coming Soon!!\n";
        else if(choice == 4)
            cout << "Coming Soon!!\n";
        else if(choice == 5) break;
        else
            cerr << "\n\tINVALID INPUT!! Enter ONLY numbers from 1 to 5\n";
    }
    cout << "\tThank you for using our program!\n";
    return 0;
}
