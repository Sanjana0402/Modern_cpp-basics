#include"Functionalities.h"
#include"NoValidPointerException.h"
#include"IdNotFoundException.h"
#include<iostream>

int main()
{
    std::vector<Engine*>engines;
    CreateObjects(engines);
    
    try
    {
        {
            std::cout<<"Average Horsepower="<<AverageHorsePower(engines)<<"\n";
        }
    }
    catch(NoValidPointerException& e)
    {
        std::cerr << e.what() << "\n";
    }
    FindLowestHorsepowerforMinimumTorque(engines);

    try
    {
        FindToqueforGivenId(engines,"101");
    }
    catch(IdNotFoundException& e)
    {
        std::cerr << e.what() << '\n';
    }
    
    
}