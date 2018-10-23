
#ifndef ROBOWORKERS_MOVE_H
#define ROBOWORKERS_MOVE_H


#include <product.h>
#include <task.h>
#include <unordered_map>

class Move : public Task {
public:
    Move(const std::string operationId, Product &product) :
            Task(operationId,
                 product,
                 productType_To_WorkloadCalculator.at(product.getType())(product), "MOVE") {};
private:
    const static std::unordered_map<Product::Type, WorkloadCalculator> productType_To_WorkloadCalculator;
};

#endif //ROBOWORKERS_MOVE_H
