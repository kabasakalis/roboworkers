#ifndef ROBOWORKERS_LIFT_H
#define ROBOWORKERS_LIFT_H

#include <products/product.h>
#include <tasks/task.h>
#include <products/sofa.h>
#include <products/chair.h>

class Lift : public Task {
public:
    Lift(const std::string operationId, Product &product) :
            Task(operationId,
                 product,
                 productType_To_WorkloadCalculator.at(product.get_type())(product), "LIFT") {};

private:
    const static std::unordered_map<Product::Type, WorkloadCalculator> productType_To_WorkloadCalculator;

};

#endif //ROBOWORKERS_LIFT_H
