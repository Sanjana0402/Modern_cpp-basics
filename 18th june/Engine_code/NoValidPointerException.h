#ifndef NOVALIDPOINTEREXCEPTION_H
#define NOVALIDPOINTEREXCEPTION_H

#include<iostream>

class NoValidPointerException : public std::exception
{
private:
    std::string m_msg{""};
public:
    NoValidPointerException(std::string msg):m_msg{msg} {}

    NoValidPointerException(const NoValidPointerException&)=delete;//copy construuctor

    NoValidPointerException& operator=(const NoValidPointerException&)=delete;//copy assignment operator

    NoValidPointerException(NoValidPointerException&&)=default;//move constructor

    NoValidPointerException&& operator=(NoValidPointerException&&)=delete;//move assignment operator
    ~NoValidPointerException() {}
};

#endif // NOVALIDPOINTEREXCEPTION_H
