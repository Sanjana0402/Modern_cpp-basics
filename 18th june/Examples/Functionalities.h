#ifndef FUNCTIONALITIES_H
#define FUNCTIONALITIES_H

#include "Engine.h"

void CreateEngines(Engine **engines, unsigned int size);

int AverageHorsePower(Engine **engines, unsigned int size);

float FindTorqueByID(Engine **engines, unsigned int size,unsigned int id);

int FindHorsepowerForMinTorqueEngine(Engine **engines, unsigned int size);

#endif // FUNCTIONALITIES_H
