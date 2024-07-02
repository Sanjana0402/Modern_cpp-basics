#include<iostream>
#include"Engine.h"
Engine::Engine(std::string id,int horsePower,float torque,Type type):m_id{id},m_horsePower{horsePower},m_torque{torque},engineType{type} 
{

}

Engine::~Engine()
{
    std::cout<<m_id<<" IS DELETED \n";
}
