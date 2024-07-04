#include <iostream>
#include <array>

int main(){

//a container of fixed size can be used with this syntax
    std::array<int ,2>arr{59589, 22};

    auto [salary, age] =  arr;
}