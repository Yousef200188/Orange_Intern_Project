#include <iostream>
#include <vector>
#include <fstream>

using namespace std;


class Person
{
public:
    string name = "  ";
    int age = 0;
    int id = 00000;

    Person() {}

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
    int salary = 0;


public:


    void role() { cout << "manger role "; }

    void  set_salary(int s)
    {

        salary = s;

    }
    int  get_salary() {
        return salary;

    }
    static Manager* get_instance() {
        if (instance == nullptr) {
            instance = new Manager();
        }
        return instance;
    }
};
Manager* Manager::instance = nullptr;

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
    Instructor(string s, int a, int i, int I_sa, int h) : Person(s, a, i) {

        salary = I_sa;
        hours = h;
    }
    int salary;
    int hours;
    void role() { cout << "instructor role "; }




};
class Employee :public Person {
public:
    Employee(string s, int a, int i, int E_sa) :Person(s, a, i) {

        salary = E_sa;

    }
    int salary;


    void role() { cout << "employee role "; }




};


class Courses {
public:
    string title = " ";
    int Course_id = 0000;
    void details() 
    {
        cout << title << endl << Course_id << endl;


    }

};


class Department
{
public:
    Department(string t, vector<Courses> c) {
        title = t;
        courses = c;
    }
    string title;
    vector<Courses> courses;
   /* void details() 
    {
        cout << title << endl;
        string myText;

        ifstream MyReadFile("Courses.txt");

        while (getline(MyReadFile, myText)) {
            cout << myText;
        }

        MyReadFile.close();


    }*/


    

    void add_Courses(Courses c)
    {
    
        string courses_file = "Courses.txt";
        const string& filename= courses_file;
       const vector<Courses>& data=courses;
        ofstream file(filename, ios::app);                                                       

        if (file.is_open()) {
            for (const Courses& obj : data) {
                file << obj.title << endl;
                file << obj.Course_id << endl;

            }

            file.close();
            cout << "Data written to file successfully." << endl;
        }
        else {
            cout << "Unable to open file for writing." << endl;
        }
       
    }
};

class Faculty {

public:
    Faculty (string t, vector<Student> s, vector<Instructor> i, vector<Employee> e, vector<Department> d) {
        title = t;
        students = s;
        instructors = i;
        employees = e;
        departments = d;
    }
    string title;
    vector<Student> students;
    vector<Instructor> instructors;
    vector<Employee> employees;
    vector<Department> departments;
   /* void details() {
    
        cout << title << endl;
        string myText;

        string arr[4] = {"students.txt","instructor.txt","employees.txt","departments.txt"};
        for (int i = 0; i < 4; i++)
        {

            ifstream MyReadFile(arr[i]);
            while (getline(MyReadFile, myText)) {
                cout << myText;

            }
            MyReadFile.close();
        }
        
    }*/


    void add_Student(Student s)
   {
        string students_file = "students.txt";
        const string& filename = students_file;
        const vector<Student>& data = students;
        ofstream file(filename, ios::app);

        if (file.is_open()) {
     for (const Student& obj : data) {
        file << obj.name << endl;
        file << obj.age << endl;
        file << obj.id << endl;
        file << obj.gpa << endl;

    }

    file.close();
    cout << "Data written to file successfully." << endl;
}
        else {
    cout << "Unable to open file for writing." << endl;
}

    }



    void add_Instrucor(Instructor i)
    {

        string instrucor_file = "instructor.txt";
        const string& filename = instrucor_file;
        const vector<Instructor>& data = instructors;
        ofstream file(filename, ios::app);

        if (file.is_open()) {
            for (const Instructor& obj : data) {
                file << obj.name << endl;
                file << obj.age << endl;
                file << obj.id << endl;
                file << obj.salary << endl;

            }

            file.close();
            cout << "Data written to file successfully." << endl;
        }
        else {
            cout << "Unable to open file for writing." << endl;
        }

    }

    void add_Employee(Employee e)
    {

        string employees_file = "employees.txt";
        const string& filename = employees_file;
        const vector<Employee>& data = employees;
        ofstream file(filename, ios::app);

        if (file.is_open()) {
            for (const Employee& obj : data) {
                file << obj.name << endl;
                file << obj.age << endl;
                file << obj.id << endl;
                file << obj.salary << endl;

            }

            file.close();
            cout << "Data written to file successfully." << endl;
        }
        else {
            cout << "Unable to open file for writing." << endl;
        }

    }
   

    void add_Department(Department d)
    {

        string departments_file = "departments.txt";
        const string& filename = departments_file;
        const vector< Department>& data =departments;;
        ofstream file(filename, ios::app);

        if (file.is_open()) {
            for (const Department& obj : data) {
                file << obj.title << endl;
               

            }

            file.close();
            cout << "Data written to file successfully." << endl;
        }
        else {
            cout << "Unable to open file for writing." << endl;
        }

    }



};

class University {
public:

    University(string t, std::vector <Faculty>  f )
    {
        title = t;
        faclties = f;
    }
    Manager* manager = Manager::get_instance();

    string title;
    vector <Faculty> faclties;
    void details(){
    
    }
 

    void add_Faculty(Faculty f)
    {

        string faclties_files = "faclties.txt";
        const string& filename = faclties_files;
        const vector< Faculty>& data = faclties;;
        ofstream file(filename, ios::app);

        if (file.is_open()) {
            for (const Faculty& obj : data) {
                file << obj.title << endl;


            }

            file.close();
            cout << "Data written to file successfully." << endl;
        }
        else {
            cout << "Unable to open file for writing." << endl;
        }

    }


};


int main()
{
    Courses c1;
    c1.Course_id = 123656;
    c1.title = "data structure";


    
    Courses c2;
    c2.Course_id = 123657;
    c2.title = "data sciense";

    vector<Courses> cc;
    cc.push_back(c1);
    cc.push_back(c2);



    Department d1("cs", cc);
    d1.add_Courses(c2);


   

}
