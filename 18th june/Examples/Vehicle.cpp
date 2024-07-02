#include<iostream>

class Vehicle
{
private:
    /* data */
    std::string id{""};
    std::string name{""};
public:
    Vehicle() = delete;
    ~Vehicle() = default;
    /*
         this is a vehicle constructor that takes one const lvalue reference to a vehicle as a parameter
    */
   Vehicle(const Vehicle& other) = delete;//copy constructor disabled
//    Vehicle(const Vehicle& other) = default;//copy constructor enabled

   Vehicle(std::string id, std::string name):id{id},name{name}{}
};

int main(){
    // Vehicle v1{"101","Dzire"};

    // Vehicle v2{v1};// v2[101|Dzire] : enabled copy constructor is used for this

    
}