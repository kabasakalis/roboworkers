/**
 * @file sofa.h
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

#ifndef ROBOWORKERS_SOFA_H
#define ROBOWORKERS_SOFA_H

#include "product.h"

class Sofa : public Product {
public:
    /**
     * @brief Default Constructor
     *
     * @details Initializes the multiplier which contributes to the calculation of workload for every task,
     *          the seats_count_, the product type enum and the name
     */
    Sofa();

    constexpr int getSeats() const;;
private:
    int seats_count_;
};

#endif //ROBOWORKERS_SOFA_H
