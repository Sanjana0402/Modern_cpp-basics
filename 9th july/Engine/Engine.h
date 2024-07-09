#ifndef ENGINE_H
#define ENGINE_H
#include "Type.h"
#include<iostream>

class Engine
{
private:
    /* data */
    std::string m_id{0};
    int m_horsepower{0};
    float m_engine_cc{0.0f};
    float m_torque{0.0f};
    Type m_type{Type::ALTERNATE_FUEL};
public:
    Engine(/* args */) = default;

    ~Engine() = default;

    Engine(const Engine& other) = delete;
    Engine& operator = (const Engine& other) = delete;
    Engine(Engine&& other) = delete;
    Engine& operator = (Engine&& other) = delete;

    Engine(std::string id, int power, float cc,float torque ,Type type );

    int horsepower() const { return m_horsepower; }
    void setHorsepower(int horsepower) { m_horsepower = horsepower; }

    float torque() const { return m_torque; }
    void setTorque(float torque) { m_torque = torque; }

    std::string id() const { return m_id; }
    void setId(const std::string &id) { m_id = id; }

    float engineCc() const { return m_engine_cc; }
    void setEngineCc(float engine_cc) { m_engine_cc = engine_cc; }

};

#endif // ENGINE_H
