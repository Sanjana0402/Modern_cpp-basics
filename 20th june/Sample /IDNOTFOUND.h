#ifndef IDNOTFOUND_H
#define IDNOTFOUND_H
// #include <iostream>
// class IdNotFound : public std::exception
// {
// private:
//     std::string m_msg;
// public:
//     IdNotFound(std::string msg) {
//         this->m_msg = msg;
//     }
//     ~IdNotFound() {}

//     virtual const char*
//     what() const _GLIBCXX_TXN_SAFE_DYN _GLIBCXX_NOTHROW{
//         return m_msg.c_str();
//     }

// };

#include<stdexcept>

class IdNotFound : public std::exception
{
private:
    std::string _m;
    /* data */
public:
    IdNotFound(std::string msg):_m{msg}{

    }

    IdNotFound() = delete;
    IdNotFound(const IdNotFound& other)=delete;
    IdNotFound& operator=(const IdNotFound& other)=delete;
    IdNotFound(IdNotFound&& other)=default;
    IdNotFound& operator=(IdNotFound&& other)=delete;
    ~IdNotFound() = default;

    virtual const char*
    what() const _GLIBCXX_TXN_SAFE_DYN _GLIBCXX_NOTHROW{
        return _m.c_str();
    }

};

#endif // IDNOTFOUND_H