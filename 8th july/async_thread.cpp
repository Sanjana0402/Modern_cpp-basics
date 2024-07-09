/*
     It can be used to execute task pin asynchronous mode
     It is a thread that can also catch a return value so that it could be used
     in CPP to execute value returning functions in a separate thread as well
*/

#include <iostream>
#include <future>// CPP 11 feature

int64_t Magic(int32_t number){
    return number * number;
}

int main(){
    std::future<int64_t> ans = std::async(&Magic,10); //async returns future values... I can track it in future when required

    std::cout << ans.get() << "\n";//get fetches the answer from async thread
    //if thread still executing the main will get blocked at this line till completion of Magic function
}