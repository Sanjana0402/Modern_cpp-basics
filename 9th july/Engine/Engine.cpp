#include "Engine.h"

Engine::Engine(std::string id, int power, float cc ,float torque, Type type) : m_id{id},m_horsepower{power},m_engine_cc{cc},m_torque{torque}, m_type{type}
{
}