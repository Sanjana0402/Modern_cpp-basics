#include <iostream>

//  Part 2
// int createN1(){
//     int n1{10};
// }

// int main(){
//     int n1 = createN1();
//     std::cout << n1;
// }

// Part 3

void Display(char grade)
{

    std::cout << grade << "\n";
}

void Demo(int n1, std::string name)
{

    std::cout << n1 << name << "\n";
}

void Temp(float n1, int *ptr, std::string name, char &&grade, const bool &flag)
{

    std::cout << "\t" << n1 << "\t" << *ptr << "\t" << name << "\t" << grade << "\t" << flag << "\n";
}

int main()
{
    Display('A');
    Demo(10, "abc");
    std::string val{"Sanjana"};
    bool flag{true};

    Temp(34.5f, new int(40), val, 'A', flag);
}
