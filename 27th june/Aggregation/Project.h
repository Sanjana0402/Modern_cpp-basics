#ifndef PROJECT_H
#define PROJECT_H

#include <iostream>

class Project
{
private:
    std::string _id;
    unsigned int _teamSize;
    float _budget;
public:
    Project(std::string id,  unsigned int size, float budget); 
    ~Project();

    unsigned int teamSize() const { return _teamSize; }
    void setTeamSize(unsigned int teamSize) { _teamSize = teamSize; }

    std::string id() const { return _id; }
    void setId(const std::string &id) { _id = id; }

    float budget() const { return _budget; }
    void setBudget(float budget) { _budget = budget; }

    friend std::ostream &operator<<(std::ostream &os, const Project &rhs) {
        os << "_id: " << rhs._id
           << " _teamSize: " << rhs._teamSize
           << " _budget: " << rhs._budget;
        return os;
    }
};

#endif // PROJECT_H
