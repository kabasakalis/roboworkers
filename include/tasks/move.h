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
    Move(const std::string& operationId, Product& product);;
private:
    const static std::unordered_map<Product::Type, WorkloadCalculator> product_type_to_workload_calculator;
};

#endif //ROBOWORKERS_MOVE_H
