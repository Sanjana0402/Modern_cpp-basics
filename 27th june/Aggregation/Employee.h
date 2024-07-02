#ifndef EMPLOYEE_H
#define EMPLOYEE_H

#include <iostream>
#include "Project.h"


class Employee
{
private:
    int _id;
    std::string _name;
    Project& _project;
public:
    Employee(int id, std::string name, Project& pr);
    ~Employee();

    Project& project() const { return _project; }
    void setProject(const Project& project) { _project = project; }

    std::string name() const { return _name; }
    void setName(const std::string &name) { _name = name; }

    int id() const { return _id; }
    void setId(int id) { _id = id; }

    friend std::ostream &operator<<(std::ostream &os, const Employee &rhs) {
        os << "_id: " << rhs._id
           << " _name: " << rhs._name
           << " _project: " << rhs._project;
        return os;
    }
};

#endif // EMPLOYEE_H

/*
    Project&

    lvalue Reference to a Project
*/
