#include "Employee.h"
#include "BusinessOwner.h"
#include <variant>
#include<iostream>

using vrType = std:: variant<BusinessOwner, Employee>;
void Display(const vrType& vr)    {

    std::visit( [] (auto&& val) {std::cout<<val << "\n";} , vr);
}




int main(){

 vrType vr;
 Employee e1 {"Anju", 96945.0f};
 BusinessOwner b1 {"Anju", 84658.0f};
 vr = e1;

 Display(vr);

 vr = b1; // changed vs to businessowner

 Display(vr);                 
}