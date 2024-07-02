
#ifndef FUNCTIONALITIES_H
#define FUNCTIONALITIES_H

#include "NoValidEngineException.h"
#include"Engine.h"
// #define size 3
#include<vector>

void CreateEngines(std::vector<Engine*>& arr);

int AverageHorsePower(const std::vector<Engine*>& arr);

float FindTorqueById(const std::vector<Engine*>& arr, unsigned int id);

int FindHorsepowerForMinTorque(const std::vector<Engine*>& arr);

#endif // FUNCTIONALITIES_H