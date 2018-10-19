#ifndef ROBOWORKERS_LIFT_H
#define ROBOWORKERS_LIFT_H

#include <product.h>
#include <task.h>
#include <sofa.h>
#include <chair.h>

class Lift : public Task {
public:
    Lift(const std::string operationId, const Product &product) :
            Task(operationId,
                 product,
                 productType_To_WorkloadCalculator.at(product.getType())(product)) {};

private:
    const static std::unordered_map<Product::Type, WorkloadCalculator> productType_To_WorkloadCalculator;

};

#endif //ROBOWORKERS_LIFT_H
