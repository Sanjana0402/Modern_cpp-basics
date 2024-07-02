#include "Functionalities.h"

void CreateObjects(EmployeeContainer employees, ProjectContainer projects, unsigned int size)
{
    projects.emplace_back(new Project("c.111", 10, 1000.0f));
    projects.emplace_back(new Project("c.221", 50, 11000.0f));
    projects.emplace_back(new Project("c.331", 20, 10000.0f));

    auto itr = projects.begin(); // its id pointing to the begining of the projects list

    employees.emplace_back(new Employee(101, "Harshit", **itr++));
    employees.emplace_back(new Employee(101, "Rohan", **itr++));
    employees.emplace_back(new Employee(101, "Riya", **itr++));
}

void Deallocate(EmployeeContainer employees, ProjectContainer projects, unsigned int size)
{
    for (Employee *e : employees)
    {
        delete e;
    }
    for (Project *p : projects)
    {
        delete p;
    }
}

void FilterEmployees(const Predicate fn, const EmployeeContainer& employees)
{
    for(const Employee* e : employees){
        if(fn(e)) {
            std::cout<< *e << "\n";
        }
    }
}

void DisplayProject(const EmployeeContainer &employees)
{
    for (Employee* e : employees){
        std::cout<<e->project().budget() <<"\n";
    }
}
