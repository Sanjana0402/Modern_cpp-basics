#ifndef NOVALIDENGINEEXCEPTION_H
#define NOVALIDENGINEEXCEPTION_H

#include<stdexcept>

class NoValidEngineException : public std::exception
{
private:
    std::string _m;
    /* data */
public:
    NoValidEngineException(std::string msg):_m{msg}{

    }

    NoValidEngineException() = delete;
    NoValidEngineException(const NoValidEngineException& other)=delete;
    NoValidEngineException& operator=(const NoValidEngineException& other)=delete;
    NoValidEngineException(NoValidEngineException&& other)=default;
    NoValidEngineException& operator=(NoValidEngineException&& other)=delete;
    ~NoValidEngineException() = default;

    virtual const char*
    what() const _GLIBCXX_TXN_SAFE_DYN _GLIBCXX_NOTHROW{
        return _m.c_str();
    }

};

#endif // NOVALIDENGINEEXCEPTION_H
