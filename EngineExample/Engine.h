#ifndef ENGINE_H
#define ENGINE_H

#include <iostream>

enum class EngineType {
    HYBRID,
    ICE,
    ALTERNATE_FUEL
};

class Engine
{
private:
    std::string m_id {""};
    EngineType m_type { EngineType ::ICE };
    float m_cc {0.0f};
    float m_torque{0.0f};
    int m_horsePower {0};

public:
    Engine() = default;
    ~Engine() = default;
    Engine(const Engine&) = delete;
    Engine(Engine&&) = delete;
    Engine& operator = (Engine&) = delete;
    Engine& operator = (Engine&&) = delete;

    Engine(std::string id, EngineType type, float cc, float torque, int horsePower);

    std::string id() const { return m_id; }

    EngineType type() const { return m_type; }

    float cc() const { return m_cc; }

    float torque() const { return m_torque; }

    int horsePower() const { return m_horsePower; }

    friend std::ostream &operator<<(std::ostream &os, const Engine &rhs) {
        os << "m_id: " << rhs.m_id
           << " m_type: " << (int) rhs.m_type
           << " m_cc: " << rhs.m_cc
           << " m_torque: " << rhs.m_torque
           << " m_horsePower: " << rhs.m_horsePower;
        return os;
    }
};




#endif // ENGINE_H
