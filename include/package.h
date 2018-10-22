
#ifndef ROBOWORKERS_PACKAGE_H
#define ROBOWORKERS_PACKAGE_H

#include <product.h>
#include <task.h>
#include <unordered_map>
#include "packager.h"

class Package : public Task {
public:

    Package(const std::string &operationId, Product &product) :
            Task(operationId,
                 product,
                 productType_To_WorkloadCalculator.at(product.getType())(product)) {};

    void execute() override {

        while (!done) {
            boost::mutex::scoped_lock lock(package_mutex_);
            if (!Packager::getInstance().is_busy) {
                Packager::getInstance().is_busy = true;
                set_start_time();
                Packager::getInstance().package(workload_);
                set_finish_time();
                Packager::getInstance().is_busy = false;
                done = true;
                packager_busy.notify_all();
            }
            if (!done) packager_busy.wait(lock);
            lock.unlock();
        }
        logTask(operationId_, id, start_time, finish_time, workload_);
        std::cout << "OVERRIDEN EXETUTION" << std::endl;
    };


private:
    const static std::unordered_map<Product::Type, WorkloadCalculator> productType_To_WorkloadCalculator;
    boost::mutex package_mutex_;
    boost::condition_variable packager_busy;
    bool done{false};
};

#endif //ROBOWORKERS_PACKAGE_H
