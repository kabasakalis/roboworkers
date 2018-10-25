/**
 * @file chair.h
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

#ifndef ROBOWORKERS_CHAIR_H
#define ROBOWORKERS_CHAIR_H

#include "product.h"

class Chair : public Product {
public:
    /**
     * Default Constructor
     */
    Chair();;

    constexpr int getWeight() const;;
private:
    int weight_;
};

#endif //ROBOWORKERS_CHAIR_H
