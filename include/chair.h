#ifndef ROBOWORKERS_CHAIR_H
#define ROBOWORKERS_CHAIR_H

#include "product.h"
#include "product_type.h"

class Chair : public Product {
public:
    Chair() : weight_(getUniform(1, 5)) {
        type = Product::Type::CHAIR;
        name = stringify(Product::Type::CHAIR);
    };
private:
    int weight_;
};

#endif //ROBOWORKERS_CHAIR_H
