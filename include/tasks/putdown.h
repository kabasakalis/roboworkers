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
    PutDown(const std::string& operationId, Product& product);;
private:
    const static std::unordered_map<Product::Type, WorkloadCalculator> product_type_to_workload_calculator;
};

#endif //ROBOWORKERS_PUTDOWN_H
