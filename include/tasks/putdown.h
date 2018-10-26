/**
 * @file putdown.h
 *
 * @brief PutDown class
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

#ifndef ROBOWORKERS_PUTDOWN_H
#define ROBOWORKERS_PUTDOWN_H

#include <products/product.h>
#include <tasks/task.h>
#include <unordered_map>

class PutDown : public Task {
public:
    /**
     * @brief Constructor
     *
     * @param operationId  the operation id that this putdown instance belongs to
     * @param product      the product handled by the putdown
     *
     */
    PutDown(const std::string& operationId, Product& product);;
private:
    /**
     * Maps every product type to the function that calculates the workload for the putdown task.
     *
     * @details SOFA: number_of_seats * uniform[1,5) ms b. CHAIR: weight * uniform[1,5) ms
     *
     */
    const static std::unordered_map<Product::Type, WorkloadCalculator> product_type_to_workload_calculator;
};

#endif //ROBOWORKERS_PUTDOWN_H
