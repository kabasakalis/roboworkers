#include "tasks/package.h"

//SOFA: number_of_seats * uniform[20,30) ms b. CHAIR: uniform[20,30) ms
const std::unordered_map<Product::Type, WorkloadCalculator> Package::productType_To_WorkloadCalculator = {
        {Product::Type::CHAIR, [](Product product) {
            return 1 * getUniform(20, 30);
        }},
        {Product::Type::SOFA,  [](Product product) {
            return 1 * product.getWorkloadMultiplier() * getUniform(20, 30);
        }}
};
