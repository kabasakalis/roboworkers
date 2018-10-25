
#ifndef ROBOWORKERS_PUTDOWN_H
#define ROBOWORKERS_PUTDOWN_H

#include <products/product.h>
#include <tasks/task.h>
#include <unordered_map>

class PutDown : public Task {
public:
    PutDown(const std::string operationId,  Product &product) :
            Task(operationId,
                 product,
                 productType_To_WorkloadCalculator.at(product.get_type())(product), "PUT_DOWN") {};
private:
    const static std::unordered_map<Product::Type, WorkloadCalculator> productType_To_WorkloadCalculator;
};

#endif //ROBOWORKERS_PUTDOWN_H
