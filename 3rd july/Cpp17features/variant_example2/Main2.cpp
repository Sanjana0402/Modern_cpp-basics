
/*
keep data on the heap

and use variant for functional polymorphism


*/

#include<iostream>
#include<variant>
#include"Employee.h"
#include"BusinessOwner.h"
/*
A function which either accepts another func as a parameter or
return a functin is called "Higher-order" function
*/
using VrType = std::variant<BusinessOwner*, Employee*>;
 
void Display (const VrType& v){
    std::visit([](auto&& val ){std::cout << *val <<"\n";},  v );
}

//
void ShowPFAmount(const VrType&  v){
    if(std::holds_alternative<Employee*>(v))  
    {
        Employee* e=std::get<1>(v);
        e->CalculateMonthyPF();
    }

    throw std::runtime_error("not valid data for business man\n");

}




void ShowTaxAmount(const VrType& v){
    std::visit([](auto&& val){val->CalculateTaxAmount();}, v);
}
    //
int main(){
 
    VrType v;
 
    v = new BusinessOwner {"Anju", 56786.0f};
    Display(v);
    ShowTaxAmount(v);
    try
    {
        ShowPFAmount(v);
    }
    catch(const std::runtime_error& e)
    {
        std::cerr << e.what() << '\n';
    }
    
 
    v = new Employee{"Anju",45000.0f};
 
    Display(v);
    ShowTaxAmount(v);
}

