#include<iostream>
#include"Engine.h"
#include<vector>

using Container=std::vector<Engine*>;
void CreateObjects(Container& engines);
float AverageHorsePower(Container& engines);
void FindLowestHorsepowerforMinimumTorque(Container &engines);
void FindToqueforGivenId(Container &engines,std::string id);
void Deallocate(Container& engines); 