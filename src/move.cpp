#include "move.h"

//SOFA: 10 * number_of_seats * uniform[1,100) ms b. CHAIR: weight * uniform[1,100) ms
const std::unordered_map<Product::Type, WorkloadCalculator> Move::productType_To_WorkloadCalculator = {
        {Product::Type::CHAIR, [](Product product) {
            return 1 * product.getWorkloadMultiplier()  * getUniform(1, 100);
        }},
        {Product::Type::SOFA,  [](Product product) {
            return 10 * product.getWorkloadMultiplier() * getUniform(1, 100);
        }}
};
