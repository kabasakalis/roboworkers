//
// Created by spiros on 10/18/18.
//

#include <backoffice.h>
#include <stdatomic.h>
#include <warehouse.h>
#include "roboworker.h"


boost::condition_variable available_requests_event;

// Implementation with blocking queue
//void RoboWorker::work() {

//    boost::mutex serve_requests_mutex_;
//    boost::mutex::scoped_lock lock(serve_requests_mutex_);
//    while (pending_requests() ) {
//        if (!requestBlockingQueue_.empty()) {
//            Request current_request = requestBlockingQueue_.pop_front();
//            current_request.get_operation().process();
//            Backoffice::completed_operations_count++;
//            served_requests.emplace_back(current_request);
//            std::cout << "RUNNING LOOP" << std::endl;
//            available_requests_event.notify_all();
//        }
//      if (Backoffice::completed_operations_count < total_requests_count_ ) available_requests_event.wait(lock);
//    }
//
//    std::cout << "FINISHED WORK " << " Thread: " << boost::this_thread::get_id() << " Ops served: " << served_requests.size() << std::endl;
//    lock.unlock();
//}


void RoboWorker::work() {
    while (pending_requests()) {
        boost::mutex serve_requests_mutex_;
        boost::mutex::scoped_lock lock(serve_requests_mutex_);
        bool found(false);
        Request request;
        if (!reqs_.empty()) {
            found = true;
            request = reqs_.front();
            reqs_.pop_front();
            std::cout << "TOOK ONE" << std::endl;
            Backoffice::completed_operations_count++;
            std::cout << "Completed Operations : " << Backoffice::completed_operations_count.load() << std::endl;
            available_requests_event.notify_all();
        }
        if (Backoffice::completed_operations_count < total_requests_count_) available_requests_event.wait(lock);
        lock.unlock();
        if (found) {
            request.get_operation().process();
            served_requests.emplace_back(request);
        }
    }

    std::cout << "FINISHED WORK " << " Thread: " << boost::this_thread::get_id() << " Ops served: "
              << served_requests.size() << std::endl;

}


bool RoboWorker::pending_requests() {
    return Backoffice::completed_operations_count < total_requests_count_;
}
