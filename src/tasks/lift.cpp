#include "tasks/lift.h"

//SOFA: 3 * number_of_seats * uniform[1,10) ms b. CHAIR: weight * uniform[1,10) ms
const std::unordered_map<Product::Type, WorkloadCalculator> Lift::productType_To_WorkloadCalculator = {
        {Product::Type::CHAIR, [](Product product) {
            return 1 * product.getWorkloadMultiplier()  * getUniform(1, 10);
        }},
        {Product::Type::SOFA,  [](Product product) {
            return 3 * product.getWorkloadMultiplier() * getUniform(1, 10);
        }}
};
