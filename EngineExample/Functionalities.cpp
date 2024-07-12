#include "Functionalities.h"

void CreateObjects(container& engines)
{ 
    //std::shared_ptr<Engine> e1   { new Engine("e1",EngineType::ALTERNATE_FUEL,2.3f, 5.6f, 90)}; //This will give a mismatch so use       make_shared
    //std::shared_ptr<Engine> e1 { std::make_shared<Engine>("e1",EngineType::ALTERNATE_FUEL,2.3f, 5.6f, 90) }

    engines.emplace_back(new Engine("e1",EngineType::ALTERNATE_FUEL,2.3f, 5.6f, 90));

    //std::shared_ptr<Engine> e2   { new Engine("e2",EngineType::HYBRID,3.3f, 1.1f, 10)};
    engines.emplace_back(new Engine("e2",EngineType::HYBRID,3.3f, 1.1f, 10));

    //std::shared_ptr<Engine> e3   { new Engine("e3",EngineType::ICE,9.2f, 5.6f, 40)};
    engines.emplace_back(new Engine("e3",EngineType::ICE,9.2f, 5.6f, 40));

    //std::shared_ptr<Engine> e4   { new Engine("e4",EngineType::ALTERNATE_FUEL,2.3f, 5.6f, 70)};
    engines.emplace_back(new Engine("e4",EngineType::ALTERNATE_FUEL,2.3f, 5.6f, 70));

    //std::shared_ptr<Engine> e5   { new Engine("e5",EngineType::ICE,2.3f, 1.9f, 90)};
    engines.emplace_back(new Engine("e5",EngineType::ICE,2.3f, 1.9f, 90));

}

std::optional<container> ReturnMatchingInstance(const container &engines, const Predicate &fn)
{
    /*
        has 2 input --> container & predicate
        for container--> it can have data or not
        for predicate --> a valid function
        so the pblm would rise from conatiner only

        so take result ---> it can have some result or not
        the corner cases arise from result and container 
    */
    bool m_input {false}; //flag to check if input is empty
    if(engines.empty()) {
        std::cerr << "Empty container\n";
        m_input = true; //set it true
    }

    container result {};
    /*
        for each engine_ptr in engines, check if predicate is applicable on the pointer if yes store in the result
    */

    for(const engine_ptr& ptr : engines) {
        if(fn(ptr)) {
            result.emplace_back(ptr);
        }
    }

    // if input is not empty but result is empty
    if(!m_input && result.empty()) {
        return std::nullopt;
    }

    // 
    else if(!m_input) {
        return result;
    }

    // 
    else {
    return std::nullopt;
    }
}

bool AtleastOneMatchingInstance(const container &engines, const Predicate &fn)
{
    bool m_input {false};

    if(engines.empty()) {
        std::cerr << "Empty container\n";
        m_input = true;
        return 0;
    }

    for(const engine_ptr& ptr : engines) {
        if(fn(ptr)) {
            return true;
        }
    }

    return false;
}

float AverageCCValue(container& engines) {
    bool m_input {false};

    if(engines.empty()) {
        std::cerr << "Empty container\n";
        return 0;
    }

    float total {0.0f};

    for(const engine_ptr& pt : engines ) {
        total += pt->cc();
    }

    return total/engines.size();
}


// void CreateThreads(ThreadContainer& threads) {

// }