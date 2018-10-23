#ifndef ROBOWORKERS_CHAIR_H
#define ROBOWORKERS_CHAIR_H

#include "product.h"
#include "product_type.h"

class Chair : public Product {
public:
    Chair() : Product(Product::Type::CHAIR, stringify(Product::Type::CHAIR)),
              weight_(getUniform(1, 5))  {

        workloadMultiplier_ = weight_;
    };

    constexpr int getWeight() const { return weight_; };
private:
    int weight_;
};

#endif //ROBOWORKERS_CHAIR_H
