/*
     parallel process data with multiple threads
*/

#include <thread>
#include <list>
#include <iostream>
#include <functional>

using ThreadContainer = std::list<std::thread>;
using DataContainer = std::list<int32_t>;
using wrapper = std::function<void(int32_t)>;

void MapThreads( ThreadContainer& threads,const DataContainer& data , wrapper fn){
    auto itr = data.begin();
    for(int32_t n : data){
        threads.emplace_back(fn, n );
    }
}

void JoinThreads( ThreadContainer& threads){
    for(std::thread& th : threads ){
        if(th.joinable()){
            th.join();
        }
    }
}

int main(){
    ThreadContainer threads{};
    DataContainer data{10 , 20 , 30, 40};

    auto f1 = [](int32_t number){std::cout << number * number<<"\n";};

    MapThreads(threads,data,f1);

    JoinThreads(threads);

}