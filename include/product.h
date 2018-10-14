#ifndef ROBOWORKERS_PRODUCT_H
#define ROBOWORKERS_PRODUCT_H


#include <string>

#include "identifiable.h"

class Product : public Identifiable {
public:
    enum class Type { PRODUCT, SOFA, CHAIR };
    Product(): type(Product::Type::PRODUCT), name(stringify(Product::Type::PRODUCT)){};
    virtual std::string getName() const;
    virtual Type getType() const;
protected:
    Type type;
    std::string name;
};


#endif //ROBOWORKERS_PRODUCT_H
