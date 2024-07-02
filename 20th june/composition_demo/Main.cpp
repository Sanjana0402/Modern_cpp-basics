#include "Functionalities.h"
#include<iostream>
#include"AccountNotFoundException.h"
int main() {
    Container accounts; 

    CreateObjects(accounts);
    DeallocateMemory(accounts);
    CountVISACards(accounts);
    
    /*
        write other parts of client code here
    */
    std::cout<<"\nDisplay Card Details :  ";
    try{
       DisplayCardDetails(accounts,04012002);
    }
    catch(AccountNotFoundException& ex){
        std::cerr << ex.what() << "\n";
    }
     //std::cout<< DisplayCardDetails(accounts,04012002);
  
    std::cout<<"\n";
}