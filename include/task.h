
#ifndef ROBOWORKERS_TASK_H
#define ROBOWORKERS_TASK_H

#include <unordered_map>
#include <map>
#include "identifiable.h"
#include "timestampable.h"
#include "product.h"
#include <unistd.h>
#include <functional>

using WorkloadCalculator = std::function<int(Product)>;

class Task : public Identifiable, public Timestampable {
public:

    Task() :
            operationId_("NOT_AVAILABLE"),
            product_(Product()),
            workload_(0),
            name_("TASK") {}

    Task(std::string operationId,
         Product &product,
         int workload,  std::string name) :
            operationId_(std::move(operationId)),
            product_(product),
            workload_(workload),
            name_(std::move(name)) {}

    virtual void execute() {
        set_start_time();
        usleep(static_cast<useconds_t >(workload_) * 1000);
        set_finish_time();
        log();
    };

    int get_workload() { return workload_; }

    /**
 * @brief logOperation Logs an operation following the required format
 */
    virtual void log() {
        std::cout << "# " << name_ << " #" << " | "
                  << "OPERATION ID: " << operationId_ << " | "
                  << "TASK ID: " << id << " | "
                  << " " << product_.getName() << " | "
                  << "WORKLOAD: " << workload_ << "ms" << " | "
                  << "CREATED AT: " << utc_format(creation_time) << " | "
                  << "START TIME: " << utc_format(start_time) << " | "
                  << "FINISH TIME: " << utc_format(finish_time) << " | " << std::endl;
    }

protected:
    std::string operationId_;
    std::string name_;
    Product product_;
    int workload_;
};

#endif //ROBOWORKERS_TASK_H
