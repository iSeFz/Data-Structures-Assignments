#include <iostream>
using namespace std;

class Student
{
private:
    string name;
    int id;
    float gpa;
    string dept;

public:
    Student(string name, string gpa, string dept, string id)
    {
        this->name = name;
        this->gpa = stof(gpa);
        this->dept = dept;
        this->id = stoi(id);
    }

    int getId()
    {
        return id;
    }

    string getName()
    {
        return name;
    }

    float getGpa()
    {
        return gpa;
    }

    string getDept()
    {
        return dept;
    }

    void print(){
        cout << "Name: " << name << endl;
        cout << "ID: " << id << endl;
        cout << "GPA: " << gpa << endl;
        cout << "Department: " << dept << endl;
    }
};