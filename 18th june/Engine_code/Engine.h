#ifndef ENGINE_H
#define ENGINE_H
#include<iostream>
#include"Type.h"

class Engine
{
private:
    std::string m_id{""};
    int m_horsePower{0};
    float m_torque{0.0f};
    Type engineType{Type::DISEL};

public:
    Engine(std::string id,int horsePower,float torque,Type type);
    

    Engine(const Engine&)=delete;//copy construuctor

    Engine& operator=(const Engine&)=delete;//copy assignment operator

    Engine(Engine&&)=delete;//move constructor

    Engine&& operator=(Engine&&)=delete;//move assignment operator

    ~Engine();

    std::string id() const { return m_id; }
    void setId(const std::string &id) { m_id = id; }

    int horsePower() const { return m_horsePower; }
    void setHorsePower(int horsePower) { m_horsePower = horsePower; }

    float torque() const { return m_torque; }
    void setTorque(float torque) { m_torque = torque; }


    

};


#endif // ENGINE_H
