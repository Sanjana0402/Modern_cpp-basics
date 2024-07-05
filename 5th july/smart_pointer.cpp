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

// void Magic(Data d1){

//     std::cout << d1<<"\n";
// }

// int main(){
//     Data d1{11};

//     Magic(Data {100});
// }

int main()
{
    int32_t x{10};
    char grade{'A'};
    // int *ptr1 = (int *)malloc(4);
    // char *ptr2 = (char *)malloc(1);

    std::unique_ptr<int> ptr1{(int *)malloc(4)};
    std::unique_ptr<int> ptr2{new int()};
    std::unique_ptr<char> ptr3{(char *)malloc(1)};

    Data* d1{new Data{100}};
    std::unique_ptr<Data> ptr4{d1};

    delete d1;
}

/*
    unique pointer
    weak pointer

*/