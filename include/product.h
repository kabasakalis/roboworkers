#ifndef ROBOWORKERS_PRODUCT_H
#define ROBOWORKERS_PRODUCT_H


#include <string>

#include "identifiable.h"

class Product : public Identifiable {
public:
    enum Type {
        NONE, SOFA, CHAIR
    };

    Product(Product::Type productType, const std::string &name) :
            type_(productType),
            name_(name),
            workloadMultiplier_(0) {};

   Product():type_(Type::NONE), name_(stringify(Product::Type::NONE)), workloadMultiplier_{0} {};

    virtual std::string getName() const;
    virtual Type getType() const;
    virtual int getWorkloadMultiplier() const { return workloadMultiplier_; };
protected:
    Product::Type type_;
    std::string name_;
    int workloadMultiplier_;
};


#endif //ROBOWORKERS_PRODUCT_H
