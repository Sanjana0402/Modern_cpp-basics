
#include <iostream>
#include <optional>  //cpp 17
//factorial takes 1 int16_t by value and optionally return a
// sizet (sometimes , not always
//factorial may or may not return a value)

std::optional<size_t> Factorial(int16_t val) {

    if(val<0){
       return std::nullopt; // a symbolic data value to indicate "Null"
    }
    
   else if(val == 0 || val ==1){
        return 1;
    }

    else {
        size_t total {1};
        for(size_t i =2; i<= val ;i++){
            total +=i;
        }

        return total;
    }
}

int main(){

    

if ( std::optional<size_t> result = Factorial(-5); result.has_value())
{

    std::cout<<"Factorial value : "<<result.value();
}

else {
    std::cerr<<"Factorial did not return a value\n";
}


}

