/**
 * @file package.cpp
 *
 * @brief Package class, definition
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

#include "tasks/package.h"

/**
 * Constructor
 *
 * @param operationId  the operation id that this package instance belongs to
 * @param product      the product handled by the package
 *
 */
Package::Package(const std::string& operationId, Product& product) :
        Task(operationId,
             product,
             product_type_to_workload_calculator.at(product.get_type())(product), "PACKAGE") {}

/**
 * Since packaging is executed by the single instance of Packager, the
 * execute method of package task delegates the execution to the Packager.
 * Roboworkers work in different threads, so access is synchronized with a lock and a conditional variable.
 */
void Package::execute() {
    boost::mutex::scoped_lock lock(package_mutex_);
    Packager::getInstance().available.wait(lock, []() { return !Packager::getInstance().is_busy; });
    set_start_time();
    Packager::getInstance().package(workload_);
    set_finish_time();
    Packager::getInstance().available.notify_one();
    lock.unlock();
    log_task(name_, operationId_, id, product_.get_name(), workload_, creation_time, start_time, finish_time);
}

/**
 * Maps every product type to the function that calculates the workload for the package task.
 *
 * @details SOFA: number_of_seats * uniform[20,30) ms b. CHAIR: uniform[20,30) ms
 *
 */
const std::unordered_map<Product::Type, WorkloadCalculator> Package::product_type_to_workload_calculator = {
        {Product::Type::CHAIR, [](Product product) { return 1 * getUniform(20, 30); }},
        {Product::Type::SOFA,  [](Product product) { return 1 * product.getWorkloadMultiplier() * getUniform(20, 30); }}
};
