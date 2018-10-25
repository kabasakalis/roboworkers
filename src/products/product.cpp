/**
 * @file product.cpp
 *
 * @brief Base class for products, definition
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

#include "products/product.h"

Product::Type Product::get_type() const { return type_; }

std::string Product::get_name() const { return name_; }

int Product::getWorkloadMultiplier() const { return workloadMultiplier_; }

Product::Product() : type_(Type::NONE), name_(stringify(Product::Type::NONE)), workloadMultiplier_{1} {}

Product::Product(Product::Type productType, std::string name) :
        type_(productType),
        name_(std::move(name)),
        workloadMultiplier_(1) {}


