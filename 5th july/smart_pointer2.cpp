#include <iostream>
#include <memory>

class Data
{
private:
    /* data */
    int m_value{0};

public:
    Data() = default;

    Data(const Data &) = default;           // copy construuctor
    Data &operator=(const Data &) = delete; // copy assignment operator
    Data(Data &&) = default;                // move constructor
    Data &&operator=(Data &&) = delete;     // move assignment operator

    ~Data() = default;

    explicit Data(int val) : m_value{val} {} // explicit cannot be used for type conversion
    // Data(int val) : m_value {val}{}

    friend std::ostream &operator<<(std::ostream &os, const Data &rhs)
    {
        os << "m_value: " << rhs.m_value;
        return os;
    }
};

// void Magic(std::unique_ptr<Data> &&temp)
// {
// }

// resource : 4 bytes of memory on the heap used by data object with value 100

int main()
{

    std::unique_ptr<Data> ptr4{new Data{100}};
    // std::unique_ptr<Data> ptr5{ptr4};

    // Magic(std::move(ptr4));

    ptr4.reset(new Data{99});
}

/*
    unique pointer
    weak pointer

*/