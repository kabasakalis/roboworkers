
#ifndef ROBOWORKERS_PACKAGE_H
#define ROBOWORKERS_PACKAGE_H

#include <products/product.h>
#include <tasks/task.h>
#include <unordered_map>
#include "packager.h"

class Package : public Task {
public:

    Package(const std::string &operationId, Product &product) :
            Task(operationId,
                 product,
                 productType_To_WorkloadCalculator.at(product.get_type())(product), "PACKAGE") {};

    void execute() override {
        boost::mutex::scoped_lock lock(package_mutex_);
        Packager::getInstance().available.wait(lock, []() { return !Packager::getInstance().is_busy; });
        set_start_time();
        Packager::getInstance().package(workload_);
        set_finish_time();
        Packager::getInstance().available.notify_one();
        lock.unlock();
        log_task(name_, operationId_, id, product_.get_name(), workload_, creation_time, start_time, finish_time);
    };

private:
    const static std::unordered_map<Product::Type, WorkloadCalculator> productType_To_WorkloadCalculator;
    boost::mutex package_mutex_;
};

#endif //ROBOWORKERS_PACKAGE_H
