#ifndef FUNCTIONALITIES_H
#define FUNCTIONALITIES_H

#include "Employee.h"
#include "Project.h"
#include <list>
#include <functional>

using EmployeeContainer = std::list<Employee*>;
using ProjectContainer =  std::list<Project*>;
using Predicate =  std::function<bool(const Employee*)>;

void CreateObjects(EmployeeContainer employees, ProjectContainer projects, unsigned int size);

void Deallocate(EmployeeContainer employees, ProjectContainer projects, unsigned int size);

void FilterEmployees(const Predicate fn, const EmployeeContainer& employees);

void DisplayProject( const EmployeeContainer& employees);

#endif // FUNCTIONALITIES_H
