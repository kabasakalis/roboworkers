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
    Lift(const std::string& operationId, Product& product);;

private:
    const static std::unordered_map<Product::Type, WorkloadCalculator> product_type_to_workload_calculator;

};

#endif //ROBOWORKERS_LIFT_H
