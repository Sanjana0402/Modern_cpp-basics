#include "functionalities.h"
#include "IDNOTFOUND.h"
#include "Engine.h"


// void CreateEngines(Engine **arr)
// {
//     arr[0] = new Engine(101, 44, 60.0f);
//     arr[1] = new Engine(102, 45, 90.0f);
//     arr[2] = new Engine(103, 46, 70.0f);
// }


// int CalculateAverageOfHorsepower(Engine ** arr)
// {
// return 0;
// }

// int AverageHorsePower(Engine **arr)

// {
//     if (size < 0)
//     {
//         std::cerr << "Size can't be negative\n";
//     }
//     int avg = 0;
//     bool flag = false;
//     int cnt = 0;
//     for (int i = 0; i < size; i++)
//     {
//         if (arr[i])
//         {
//             cnt++;
//             flag = true;
//             avg = avg + arr[i]->horsepower();
//         }
//     }
//     if (flag)
//     {
//          avg = avg / cnt;
         
//          return avg;
//     }
    
//     throw IdNotFound("Id not found");
    
// }

// float FindTorqueById(Engine **arr, int id)
// {
//     if (size < 0)
//     {
//         std::cerr << "Size can't be negative " << "\n";
//     }
//     for (int i = 0; i < size; i++)
//     {
//         if (arr[i] && arr[i]->id() == id)
//         {
//             return arr[i]->torque();
//         }
//     }
//     throw IdNotFound("Id not found");
    
// }

// int FindHorsepowerForMinTorque(Engine **arr)
// {
//     int cnt = 0;
//     int min = arr[0]->torque();
//     for (int i = 0; i < size; i++)
//     {
//         if (arr[i]->torque() < min)
//         {
//             min = arr[i]->torque();
//             cnt = i;
//         }
//     }
//     return arr[cnt]->horsepower();
// }

/*
    whatever u write in the emplace back it should be "sufficient material" to make a new instance for the container of that specific type


    type : vector of Engine pointer ---->we need materials to make a new Engine
*/



void CreateEngines(std::vector<Engine *> &arr)
{
    arr.emplace_back(new Engine(102, 167, 80.0f));
    arr.emplace_back(new Engine(101, 89, 60.0f));
    arr.emplace_back(new Engine(103, 50, 70.0f));
    // arr.emplace_back{nullptr};//segmentation fault
}

int AverageHorsePower(const std::vector<Engine *> &arr)
{
    float total{0.0f}; //uniform inialization
    std::size_t validPointerCount{0};



    //range based for loop(for-each loop)

    /*
        for each const Engine pointer "called e" present in arr
    */


    for(const Engine* e : arr){
        if(e){
            total += e->horsepower();
            validPointerCount++;
        }
    }


    // for(std::size_t i = 0 ; i < arr.size() ; i++)
    // {
    //     if (arr[i])
    //     {
    //         validPointerCount++;
    //         total += arr[i]->horsepower();
    //     }
        
    // }


    if(validPointerCount == 0){
        throw NoValidEngineException("all pointers are invalid");
    }
    return total/validPointerCount;
}

float FindTorqueById(const std::vector<Engine *> &arr,unsigned int id)
{
    bool atleastOneValidPointer {false};
    
    for(const Engine* e : arr){
        if(e){
            atleastOneValidPointer = true;
            if(e->id()==id)
            {
                return e -> torque();
            }
        }
    }   

    if(!atleastOneValidPointer){
        throw NoValidEngineException("No valid engines present in Data. Search cannot be performed");
    }

    throw IdNotFound("Match not found");
}

int FindHorsepowerForMinTorque(const std::vector<Engine *> &arr)
{
    bool atleastOneValidPointer {false};

    float currentMinTorque{arr[0]->torque()};//min initialized

    std::size_t indexofMinTorque{1};//storing index
    std::size_t k=0;

// each time min is found index is updated
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
