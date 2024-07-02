/*

  Terminologies:

  1)CPU : Set of hardware responsible for executing tasks in a computing system

  2)System : Any computing device

  3)Processor : A hardware chip (made of silicon) designed for executing
  insructions given by the user of the computer
  
  4)Socket : Point on the motherboard where processor is connected

  5)Core : Every processor is divided internally into units called as "Cores"
  Each core can execute instructions from one "process" at any given time

  6)processor : hardware chip designed for executing instructions


*/

#include<iostream>
#include<vector>
#include<functional>
#include<thread>


using Operations=std::function<void(int number)>;

void Adaptor(Operations fn,const std::vector<int>&data)
{
    for(int val:data)
    {
        std::this_thread::sleep_for(std::chrono::seconds(1));
        fn(val);
    }
}

void Square(int number)
{
    std::cout<<"\n"<<number*number<<"\n";
}

int main()

{

    auto cube_fn=[](int number){std::cout<<"\n"<<number*number*number<<"\n";};
    std::thread t1{&Adaptor,&Square,std::vector<int>{1,2,3,4,5}};
    std::thread t2{&Adaptor,cube_fn,std::vector<int>{1,2,3,4,5}};

    t1.join();
    t2.join();



}

