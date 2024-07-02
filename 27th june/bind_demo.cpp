/*
    std::bind allows us to "refactor" / "repurpose" / "remodel" an existing function to create "partially-implemented" functions

    cp    -r      source     destination

    strcpy(destination,source)

*/

#include <iostream>
#include <functional>

void Formula(int x, int y, int z){
    std::cout<<((x+y)-z)<<"\n";
}

int main()
{

    // auto partial_formula = std::bind(&Formula,100,std::placeholders::_1,std::placeholders::_2);

    // partial_formula(10,90); //Formula(100,10,90)

    auto swapped = std::bind(&Formula,std::placeholders::_2,std::placeholders::_3,std::placeholders::_1);

    swapped(10,20,30);//Formula(20,30,10)

    // Formula(10,20,30);
    // Formula(10,30,20);

    auto weirdly_mapped = std::bind(&Formula,100,200,std::placeholders::_2);

    weirdly_mapped(99,10);//99 is discarded coz _1 was not used

}