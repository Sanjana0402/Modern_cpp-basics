#include "Functionalities.h"

int main() {
    // Employee* employees[3];
    // Project* projects[3];

    EmployeeContainer employees;
    ProjectContainer projects;
    
    CreateObjects(employees, projects,3);
    Deallocate(employees, projects,3);
}