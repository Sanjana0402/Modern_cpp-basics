/*
    Employee :
        int id, string name, string designation, categorigal Dept, float salary


*/

#include <iostream>
#include "Dept.h"


class Employee
{
private:
    /* data */
    unsigned int m_id{0}; //default value of id that is 0
    std::string m_name{""}; //default name
    std::string m_designation{"executive"};// default
    Dept m_dept{Dept::IT};
    float m_sal{0.0f};

public:
    Employee() = default; //enable the default constructor
    ~Employee() = default; //enable the default destructor
    Employee(const Employee& other) = delete; //disable copy constructor

    /* duplicating data of employee is reduntant therefore it is deleted */

    Employee& operator = (const Employee& other) = delete;
    Employee(Employee&& other) = delete;// move constructor
    Employee& operator = (Employee&& other) = delete;

    Employee(unsigned int id, std::string name,std::string des,Dept dept, float sal):m_id{id},m_designation{des},m_name{name},m_sal{sal},m_dept{dept}
    {
        // this->m_dept = dept;
        // this->m_designation = des;
        // this ->m_id = id;
        // this ->m_name = name;
        // this ->m_sal = sal;
        /*
            to set the parameters before without doing the above
        */

    }
};


// Copy constructor : duplicates data in a new object


int main(){
    // Employee* e1 = new Employee();// heap object with default values created

    Employee *ptr {nullptr};//declaration of a pointer ptr of type Employee[uniform initialization]

    ptr = new Employee();

    ptr = new Employee(101,"Sanjana","Trainee",Dept::IT,9000.0f);//parameterized constructor

    int n1[10];
    int* ptr{nullptr};
    int arr[3] {1,2,3};
    Employee e1{};
    Employee e2{102,"Roushan","Admin",Dept::ADMIN,300000.f};
    //std::list<int> data{1,2,3,4,5};
}