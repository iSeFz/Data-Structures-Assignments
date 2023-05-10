#include <iostream>
using namespace std;

// Student Class
class Student{
private:
    int id;
    string name;
    float gpa;
    string dept;
public:
    // Constructors
    Student() : name(""), id(0), gpa(0.0), dept("") {}
    Student(string id) : id(stoi(id)) {}
    Student(string id, string name, string gpa, string dept){
        this->id = stoi(id);
        this->name = name;
        this->gpa = stof(gpa);
        this->dept = dept;
    }

    // Getter methods to get student data
    int getId(){ return id; }
    string getName(){ return name; }
    float getGpa(){ return gpa; }
    string getDept(){ return dept; }

    // Setter methods to set student data
    void setId(string id){ this->id = stoi(id); }
    void setName(string name){ this->name = name; }
    void setGpa(string gpa){ this->gpa = stof(gpa); }
    void setDept(string dept){ this->dept = dept; }

    // Overloading the comparison operators to compare students
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
    // Friend functions to overload the extraction and insertion operators
    friend ostream& operator << (ostream& out,Student& s);
    friend istream& operator >> (istream& in, Student& s);
};

// Overloading the extraction operator
ostream& operator << (ostream& out,Student& s){
    out << "[" << s.id << ", " << s.name << ", " << s.gpa << ", " << s.dept << "]\n";
    return out;
}

// Overloading the insertion operator
istream& operator >> (istream& in, Student& s){
    string id, name, gpa, dept;
    cout << "Enter student ID >> ";
    in >> id;
    s.setId(id);
    cout << "Enter student Name >> ";
    in.clear();
    in.ignore();
    getline(in, name);
    s.setName(name);
    cout << "Enter student GPA >> ";
    in.clear();
    in >> gpa;
    s.setGpa(gpa);
    cout << "Enter student Department >> ";
    in.clear();
    in >> dept;
    s.setDept(dept);
    return in;
}
