/**
 * @file move.cpp
 *
 * @brief Move class, definition
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

#include "tasks/move.h"


Move::Move(const std::string &operationId, Product &product) :
        Task(operationId,
             product,
             product_type_to_workload_calculator.at(product.get_type())(product), "MOVE") {}


const std::unordered_map<Product::Type, WorkloadCalculator> Move::product_type_to_workload_calculator = {
        {Product::Type::CHAIR, [](Product product) { return 1 * product.getWorkloadMultiplier() * getUniform(1, 100); }},
        {Product::Type::SOFA,  [](Product product) { return 10 * product.getWorkloadMultiplier() * getUniform(1, 100); }}
};