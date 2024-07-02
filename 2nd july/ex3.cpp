/*
    amt = 1000

    100 withdraw (10rs each)
    100 deposit  (10rs each)

    after 200 transaction completed , what is the expected final amt
*/

#include <iostream>
#include <thread>
#include <mutex>


int32_t m_amt{1000};
std::mutex mt;

void Deposit(){
    for(int i = 0; i< 100; i++){
        std::this_thread::sleep_for(std::chrono::milliseconds(5));
        mt.lock();
        m_amt += 10;
        mt.unlock();
    }
}

void withDraw(){
    for(int i = 0; i< 100; i++){
        std::this_thread::sleep_for(std::chrono::milliseconds(5));
        mt.lock();
        m_amt -= 10;
        mt.unlock();
    }
}

int main(){

    //synchronous 
    // Deposit();

    // withDraw();

    std::thread t1{withDraw};
    std::thread t2{Deposit};

    t1.join();
    t2.join();

    std::cout << "Final ammount : " << m_amt <<"/n";
}