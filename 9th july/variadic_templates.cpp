/*
cpp11 - create a function in c++ that can accept 1 or more arguments

*/

#include <iostream>
// base case : only 1 argument for addition

template <typename T>
T add(T val)
{
    return val;
}

template <typename T, typename... Other> // ellipis
auto add(T n1, Other... args)
{
    return n1 + add(args...); // recursion part - take add of first number and the remaining
}

int main()
{

    std::cout << add<int>(1, 2, 3) << "\n"; // 6
    std::cout << add<int>(1) << "\n";       // 1
    std::cout << add<int>(1, 2) << "\n";    // 3
}