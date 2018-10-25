/**
 * @file package.h
 *
 * @brief Package class
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

#ifndef ROBOWORKERS_PACKAGE_H
#define ROBOWORKERS_PACKAGE_H

#include <products/product.h>
#include <tasks/task.h>
#include <unordered_map>
#include "packager.h"

class Package : public Task {
public:

    Package(const std::string& operationId, Product& product);

    void execute() override;;

private:
    const static std::unordered_map<Product::Type, WorkloadCalculator> product_type_to_workload_calculator;
    boost::mutex package_mutex_;
};

#endif //ROBOWORKERS_PACKAGE_H
