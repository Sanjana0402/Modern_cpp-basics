#ifndef IDNOTFOUND_H
#define IDNOTFOUND_H

#include<stdexcept>

class IDNOTFOUND : public std::exception
{
private:
    /* data */
    std::string _m;    
public:
    IDNOTFOUND(std::string msg): _m{msg} {}
    ~IDNOTFOUND() = default;


    IDNOTFOUND() = delete;

    IDNOTFOUND(const IDNOTFOUND& other) = delete;
    IDNOTFOUND& operator= (const IDNOTFOUND& other) = delete;

    IDNOTFOUND(IDNOTFOUND&& other) = default;
    IDNOTFOUND& operator= (IDNOTFOUND&& other) = delete;

    virtual const char*
    what() const _GLIBCXX_TXN_SAFE_DYN _GLIBCXX_NOTHROW{
        return _m.c_str();
    }

};

#endif // IDNOTFOUND_H
