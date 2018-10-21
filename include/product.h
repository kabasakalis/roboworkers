#ifndef ROBOWORKERS_PRODUCT_H
#define ROBOWORKERS_PRODUCT_H


#include <string>

#include "identifiable.h"

class Product : public Identifiable {
public:
    enum Type {
        PRODUCT, SOFA, CHAIR
    };

    Product(Product::Type productType, const std::string &name) :
            type_(productType),
            name_(name) {};

    virtual std::string getName() const;
    virtual Type getType() const;
    virtual int getWorkloadMultiplier() const { return workloadMultiplier_; };
protected:
    Product::Type type_;
    std::string name_;
    int workloadMultiplier_;
};


#endif //ROBOWORKERS_PRODUCT_H
