//
// Created by spiros on 10/18/18.
//

#include <backoffice.h>
#include "roboworker.h"

void RoboWorker::work() {

    //work for as long as there are pending unserved requests.
//    while (pending_requests()) {
        while (true) {

            if ( !(pending_requests())) break;
       Request current_request= requestBlockingQueue_.pop_front();
        current_request.get_operation().process();
        Backoffice::completed_operations_count += 1;
        served_requests.emplace_back(current_request);
        std::cout << "RUNNING LOOP" <<  std::endl;
    }

    std::cout << "FINISHED WORK" << "Thread " << boost::this_thread::get_id()  <<  std::endl;
}

bool RoboWorker::pending_requests() {

    std::cout << "Completed Operations : " <<  Backoffice::completed_operations_count<< std::endl;
    return Backoffice::completed_operations_count < total_requests_count_;
}
