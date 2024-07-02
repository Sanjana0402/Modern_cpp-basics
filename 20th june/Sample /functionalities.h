
#ifndef FUNCTIONALITIES_H
#define FUNCTIONALITIES_H

#include "NoValidEngineException.h"
#include"Engine.h"
// #define size 3
#include<vector>

using Container = std::vector<Engine*>;

void CreateEngines(Container& arr); //data container

int AverageHorsePower(const Container& arr);

float FindTorqueById(const Container& arr, unsigned int id);

int FindHorsepowerForMinTorque(const Container& arr);

void DeallocateMemory(Container& arr);
#endif // FUNCTIONALITIES_H