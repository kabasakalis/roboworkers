
#include "putdown.h"
//SOFA: number_of_seats * uniform[1,5) ms b. CHAIR: weight * uniform[1,5) ms
const std::unordered_map<Product::Type, WorkloadCalculator> PutDown::productType_To_WorkloadCalculator = {
        {Product::Type::CHAIR, [](Product product) {
            return 1 * product.getWorkloadMultiplier()  * getUniform(1, 5);
        }},
        {Product::Type::SOFA,  [](Product product) {
            return 1 * product.getWorkloadMultiplier() * getUniform(1, 5);
        }}
};
