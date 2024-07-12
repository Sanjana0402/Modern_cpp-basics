#include "Functionalities.h"


int main() {

    engine_ptr engines{};
    container data{};
    CreateObjects(data);

    std::cout << AverageCCValue(data) << "\n";

    auto f1 =  [] (const engine_ptr& e) { return e->type() == EngineType::HYBRID; };
    //std::cout << ReturnMatchingInstance(data, f1) << "\n";
    container c = ReturnMatchingInstance(data, f1).value();
    for(engine_ptr e : c) {
        std::cout << *e << "\n";
    }

    auto f2 =  [] (const engine_ptr& e) { return e->horsePower() > 20; };
    std::cout << AtleastOneMatchingInstance(data, f2) << "\n";

    // std::future<float> avg =  std::async(&AverageCCValue,std::ref( data));
    // float res1 = avg.get();
    // std::cout << "The average is : " << res1 << "\n";

    // std::future<std::optional<container>> matching_instance = std::async(&ReturnMatchingInstance,std::ref(data), f1);
    // std::optional<container> res2 = matching_instance.get();
    
    // if(res2.has_value()) {
    //     for(const engine_ptr e : res2.value())
    //     std::cout << "Matching instance : " << *e << "\n";
    // }

    // std::future<bool> atleast_one_instance = std::async(&AtleastOneMatchingInstance,std::ref(data), f2);
    // bool res3 = atleast_one_instance.get();
    // std::cout << "Atleast one instance : " << res3 << "\n";



}