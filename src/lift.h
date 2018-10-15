#ifndef ROBOWORKERS_LIFT_H
#define ROBOWORKERS_LIFT_H

#include <product.h>
#include <task.h>

class Lift : public Task {
public:
    const std::map<Product::Type, short> productType_To_multiplier{
            {Product::Type::CHAIR, 1},
            {Product::Type::SOFA,  3}
    };

    Lift(const std::string &operationId, const Product &product) :
            Task(operationId, product, productType_To_multiplier.at(product.getType()), getUniform(1,10)){};

};

#endif //ROBOWORKERS_LIFT_H
