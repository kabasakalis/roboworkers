#include "warehouse.h"

#include <iostream>
#include <thread>
#include <roboworker.h>


#include <boost/thread.hpp>

Warehouse::Warehouse(Backoffice& backoffice) :
        backoffice_(backoffice),
        workers_(initialize_workers()),
        worker_threads_(initialize_threads()){
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

    for (auto &worker_thread : worker_threads_) worker_thread.join();
}




Backoffice &Warehouse::get_backoffice() {
    return backoffice_;
}

std::vector<RoboWorker> Warehouse::initialize_workers() {
    for (int i = 0; i < backoffice_.get_workers_count(); ++i) {
        RoboWorker roboworker(backoffice_.get_request_queue(), backoffice_.total_requests_count);
        workers_.push_back(roboworker);
    }
    return workers_;
}


std::vector<boost::thread>  Warehouse::initialize_threads() {
        for (int i = 0; i < backoffice_.get_workers_count(); ++i) {

        worker_threads_[i] = boost::thread(&RoboWorker::work, &workers_[i]);
    }
    return std::move(worker_threads_);
}

