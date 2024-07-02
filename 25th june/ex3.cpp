#include<iostream>
#include<functional>


using Predicate = std::function<bool(int32_t)>; 

void Adaptor(Predicate fn, int32_t* arr, int size){

    /*
        for every index "i" in the range of size of arr,
        call fn by passing arr[i] 
    */
    for(int32_t i = 0;i<size;i++)
    {
        if(fn(arr[i])){
            std::cout << arr[i] << "\n";
        }
    }
}

int main(){
    auto fn = [](int32_t number) { return number % 2 == 0; };
    int32_t arr[3] = {11,12,13};
    Adaptor(fn,arr,3);
}