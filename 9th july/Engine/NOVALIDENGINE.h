#ifndef NOVALIDENGINE_H
#define NOVALIDENGINE_H

#include<stdexcept>

class NOVALIDENGINE : public std::exception
{
private:
    /* data */
    std::string _m;    
public:
    NOVALIDENGINE(std::string msg): _m{msg} {}
    ~NOVALIDENGINE() = default;


    NOVALIDENGINE() = delete;

    NOVALIDENGINE(const NOVALIDENGINE& other) = delete;
    NOVALIDENGINE& operator= (const NOVALIDENGINE& other) = delete;

    NOVALIDENGINE(NOVALIDENGINE&& other) = default;
    NOVALIDENGINE& operator= (NOVALIDENGINE&& other) = delete;

    virtual const char*
    what() const _GLIBCXX_TXN_SAFE_DYN _GLIBCXX_NOTHROW{
        return _m.c_str();
    }

};

#endif // NOVALIDENGINE_H
