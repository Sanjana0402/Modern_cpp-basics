/*

use case)   calculate for 10 numbers
10 std::thread object to compute square of number of each

use case 2)
5 operations are to be performed. all are idenpendent(order of execution is not important). execute all 5 parallely

a) onr std:: thread for each opeartion
b) one async thread for each operation
c) mic of std::thread std::sync


use case3 )
[producer-consumerproblem]
f1(producer)--->data will be generated
f2(consumer) ----> procession data only  after is generated


example : sensor detects collison and deployment of airbags!

program to call emergency ()

*/

#include <iostream>
#include <condition_variable>
#include <thread>
#include <mutex>
int32_t value{0};
std::condition_variable cv;
std::mutex mt;

bool m_inputReceived{false};
void Producer()
{

    // bool m_inputReceived {false};

    while (m_inputReceived)
    {
        std::cin >> value;
        if (value > 5)
        {
            m_inputReceived = true;
        }
    }
    // send a signal

    std::lock_guard<std::mutex> lk{mt};
    cv.notify_one(); // means send a signal!
}

void Consumer()
{
    // waiting for signal
    std::unique_lock<std::mutex> ul(mt);

    cv.wait(ul, []()
            { return m_inputReceived; });
    std::cout << "value is squared: " << value * value << "\n";
}

int main()
{ // it is also a thread
    // this value cannot be executed until producer gives a signal
    // Main WILL launch producer and consumer
    std::thread t1{&Producer};
    std::thread t2{&Consumer};
    std::cout << "Main continous chillig! ask for 15 crore to fire employes advice\n";
    std::cout << "main can do anything\n";

    t1.join();
    t2.join();
    // will launch consumer
    std::cout << "that's all.bye bye\n";
}