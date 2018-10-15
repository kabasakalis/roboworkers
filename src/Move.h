//
// Created by spiros on 10/14/18.
//

#ifndef ROBOWORKERS_MOVE_H
#define ROBOWORKERS_MOVE_H


#include <product.h>
#include <task.h>

class Move : public Task {
public:
    const std::map<Product::Type, short> productType_To_multiplier{
            {Product::Type::CHAIR, 1},
            {Product::Type::SOFA,  10}
    };

    Move(const std::string &operationId, const Product &product) :
            Task(operationId, product, productType_To_multiplier.at(product.getType()), getUniform(1,100)){};

};


#endif //ROBOWORKERS_MOVE_H
