#ifndef FUNC_H
#define FUNC_H
#include "IDNOTFOUND.h"
#include "NOVALIDENGINE.h"
#include "Engine.h"

#include<vector>

using Container = std::vector<Engine*>;

void CreateEngines(Container& arr);

int AverageHorsePower(const Container& arr);

float FindTorque(const Container& arr, std::string id);

int FindHorsepowerForMinTorque(const Container& arr);

void Deallocate(Container& arr);


#endif // FUNC_H
