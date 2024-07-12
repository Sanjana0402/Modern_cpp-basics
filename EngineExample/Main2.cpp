#include "Functionalities.h"
#include <future>

int main() {

    container engines{};

    CreateObjects(engines);

    std::future<std::optional<container>> res1 = std::async(
        &ReturnMatchingInstance, std::ref(engines), [] (const engine_ptr& ptr) { return ptr->torque() > 3; }
    );

    std::future<float> res2 = std::async(&AverageCCValue, std::ref(engines));

    std::future<bool> res3 = std::async(&AtleastOneMatchingInstance, std::ref(engines), [] (const engine_ptr& ptr) { return ptr->torque()>0 ;} );

    bool flag = res2.get();
    std::cout << " at least one found : " << std::boolalpha << flag << "\n";

    float ans = res3.get();
    std::cout <<" avg : " << ans << "\n";

    std::optional<container> objects = res1.get();
    if(objects.has_value()) {
        container pointers = objects.value();
        std::cout << "All pointers with objects satisfying condition: " << "\n";
        for( const engine_ptr e :  pointers) {
            std::cout << *e << "\n";
        }
    }


}