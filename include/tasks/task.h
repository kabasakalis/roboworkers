/**
 * @file task.h
 *
 * @brief Base class for tasks
 *
 * @version 1.0
 *
 * @defgroup  tasks The tasks
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

#ifndef ROBOWORKERS_TASK_H
#define ROBOWORKERS_TASK_H

#include <unordered_map>
#include <map>
#include "utilities/identifiable.h"
#include "utilities/timestampable.h"
#include "products/product.h"
#include <unistd.h>
#include <functional>

using WorkloadCalculator = std::function<int(Product)>;

class Task : public Identifiable, public Timestampable {
public:
    /**
     * @brief Default constructor
     */
    Task();

    /**
     *
     * @brief Constructor
     *
     * @param operationId the id of the operation that this task belongs to
     * @param product     the product handled by the task
     * @param workload    the workload of this task assoicated with the specific product
     * @param name        identifier
     */
    Task(std::string operationId,
         Product& product,
         int workload, std::string name);
    /**
     *  @brief Executes the task, sets start and finish timestamps and logs.
     */
    virtual void execute();

    int get_workload();

protected:
    std::string operationId_;
    std::string name_;
    Product product_;
    int workload_;
};

#endif //ROBOWORKERS_TASK_H
