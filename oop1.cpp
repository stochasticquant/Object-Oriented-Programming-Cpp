// oop1.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>

// using namespace std : is normally used but not recommeded as it brings all the std content
using std::cout;  
using std::string;
using std::endl;

class AbstractEmployee {
    virtual void AskForPromotion() = 0;
};

class Employee:AbstractEmployee {
 
protected:
    string Name;
    string Company;
    int Age;

public:
    void setName(string name) {
        Name = name;
    }

    string getName() {
        return Name;
    }
    void setCompany(string company) {
        Company = company;
    }

    string getCompany() {
        return Company;
    }

    void setAge(int age) {
        if (age >= 18) {
            Age = age;
        }       
    }

    int getAge() {
        return Age;
    }

    void IntroduceYourself() {
        cout << "Name    : " << Name << endl;
        cout << "Company : " << Company << endl;
        cout << "Age     : " << Age << endl;
        cout << endl;
    }

    void AskForPromotion() {
        if (Age > 30)
            cout << Name << " got promoted!" << endl;
        else
            cout << Name << " sorry NO promotion" << endl;
    }

    void Work() {
        cout << Name << " Checking task backlog" << endl;
    }

    Employee(string name, string company, int age) {
        Name = name;
        Company = company;
        Age = age;
    }
};

class Developer: public Employee {
public:
    string ProgrammingLanguage;

    // constructor
    Developer(string name, string company, int age, string programminglanguage)
        : Employee(name, company, age) {
        ProgrammingLanguage = programminglanguage;

    }

    void FixBug(){
        cout << Name << " fixed bug using " << ProgrammingLanguage << endl;
    }

    // method overloading
    void IntroduceYourself() {
        cout << "Name    : " << Name << endl;
        cout << "Company : " << Company << endl;
        cout << "Age     : " << Age << endl;
        cout << "Programming Language : ProgrammingLanguage" << endl;
        cout << endl;
    }

    void Work() {
        cout << Name << " Coding the backend application" << endl;
    }
};

class Teacher : public Employee {
public:
    string Subject;

    void PrepareLesson() {
        cout << Name << " is preparing " << Subject << " lesson" << endl;
    }

    Teacher(string name, string company, int age, string subject) 
        : Employee(name, company, age) {     
        Subject = subject;
    }

    // method overloading
    void IntroduceYourself() {
        cout << "Name    : " << Name << endl;
        cout << "Company : " << Company << endl;
        cout << "Age     : " << Age << endl;
        cout << "Teaching Language :" << Subject  << endl;
        cout << endl;
    }
};


int main()
{
    Employee employee1 = Employee("Charles", "Musa", 40);
    employee1.IntroduceYourself();
    employee1.setAge(45);
    employee1.IntroduceYourself();
    employee1.AskForPromotion();

    cout << endl;
    Employee employee2 = Employee("Paul", "Google", 25);
    employee2.IntroduceYourself();
    employee2.setAge(23);
    employee2.IntroduceYourself();
    employee1.Work();
    employee2.AskForPromotion();

    cout << endl;
    Developer dev1 = Developer("Peter", "Apple", 34, "C++");
    dev1.IntroduceYourself();
    dev1.FixBug();
    dev1.Work();
    dev1.AskForPromotion();

    cout << endl;
    Teacher teacher1 = Teacher("Mary", "Udemy", 47, "Python");
    teacher1.IntroduceYourself();
    teacher1.PrepareLesson();
    teacher1.AskForPromotion();


    return 0;
}

