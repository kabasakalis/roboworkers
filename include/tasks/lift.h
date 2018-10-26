/**
 * @file lift.h
 *
 * @brief Lift class
 *
 * @version 1.0
 *
 * @ingroup tasks
 *
 * @author Spiros Kabasakalis
 * Contact: kabasakalis@gmail.com
 *
 * @copyright 2018 Spiros Kabasakalis
 * This code is licensed under MIT license (see LICENSE for details)
 *
 */

#ifndef ROBOWORKERS_LIFT_H
#define ROBOWORKERS_LIFT_H

#include <products/product.h>
#include <tasks/task.h>
#include <products/sofa.h>
#include <products/chair.h>

class Lift : public Task {
public:

    /**
     * @brief Constructor
     *
     * @param operationId  the operation id that this lift instance belongs to
     * @param product      the product handled by the lift
     */
    Lift(const std::string& operationId, Product& product);

private:
    /**
     * @brief Maps every product type to the function that calculates the workload for the lift task.
     *
     * @details  SOFA: 3 * number_of_seats * uniform[1,10) ms b. CHAIR: weight * uniform[1,10) ms
     *
     */
    const static std::unordered_map<Product::Type, WorkloadCalculator> product_type_to_workload_calculator;

};

#endif //ROBOWORKERS_LIFT_H
