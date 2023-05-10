#include <fstream>
#include <sstream>
#include <vector>
#include "Structures/AVL.cpp"
#include "Structures/heap.cpp"
#include "Structures/BST.cpp"
#include <limits>

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

// Driver function for the AVL data structure
void useAVL(vector<Student>& students){
    AVL<Student>avl;
    for (int i = 0; i < students.size(); ++i) {
        avl.insert(students[i]);
    }
    avl.menu();
}


void maxHeap(const vector<Student>& students){
    MaxBinaryHeap maxBinaryHeap(students);
    while (true){
        cout << "\nChoose one of the following options:\n"
             << "1- Add student - NOT COMPLETE YET - SOLVE BUGS\n" << "2- Print All (sorted by gpa)\n"
             << "3- Return to main menu\n"
             << "=>:";
        int option;
        cin >> option;
        if (option == 1){
            Student newStudent;
            cin >> newStudent;
            maxBinaryHeap.insert(newStudent);
        } else if (option == 2){
            maxBinaryHeap.printSorted();
        } else if (option == 3) break;
        else cout << "Enter a valid option\n";
    }

}

void mainMenu(int choice, vector<Student>& students) {
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
            maxHeap(students);
            break;
        default:
            break;
    }
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
            cout << "Coming Soon!!\n";
        else if(choice == 4)
            maxHeap(students);
        else if(choice == 5) break;
        else
            cerr << "\n\tINVALID INPUT!! Enter ONLY numbers from 1 to 5\n";
    }
    cout << "\tThank you for using our program!\n";
    return 0;
}
