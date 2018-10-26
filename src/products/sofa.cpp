/**
 * @file sofa.cpp
 *
 * @brief Sofa product
 *
 * @version 1.0
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

#include "products/sofa.h"

Sofa::Sofa() : Product(Product::Type::SOFA, stringify(Product::Type::SOFA)), seats_count_(getUniform(2, 5)) {
    workloadMultiplier_ = seats_count_;
}

constexpr int Sofa::getSeats() const { return seats_count_; }
