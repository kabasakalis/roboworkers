/**
 * @file operation.cpp
 *
 * @brief  Operation, definition
 *
 * @version 1.0
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

#include "operations/operation.h"

Operation::Operation() : product_(Product()),
                         type_(Type::NONE),
                         type_name_(stringify(Type::NONE)),
                         total_workload_processed(0) {}

Operation::Operation(Operation::Type type, Product product) :
        product_(std::move(product)), type_(type) {
    switch (type) {
        //LIFT->MOVE->PUT_DOWN->MOVE
        case Type::INBOUND :
            type_name_ = stringify(Type::INBOUND);
            tasks_.emplace_back(std::shared_ptr<Task>(new Lift(id, product_)));
            tasks_.emplace_back(std::shared_ptr<Task>(new Move(id, product_)));
            tasks_.emplace_back(std::shared_ptr<Task>(new PutDown(id, product_)));
            tasks_.emplace_back(std::shared_ptr<Task>(new Move(id, product_)));
            break;
            //MOVE-LIFT-MOVE-PACKAGE-MOVE-PUT_DOWN-MOVE
        case Type::DELIVER:
            type_name_ = stringify(Type::DELIVER);
            tasks_.emplace_back(std::shared_ptr<Task>(new Move(id, product_)));
            tasks_.emplace_back(std::shared_ptr<Task>(new Lift(id, product_)));
            tasks_.emplace_back(std::shared_ptr<Task>(new Move(id, product_)));
            tasks_.emplace_back(std::shared_ptr<Task>(new Package(id, product_)));
            tasks_.emplace_back(std::shared_ptr<Task>(new Move(id, product_)));
            tasks_.emplace_back(std::shared_ptr<Task>(new PutDown(id, product_)));
            tasks_.emplace_back(std::shared_ptr<Task>(new Move(id, product_)));
            break;
        case Type::NONE:
            break;
        default:
            throw std::runtime_error("Unknown operation type.");
    }
    total_workload_processed = calculate_total_workload();
}

void Operation::process() {
    set_start_time();
    for (auto &task : tasks_) task->execute();
    set_finish_time();
    log_operation(id, type_name_,
                  product_.get_name(),
                  total_workload_processed,
                  creation_time,
                  start_time,
                  finish_time);
}

int Operation::calculate_total_workload() {
    std::vector<int> temp(tasks_.size());
    std::transform(tasks_.begin(), tasks_.end(), temp.begin(),
                   [this](std::shared_ptr<Task> task) { return task->get_workload(); });
    return std::accumulate(temp.begin(), temp.end(), 0);
}
