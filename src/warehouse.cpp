#include "warehouse.h"

#include <iostream>
#include <roboworker.h>
#include <thread>
#include <boost/thread.hpp>



Warehouse::Warehouse(Backoffice &backoffice) :
        backoffice_(backoffice) {
    // TODO: Implement me
    std::cout << "Workers count: " << backoffice.get_workers_count() << std::endl;
}


void Warehouse::wait() {
    // TODO: Implement me

}

void Warehouse::onNewRequests(std::vector<Request> &new_requests) {
    // TODO: Implement me

    //         >>> This function should *never* block <<<


//  for (Request &r : new_requests) {
//      r.get_operation().process();
////    std::cout << r.operation_ << "," << r.product_ << " ";
//  }
    std::cout << std::endl;

}

void Warehouse::serve_requests() {
// join worker threads
    for (int i = 0; i < backoffice_.get_workers_count(); ++i) {
        RoboWorker roboworker(*this);
        workers_.push_back(roboworker);
    }

    for (int i = 0; i < backoffice_.get_workers_count(); ++i) {
        worker_threads_[i] = boost::thread(&RoboWorker::work, &workers_[i]);
    }
    for (auto &worker_thread : worker_threads_) worker_thread.join();
}

std::atomic_int Warehouse::completed_operations_count = 0;

bool Warehouse::pending_requests() {
    return completed_operations_count < backoffice_.get_total_requests_count();
}

Backoffice &Warehouse::get_backoffice() {
    return backoffice_;
}

