#include<iostream>

/*

bool definition fn()
//////
main() {
bool flag fn()
if (flag)  {
////}

else  {
/////
flag should be erased at the end of line
//// flag is gone
}
}
*/


bool CheckDivisibilityBy3(int32_t number){
    return number % 3 == 0;

}

 int main(){
int32_t n1{10};
// if flag variable is initialized and then flag is also true
if(bool flag = CheckDivisibilityBy3(n1); flag){

    std::cout << "number isdivisble bye 3 \n";
}

else {
    std::cerr<<"flag is set at :" <<std::boolalpha<<flag<<"number us not divisible\n";
}

//std::cout<<"cannot acess flag now: "<<flag;  

 }