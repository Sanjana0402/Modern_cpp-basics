/*
    elision : not do something , not perform something ,
                ignore/avoid something

        Guranteed copy elision : cpp17 
*/
#include<iostream>

class Data
{
private:
    /* data */
    int m_value{0};
public:
    Data ()= default;

    Data(const Data&)=default;//copy construuctor

    Data& operator=(const Data&)=delete;//copy assignment operator

    Data(Data&&)=default;//move constructor

    Data&& operator=(Data&&)=delete;//move assignment operator

    ~Data ()= default;

    explicit Data(int val) : m_value {val}{} //explicit cannot be used for type conversion
    // Data(int val) : m_value {val}{}

    friend std::ostream &operator<<(std::ostream &os, const Data &rhs) {
        os << "m_value: " << rhs.m_value;
        return os;
    }
};


void Magic(Data d1){

    std::cout << d1<<"\n";
}


int main(){
    Data d1{11};

    Magic(Data {100});
}