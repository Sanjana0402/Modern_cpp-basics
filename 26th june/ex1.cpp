/*
    More about lambdas:

        1) WHAT ARE THEY EXACTLY?
            - objects of an anonymous class in the background created by the compiler
        2) WHAT IS [] 
            - if we want to access objects / variables created int the enclosing function of the lambda , we use [] that is capture
        3) SOME WEIRD THINGS TO KNOW ABOUT THIS

*/

#include <iostream>
#include<functional>

void add (int32_t n1,int32_t n2){
    std::cout << n1 + n2 << "\n";
}

int main()
{

    int data = 20;
    /*
        lambda object is bound to fn variable in the scope of main function
    */

    auto fn = [data](int32_t n1, int32_t n2){std::cout << n1 + n2 << "\n";};

    // data is captured in another thing and can be taken anywhere else

    fn(10,20); //overload() operator of a class created in the background
}

/*
    capture clause

    int n1 = 10;
    int n1 = 10;
    int n1 = 10;
    
    ex1 : use of no capture variables
        auto fn = [](){std::cout << "hello";};
    
    ex2 : use of no capture variables but passed parameters 
        auto fn = [](int n1,int n2){std::cout << n1 + n2;};
        fn(n1,n2);

    ex3 : use n1 as capture variable n1 should be copied into the lambda 
        auto fn = [n1](int n2){std::cout << n1 + n2;};
        fn(n2); // only n2 is passed as n1 was already captured

    ex4 : use n1 as capture variable n1 should be referred into the lambda 
        auto fn = [&n1](int n2){std::cout << n1 + n2;};
        fn(n2); // only n2 is passed as n1 was already captured by reference

    ex5 : capture all variables from the surrounding (make them all accessible in the lambda).(copied 
        everything into the lambda when they are accessed in the body of lambda)
        auto fn = [=](){std::cout << n1 + n2 + n3;};
        fn(); // all variables are captured and are copied

    ex5 : capture all variables from the surrounding (make them all accessible in the lambda).(refer
-        everything into the lambda when they are accessed in the body of lambda)
        auto fn = [&](){std::cout << n1 + n2 + n3;};
        fn(); // all variables are captured by reference into the lambda
   
*/