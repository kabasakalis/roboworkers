
#ifndef ROBOWORKERS_TASK_H
#define ROBOWORKERS_TASK_H

#include <bits/unordered_map.h>
#include <unordered_map>
#include <map>
#include "identifiable.h"
#include "timestampable.h"
#include "product.h"
#include <unistd.h>

class Task : public Identifiable, Timestampable {
public:


    Task(const std::string &operationId, const Product &product, int productTypeMultiplier, int randomMultiplier) :
            operationId_(operationId),
            product_(product) {
        workload_ = productTypeMultiplier * product.getMultiplier() * randomMultiplier;
    };


    virtual void execute() {
        setStarted();
        usleep(static_cast<useconds_t >(workload_) * 1000);
        setFinished();
    };


protected:
    std::string operationId_;
    Product product_;
    int workload_;
};


#endif //ROBOWORKERS_TASK_H
