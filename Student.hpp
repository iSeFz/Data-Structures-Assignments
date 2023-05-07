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
    Student() : name(""), id(0), gpa(0), dept("") {}
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

    bool operator < (Student& another) const{
        return (this->id < another.id);
    }

    bool operator > (Student& another) const{
        return (this->id > another.id);
    }

    bool operator == (Student& another) const{
        return (this->id == another.id);
    }

    bool operator != (Student& another) const{
        return (this->id != another.id);
    }

    friend ostream& operator << (ostream& out,Student& s);
    friend istream& operator >> (istream& in, Student& s);
};

ostream& operator << (ostream& out,Student& s){
    out << "[" << s.id << ", " << s.name << ", " << s.gpa << ", " << s.dept << "]";
    return out;
}
istream& operator >> (istream& in, Student& s){
    cout << "Id: ";
    in >> s.id;
    cout << "Name: ";
    in >> s.name;
    cout << "GPA: ";
    in >> s.gpa;
    cout << "Department: ";
    in >> s.dept;
    return in;
}
