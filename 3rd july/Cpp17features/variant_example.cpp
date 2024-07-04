#include <iostream>
#include<vector>
#include<variant>

//variants : are categorical types which allows "either" "or" principle of coding
int main(){
    int32_t n1{100};
    std::string s1 {"Anju"};

    std::variant<int32_t, std::string> vr;

    vr = n1; //n1 is assigned   to the variant
    std::cout<<"variant is working\n";
    vr = s1;
    vr = 41.56f;
}

//memeory is allocated at run time not at compile time

/*
At one time only one index will be active like 
if 0 index then print n1 and if 1 index then print s1
   vr = n1                          vr=s1

   vr = n1
   int32_t         std::String           index varibale
  [ 10                 xxxxx                     0      ]      //24 byte



   vr = s1
   int32_t         std::String           index varibale
  [ 10                 xxxxx                     1     ]      //24 byte


  bad variant access - if tried to access invalid location   gets and exception

*/