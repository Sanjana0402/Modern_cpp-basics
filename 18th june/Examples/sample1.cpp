// /*
// problems with regular enums
// */

// #include <iostream>

// enum class Gear
// {
//     FIRST,
//     SECOND
// };
// enum class Student
// {
//     FIRST,
//     SECOND
// };

// void Magic(int n1)
// {
//     std::cout << n1 * 100;
// }

// int main()
// {
//     FIRST; // prblm 1 : not mandatory to prefix enum name (confusion)

//     Gear g1 = Gear::FIRST;
//     Student s1 = Student::FIRST;

//     if (g1 == s1)
//     {
//         std::cout << "OOOOHHHH NOOO!";
//     }

//     // prblm 2 : 2 diff categories get compared on basis of integer value
//     /*
//         Comparing them is logically invalid
//     */

//     Magic(g1);
//     // prblm 3 : auto conversion of enum to integer without consent!!

//     // using class will avoid all the above prblms
// }