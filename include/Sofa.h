
#ifndef ROBOWORKERS_SOFA_H
#define ROBOWORKERS_SOFA_H

#include "product.h"

class Sofa : public Product {
public:
    Sofa():seatsCount_(getUniform(2,5)){
       type = Product::Type::SOFA;
       name = stringify(Product::Type::SOFA);
       workloadMultiplier = seatsCount_;
    };
private:
    int seatsCount_;
};

#endif //ROBOWORKERS_SOFA_H
