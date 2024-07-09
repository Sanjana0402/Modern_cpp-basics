#include "Func.h"
#include<iostream>

int main(){

    std::vector<Engine*> arr;

    CreateEngines(arr);

    std::cout<<"\n Average horsepower is ";
    try{
        std::cout << AverageHorsePower(arr) << "\n";
    }
    catch(NOVALIDENGINE& ex){
        std::cerr<<ex.what()<<"\n";
    }

    std::cout<<"\n";

    std::cout<<"Torque of given id : ";
    try {
        std::cout<<FindTorque(arr,"101")<<"\n";
    }
    catch(NOVALIDENGINE& ex){
        std::cerr<<ex.what()<<"\n";
    }
    catch(IDNOTFOUND& ex){
        std::cerr<<ex.what()<<"\n";
    }
    std::cout<<"\n";

    std::cout<<"Horse Power for Min Torque : "<<FindHorsepowerForMinTorque(arr)<<"\n";

    Deallocate(arr);
}