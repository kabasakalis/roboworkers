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


    Operation() : product_(Product()),
                  type_(Type::NONE),
                  type_name_(stringify(Type::NONE)),
                  total_workload_processed(0) {};

    Operation(Type type, Product product) :
            product_(product), type_(type) {

        switch (type) {
            //LIFT->MOVE->PUT_DOWN->MOVE
            case Type::INBOUND :
                type_name_ = stringify(Type::INBOUND);
                tasks_.emplace_back(std::shared_ptr<Task>(new Lift(id, product_)));
                tasks_.emplace_back(std::unique_ptr<Task>(new Move(id, product_)));
                tasks_.emplace_back(std::unique_ptr<Task>(new PutDown(id, product_)));
                tasks_.emplace_back(std::unique_ptr<Task>(new Move(id, product_)));
                break;
                //MOVE-LIFT-MOVE-PACKAGE-MOVE-PUT_DOWN-MOVE
            case Type::DELIVER:
                type_name_ = stringify(Type::DELIVER);
                tasks_.emplace_back(std::shared_ptr<Task>(new Move(id, product_)));
                tasks_.emplace_back(std::unique_ptr<Task>(new Lift(id, product_)));
                tasks_.emplace_back(std::unique_ptr<Task>(new Move(id, product_)));
                tasks_.emplace_back(std::unique_ptr<Task>(new Package(id, product_)));
                tasks_.emplace_back(std::unique_ptr<Task>(new Move(id, product_)));
                tasks_.emplace_back(std::unique_ptr<Task>(new PutDown(id, product_)));
                tasks_.emplace_back(std::unique_ptr<Task>(new Move(id, product_)));
                break;
            case Type::NONE:
                break;
            default:
                throw std::runtime_error("Unknown operation type.");
        }
        total_workload_processed = calculate_total_workload();
    }

    void process() {
        set_start_time();
        for (auto &task : tasks_) task->execute();
        set_finish_time();
        log_operation(id, type_name_, product_.get_name(), total_workload_processed, creation_time, start_time,
                      finish_time);
    };

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

    int calculate_total_workload() {
        std::vector<int> temp(tasks_.size());
        std::transform(tasks_.begin(), tasks_.end(), temp.begin(),
                       [this](std::shared_ptr<Task> task) { return task->get_workload(); });
        return std::accumulate(temp.begin(), temp.end(), 0);
    }


};

#endif //ROBOWORKERS_OPERATION_H
