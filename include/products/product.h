/**
 * @file product.h
 *
 * @brief Base class for products
 *
 * @version 1.0
 *
 * @defgroup  products The products
 *
 * @ingroup products
 *
 * @author Spiros Kabasakalis
 * Contact: kabasakalis@gmail.com
 *
 * @copyright 2018 Spiros Kabasakalis
 * This code is licensed under MIT license (see LICENSE for details)
 *
 */

#ifndef ROBOWORKERS_PRODUCT_H
#define ROBOWORKERS_PRODUCT_H

#include <string>
#include "utilities/identifiable.h"

class Product : public Identifiable {
public:
    enum Type {
        NONE, SOFA, CHAIR
    };

/**
 * Constructor
 *
 * @param productType Type enum
 * @param name string inentifier
 */
    Product(Product::Type productType, const std::string &name) :
            type_(productType),
            name_(name),
            workloadMultiplier_(0) {};

/**
 *  Default constructor
 */
    Product() : type_(Type::NONE), name_(stringify(Product::Type::NONE)), workloadMultiplier_{0} {};


    virtual Type get_type() const;

    virtual std::string get_name() const;

    virtual int getWorkloadMultiplier() const;;
protected:
    Product::Type type_;
    std::string name_;
    int workloadMultiplier_;
};


#endif //ROBOWORKERS_PRODUCT_H
