/**
 * @file task.cpp
 *
 * @brief Base class for tasks, definition
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

#include "tasks/task.h"

Task::Task() :
        operationId_("NOT_AVAILABLE"),
        product_(Product()),
        workload_(0),
        name_("TASK") {}

Task::Task(std::string operationId, Product &product, int workload, std::string name) :
        operationId_(std::move(operationId)),
        product_(product),
        workload_(workload),
        name_(std::move(name)) {}


void Task::execute() {
    set_start_time();
    usleep(static_cast<useconds_t >(workload_) * 1000);
    set_finish_time();
    log_task(name_, operationId_, id, product_.get_name(), workload_, creation_time, start_time, finish_time);
}

int Task::get_workload() { return workload_; }
