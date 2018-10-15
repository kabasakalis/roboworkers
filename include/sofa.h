
#ifndef ROBOWORKERS_SOFA_H
#define ROBOWORKERS_SOFA_H

#include "product.h"

class Sofa : public Product {
public:
    Sofa() : Product(Product::Type::SOFA, stringify(Product::Type::SOFA)),
             seatsCount_(getUniform(2, 5)) {
         workloadMultiplier_ = seatsCount_;
    };

    constexpr int getSeats() const { return seatsCount_; };
private:
    int seatsCount_;
};

#endif //ROBOWORKERS_SOFA_H
