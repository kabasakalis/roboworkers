
#ifndef ROBOWORKERS_SOFA_H
#define ROBOWORKERS_SOFA_H

#include "product.h"

class sofa : public Product {
public:
    sofa():seatsCount_(getUniform(2,5)){
       type = Product::Type::SOFA;
       name = stringify(Product::Type::SOFA);
    };
private:
    int seatsCount_;
};

#endif //ROBOWORKERS_SOFA_H
