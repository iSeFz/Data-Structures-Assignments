#include <fstream>
#include <sstream>
#include <vector>
#include "student.cpp"

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






int main() {
    vector<Student> students;
    ifstream file;
    file.open("students.txt");
    readFile(file, students);
    print(students);
    return 0;
}