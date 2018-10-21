
#ifndef ROBOWORKERS_PACKAGE_H
#define ROBOWORKERS_PACKAGE_H

#include <product.h>
#include <task.h>
#include <unordered_map>

class Package : public Task {
public:

    Package(const std::string &operationId, const Product &product) :
            Task(operationId,
                 product,
                 productType_To_WorkloadCalculator.at(product.getType())(product)) {};


private:
    const static std::unordered_map<Product::Type, WorkloadCalculator> productType_To_WorkloadCalculator;
};

#endif //ROBOWORKERS_PACKAGE_H
