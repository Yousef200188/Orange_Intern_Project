#include <iostream>
#include <vector>
#include <fstream>

using namespace std;


class Person
{
public:
    string name = "  ";
    int age = 0 ;
    int id = 00000;

    Person(){}

    Person(string s, int a, int i) {

        name = s;
        age = a;
        id = i;

    }
   
    virtual void role() = 0;
};


class Manager : public Person
{
private:
    Manager() {}

    static Manager* instance;
   int salary =0 ;


public:

    
    void role() { cout << "manger role "; }
    
    void  set_salary(int s) 
    {
       
            salary = s;
        
    }
     int  get_salary(){
        return salary;
    
    }
     static Manager* get_instance() {
         if (instance == 0) {
             instance = new Manager ();
         }
         return instance;
     }
};
 Manager* Manager ::  instance = 0;

class Student :public Person {
public:
    Student(string s, int a, int i, float g) :Person(s, a, i) {

        gpa = g;
    }
    float gpa;
    void role() { cout << "student role "; }




};
class Instructor :public Person {
public:
    Instructor(string s, int a, int i, int I_sa ,int h ) : Person(s, a, i) {

        salary = I_sa;
        hours = h;
    }
    int salary;
    int hours;
    void role() { cout << "instructor role "; }




};
class Employee :public Person {
public:
    Employee (string s, int a, int i, int E_sa ) :Person(s, a, i) {

        salary = E_sa;
      
    }
    int salary;
      

    void role() { cout << "employee role "; }




};


class Courses {
public:
    string title=" ";
    int Course_id=0000;
    void details() {


    }

};
template<typename T>
void addVectorToFile(const string& filename, const vector<T>& data) {
    ofstream file(filename, ios::app);

    if (file.is_open()) {
        for (const T& obj : data) {
            file << obj.title << endl;
        }

        file.close();
        cout << "Data written to file successfully." << endl;
    }
    else {
        cout << "Unable to open file for writing." << endl;
    }
}
class Department {
public:
    Department(string t, vector<Courses> c) {
        title = t;
        courses = c;
    }
    string title;
    vector<Courses> courses;
    void details() {}
    void add_Courses(Courses c) {
        courses.push_back(c);
        //ofstream MyFile("Courses.txt");
        string courses_file = "TextFile1.txt";
        addVectorToFile(courses_file, courses);


    }
};



int main()
{
    Courses c1;
    c1.Course_id = 123656;
    c1.title = "data structure";
    Courses c2;
    c2.Course_id = 123657;
    c2.title = "data science";
    Courses c3;
    c3.Course_id = 123658;
    c3.title = "algo";

    cout << "Hello World!\n";
}

