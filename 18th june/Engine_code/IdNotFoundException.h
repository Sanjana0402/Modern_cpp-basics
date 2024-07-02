#ifndef IDNOTFOUNDEXCEPTION_H
#define IDNOTFOUNDEXCEPTION_H

#include<iostream>

class IdNotFoundException : public std::exception
{
private:
    std::string m_msg{""};
public:
    IdNotFoundException(std::string msg):m_msg{msg} {}

    IdNotFoundException(const IdNotFoundException&)=delete;//copy construuctor

    IdNotFoundException& operator=(const IdNotFoundException&)=delete;//copy assignment operator

    IdNotFoundException(IdNotFoundException&&)=default;//move constructor

    IdNotFoundException&& operator=(IdNotFoundException&&)=delete;//move assignment operator
    ~IdNotFoundException() {}
};

#endif // IDNOTFOUNDEXCEPTION_H
