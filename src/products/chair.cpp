/**
 * @file chair.cpp
 *
 * @brief Chair product
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

#include "products/chair.h"

constexpr int Chair::getWeight() const { return weight_; }

Chair::Chair() : Product(Product::Type::CHAIR, stringify(Product::Type::CHAIR)),
                 weight_(getUniform(1, 5)) { workloadMultiplier_ = weight_; }
