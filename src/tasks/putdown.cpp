/**
 * @file putdown.cpp
 *
 * @brief PutDown class, definition
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

#include "tasks/putdown.h"

/**
 * Constructor
 *
 * @param operationId  the operation id that this putdown instance belongs to
 * @param product      the product handled by the putdown
 *
 */
PutDown::PutDown(const std::string& operationId, Product& product) :
        Task(operationId,
             product,
             product_type_to_workload_calculator.at(product.get_type())(product), "PUT_DOWN") {}

/**
 * Maps every product type to the function that calculates the workload for the putdown task.
 *
 * @details SOFA: number_of_seats * uniform[1,5) ms b. CHAIR: weight * uniform[1,5) ms
 *
 */
const std::unordered_map<Product::Type, WorkloadCalculator> PutDown::product_type_to_workload_calculator = {
        {Product::Type::CHAIR, [](Product product) { return 1 * product.getWorkloadMultiplier() * getUniform(1, 5); }},
        {Product::Type::SOFA,  [](Product product) { return 1 * product.getWorkloadMultiplier() * getUniform(1, 5); }}
};


