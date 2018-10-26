/**
 * @file move.h
 *
 * @brief Move class
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

#ifndef ROBOWORKERS_MOVE_H
#define ROBOWORKERS_MOVE_H

#include <products/product.h>
#include <tasks/task.h>
#include <unordered_map>

class Move : public Task {
public:
    /**
     * @brief Constructor
     *
     * @param operationId  the operation id that this move instance belongs to
     * @param product      the product handled by the move
     *
     */
    Move(const std::string& operationId, Product& product);;
private:
    /**
     * Maps every product type to the function that calculates the workload for the move task.
     *
     * @details SOFA: 10 * number_of_seats * uniform[1,100) ms b. CHAIR: weight * uniform[1,100) ms
     *
     */
    const static std::unordered_map<Product::Type, WorkloadCalculator> product_type_to_workload_calculator;
};

#endif //ROBOWORKERS_MOVE_H
