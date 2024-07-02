#include"Functionalities.h"
#include<iostream>
#include"NoValidPointerException.h"
#include"IdNotFoundException.h"
#include<stdexcept>

void CreateObjects(Container &engines)
{
    engines.emplace_back(new Engine("101",20,8.1f,Type::DISEL));
    engines.emplace_back(new Engine("102",203,343.9f,Type::HYBRID));
    engines.emplace_back(new Engine("103",3243,990.0f,Type::PETROL));
}

float AverageHorsePower(Container &engines)
{
    float total{0.0f};
    std::size_t count{0};
    for(const Engine *e:engines)
    {
        if(e)
        {
            count++;
            total+=e->horsePower();
        }
    }
    if(count==0)
    {
        throw NoValidPointerException("Pointer Exception thrown");
    }
    return total/count;
}

void FindLowestHorsepowerforMinimumTorque(Container &engines)
{
    float min{engines[0]->torque()};
    bool flag{false};
    std::size_t index{0};
    std::size_t k{0};
    for(const Engine* e:engines)
    {
        if(e)
        {
            flag=true;
            if(e->torque()<min)
            {
                min=e->torque();
                index=k;
            }
        }
        k++;
    }
    std::cout<<"\n Horsepower of minimum torque= "<<engines[index]->horsePower()<<"\n";

   

}

void FindToqueforGivenId(Container &engines,std::string id)
{
    bool flag{false};std::size_t index{0};
    std::size_t k{0};

    for(const Engine*e :engines)
    {
        if(e)
        {
            flag=true;
            if(e->id()==id)
            {
                 index=k;
                std::cout<<"Torque for given id= "<<engines[index]->torque();
            }
        }
        k++;
    }
    if(!flag)
    {
        throw IdNotFoundException("Id not found");
    }
}

void Deallocate(Container &engines)
{
    for(const Engine* e:engines)
    {
        delete e;
    }
}


