#include<vector>
#include<functional>
#include<iostream>


void Magic(int& data){
    std::cout<<data;
}

int main(){

    int n1 = 10;

    // std::reference_wrapper<int> ref = n1; //ref is a reference to n1

    //ref is an alternate name for n1 in main

    // Magic(n1);// int& data = n1;

    // int& arr[1] {ref};

    // std::reference_wrapper<int> arr[1] {ref};

    // std::vector<std::reference_wrapper<int>> ref{n1} ;
    std::reference_wrapper<int> ref{n1} ;

    // std::cout<<v1[0].get(); //get value inside wrapper in 0 position of vector
    Magic(ref);
}



