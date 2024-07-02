#ifndef ENGINE_H
#define ENGINE_H

#include<iostream>


class Engine
{
private:
    /* data */
    unsigned int m_id{0};
    int m_horsepower{0};
    float m_torque{0.0f};
public:
    Engine() = default;
    ~Engine() = default;
    Engine(const Engine& other) = delete;

    Engine& operator = (const Engine& other) = delete;
    Engine(Engine&& other) = delete;
    Engine& operator = (Engine&& other) = delete;

    Engine(unsigned int id,int horsepower,float torque);

    unsigned int id() const { return m_id; }
    void setId(unsigned int id) { m_id = id; }

    int horsepower() const { return m_horsepower; }
    void setHorsepower(int horsepower) { m_horsepower = horsepower; }

    float torque() const { return m_torque; }
    void setTorque(float torque) { m_torque = torque; }
};

#endif // ENGINE_H
