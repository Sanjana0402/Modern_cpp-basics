#include <iostream>
#include <vector>
#include <variant>

int main()
{

    int32_t n1{100};
    std::string s1{"Sanjana"};

    // std::vector<std::string> v1{n1,s1};

    std::variant<int32_t, std::string> vr;

    vr = n1;

    std::cout << "Variant is working\n";

    vr = s1;

    // vr = 41.45f;

    
}