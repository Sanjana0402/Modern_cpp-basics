#include "Func.h"
#include<iostream>

void CreateEngines(Container &arr)
{
    arr.emplace_back(new Engine("101",40,5.6f,4.5f,Type::ALTERNATE_FUEL));
    arr.emplace_back(new Engine("102",70,3.8f,2.6f,Type::HYBRID));
    arr.emplace_back(new Engine("103",50,7.9f,8.9f,Type::ICE));
}

int AverageHorsePower(const Container &arr)
{
    float total{0.0f};
    std::size_t validPointer{0};

    for(const Engine* e : arr){
        
        if(e){
            total += e->horsepower();
            validPointer++;
        }
    }

    if(validPointer == 0){
        throw NOVALIDENGINE("pointers invalid");
    }
    return total/validPointer;
}

float FindTorque(const Container &arr, std::string id)
{
    bool atleastOneValidPointer{false};

    for(const Engine* e : arr){
        if(e){
            atleastOneValidPointer = true;
            if(e->id() == id){
                return e-> torque();
            }
        }
    }

    if(!atleastOneValidPointer){
        throw NOVALIDENGINE("No valid engines present in Data.");
    }

    throw IDNOTFOUND("Match not found");
}

int FindHorsepowerForMinTorque(const Container &arr)
{
    bool atleastOneValidPointer {false};

    float currentMinTorque{arr[0]->torque()};

    std::size_t indexofMinTorque{1};

    std::size_t k = 0;

    for(const Engine* e : arr){
        if(e){
            atleastOneValidPointer = true;

            if(e->torque()<currentMinTorque){
                currentMinTorque = e->torque();
                indexofMinTorque = k++;
            }
        }
    }

    return arr[indexofMinTorque]->horsepower();
}

void Deallocate(Container &arr)
{
    for(const Engine* e : arr){
        delete e;
    }
}
