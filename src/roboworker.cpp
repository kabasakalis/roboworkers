//
// Created by spiros on 10/18/18.
//

#include <backoffice.h>
#include <stdatomic.h>
#include <warehouse.h>
#include "roboworker.h"

void RoboWorker::work() {

//      boost::mutex serve_requests_mutex_;
//    boost::mutex::scoped_lock lock(serve_requests_mutex_);
//    while (pending_requests() && !requestBlockingQueue_.empty()) {
//          Request current_request = requestBlockingQueue_.pop_front();
//          current_request.get_operation().process();
//          Backoffice::completed_operations_count ++ ;
//          served_requests.emplace_back(current_request);
//          std::cout << "RUNNING LOOP" << std::endl;
//    }
//
//    std::cout << "FINISHED WORK " << "Thread " << boost::this_thread::get_id() << std::endl;
//    lock.unlock();




//    boost::mutex serve_requests_mutex_;
//    boost::mutex::scoped_lock lock(serve_requests_mutex_);
    do {

        Request current_request = requestBlockingQueue_.pop_front();
        current_request.get_operation().process();
//          Backoffice::completed_operations_count.fetch_add(1);
        Backoffice::completed_operations_count++;
        served_requests.emplace_back(current_request);
        std::cout << "RUNNING LOOP" << std::endl;
    } while (pending_requests() && !requestBlockingQueue_.empty());
    std::cout << "FINISHED WORK " << "Thread " << boost::this_thread::get_id() << std::endl;
//    lock.unlock();

//    requestBlockingQueue_.close();
//    Warehouse::all_requests_have_been_served_event_.wait(lock);

//    Warehouse::all_requests_have_been_served_event_.wait(lock);
//    requestBlockingQueue_.close();

//    while (true) {
//
//        if (!(pending_requests())) {
//            requestBlockingQueue_.close();
//            break;
//        }
//
//        Request current_request = requestBlockingQueue_.pop_front();
//        current_request.get_operation().process();
//        Backoffice::completed_operations_count.fetch_add(1);
//        served_requests.emplace_back(current_request);
//        std::cout << "RUNNING LOOP" << std::endl;
//
//    }


}


bool RoboWorker::pending_requests() {
    std::cout << "Completed Operations : " << Backoffice::completed_operations_count.load() << std::endl;
//    return Backoffice::completed_operations_count.load() < total_requests_count_;
    return Backoffice::completed_operations_count < total_requests_count_;
}
