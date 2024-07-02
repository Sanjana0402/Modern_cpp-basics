#include "Functionalities.h"


int main() {
    SmartDevice* devices[3];

    CreateObjects(devices, 3);
    FindIthIndexValue((const SmartDevice*)devices[1],1);
    FindMaxGSTDeviceId((const SmartDevice**)devices,3);

    FilterDevices([](const SmartDevice* s){return s->price() > 60000.f ;},devices,3);

    FilterDevices(

        [](const SmartDevice* s){return s->deviceTechnology() == Technology::BLUETOOTH ;},
        devices,
        3

    );
    

    Deallocate((const SmartDevice**)devices,3);
}