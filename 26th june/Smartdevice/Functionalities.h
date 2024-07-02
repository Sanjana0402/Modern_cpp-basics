#ifndef FUNCTIONALITIES_H
#define FUNCTIONALITIES_H

#include "SmartDevice.h"
#include<functional>

//predicate -----> single function takes return value and gives true or false

using Predicate = std::function<bool(const SmartDevice*)>;

void CreateObjects(SmartDevice** devices, unsigned int size);

void Deallocate(const SmartDevice** devices, const unsigned int size);

void FindIthIndexValue(const SmartDevice* device, unsigned int idx);

void FindMaxGSTDeviceId(const SmartDevice** devices, unsigned int idx);

void FilterDevices(Predicate fn, const SmartDevice** devices,const unsigned int size);

/*

                                                [  10.21  | 9.21  | 11.22 ]
                                                ^
                                                |
    [d101 |Mobile  | 9000.0f    |BLUETOOTH   |0x100H]
    24      24           4           4         8
*/



#endif // FUNCTIONALITIES_H
