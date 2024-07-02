#include<iostream>
#include<functional>

int main(){
    auto fn = [](int32_t num,int32_t fac){return num * fac;};

    // while binding lambda function donot use & symbol for function use
    auto partially_fn = std::bind(fn,100,std::placeholders::_1);

    partially_fn(20);//fn(100,20);

    partially_fn(20,1,2,3,4,5,6);//fn(100,20) after this the other inputs are discarded thia happens with lambda functions also..........no extra parameters are passed
}