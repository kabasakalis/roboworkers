
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
            workload_(0) {}


    Task(std::string operationId,
          Product &product,
         int workload) :
            operationId_(operationId),
            product_(product),
            workload_(workload) {}

    virtual void execute() {
        set_start_time();
        usleep(static_cast<useconds_t >(workload_) * 1000);
        set_finish_time();
        logTask(operationId_, id, start_time, finish_time, workload_);
    };


protected:
    std::string operationId_;
    Product product_;
    int workload_;
};


#endif //ROBOWORKERS_TASK_H
