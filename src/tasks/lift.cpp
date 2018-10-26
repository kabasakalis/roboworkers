/**
 * @file lift.cpp
 *
 * @brief Lift class, definition
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

#include "tasks/lift.h"


Lift::Lift(const std::string& operationId, Product& product) :
        Task(operationId,
             product,
             product_type_to_workload_calculator.at(product.get_type())(product), "LIFT") {}

const std::unordered_map<Product::Type, WorkloadCalculator> Lift::product_type_to_workload_calculator = {
        {Product::Type::CHAIR, [](Product product) { return 1 * product.getWorkloadMultiplier() * getUniform(1, 10); }},
        {Product::Type::SOFA,  [](Product product) { return 3 * product.getWorkloadMultiplier() * getUniform(1, 10); }}
};

