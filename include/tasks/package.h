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
    /**
     * @brief Constructor
     *
     * @param operationId  the operation id that this package instance belongs to
     * @param product      the product handled by the package
     *
     */
    Package(const std::string& operationId, Product& product);

    /**
     * @brief execute Execute the packaging task, delegated to the Packager singleton.
     *
     * @details Since packaging is executed by the single instance of Packager, the
     *          execute method of package task overrides the Task::execute method and
     *          delegates the execution to the Packager.
     *          Roboworkers work in different threads, so access is synchronized with
     *          a lock and a conditional variable.
     */
    void execute() override;

private:
    /**
     * Maps every product type to the function that calculates the workload for the package task.
     *
     * @details SOFA: number_of_seats * uniform[20,30) ms b. CHAIR: uniform[20,30) ms
     *
     */
    const static std::unordered_map<Product::Type, WorkloadCalculator> product_type_to_workload_calculator;
    boost::mutex package_mutex_;
};

#endif //ROBOWORKERS_PACKAGE_H
