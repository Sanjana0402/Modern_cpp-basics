// #include "Engine.h"
#include "functionalities.h"
#include"IDNOTFOUND.h"
#include<iostream>
int main()
{
//     Engine *arr[3];
//     CreateEngines(arr);
    
//     std::cout<<"The torque of the given id is\n";
//     try{
//         std::cout<<FindTorqueById(arr,102);
//     }
//     catch(std::invalid_argument& ex){
//         std::cerr << ex.what() << "\n";
//     }
//     catch(IdNotFound& ex){
//         std::cerr << ex.what() << "\n";
//     }
//     std::cout<<"\n";

//     std::cout<<"The avg horse power is\n";
//     try{
//         std::cout<<AverageHorsePower(arr);
//     }
//     catch(std::invalid_argument& ex){
//         std::cerr << ex.what() << "\n";
//     }
//     catch(IdNotFound& ex){
//         std::cerr << ex.what() << "\n";
//     }
//     std::cout<<"\n";



//    std::cout<<"The Horse Power for the minimum torque is "<<FindHorsepowerForMinTorque(arr);
//     Engine *arr[3];


    Container arr;

    CreateEngines(arr);
    DeallocateMemory(arr);
    
    std::cout<<"\nThe Average horse power is ";
    try{
        std::cout<<AverageHorsePower(arr)<<"\n";
    }
    catch(NoValidEngineException& ex){
        std::cerr << ex.what() << "\n";
    }
  
    std::cout<<"\n";

    std::cout<<"The torque of the given id is ";
    try{
        std::cout<<FindTorqueById(arr,101)<<"\n";
    }
    catch(NoValidEngineException& ex){
        std::cerr << ex.what() << "\n";
    }
    catch(IdNotFound& ex){
        std::cerr << ex.what() << "\n";
    }
    std::cout<<"\n";


   std::cout<<"The Horse Power for the minimum torque is "<<FindHorsepowerForMinTorque(arr)<<"\n\n";
}


/*
    when exception is thrown we use try catch block for those functions
*/

