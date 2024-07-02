#include<iostream>

// void Magic(int& data){//lvalue
//     // .......
// }

// void Magic(const int& data){//Accepts both values
//     // .......
// }

// void Magic(const int&& data){//lvalue and rvalue both not wrking
//     // .......
// }

// void Magic(int&& data){//rvalue
//     // .......
// }

void Magic(int data){//Accepts both values
    // .......
}

int main(){
    Magic(10);
    int n1 = 10;
    Magic(n1);
}