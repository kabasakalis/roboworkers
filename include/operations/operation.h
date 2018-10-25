/**
 * @file operation.h
 *
 * @brief  Operation
 *
 * @version 1.0
 *
 * @defgroup  operations The operations
 *
 * @ingroup operations
 *
 * @author Spiros Kabasakalis
 * Contact: kabasakalis@gmail.com
 *
 * @copyright 2018 Spiros Kabasakalis
 * This code is licensed under MIT license (see LICENSE for details)
 *
 */

#ifndef ROBOWORKERS_OPERATION_H
#define ROBOWORKERS_OPERATION_H

#include <utilities/utilities.h>
#include <products/product.h>
#include <utilities/timestampable.h>
#include <deque>
#include <tasks/lift.h>
#include <tasks/move.h>
#include <tasks/putdown.h>
#include <tasks/package.h>
#include <numeric>

class Operation : public Identifiable, Timestampable {
public:
    enum Type {
        NONE, INBOUND, DELIVER
    };

    /**
     * Default Constructor
     */
    Operation();

    /**
     * Constructor
     *
     * Using a container of smart pointers to store tasks,
     * so that  polymorphism can be used when iterating over them
     * and calling Task::execute. The overriden and specialized execute
     * method will be called for every subclass of Task. For example,
     * the Package task has a specialized execute method that delegates
     * to singleton's Packager::package method.
     *
     *
     * @param type  the operation type enum
     * @param product the product processed by the operation
     */
    Operation(Type type, Product product);

    /**
     * Process the operation, calling execute in every task sequentially.
     */
    void process();

    std::string get_type_name() {
        return type_name_;
    };

    std::string get_product_name() {
        return product_.get_name();
    };

private:
    Product product_;
    int type_;
    std::string type_name_;
    std::vector<std::shared_ptr<Task>> tasks_;
    int total_workload_processed;

    /**
     * Calculate the sum of workloads for all tasks.
     */
    int calculate_total_workload();
};

#endif //ROBOWORKERS_OPERATION_H
