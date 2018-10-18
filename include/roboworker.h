//
// Created by spiros on 10/18/18.
//

#ifndef ROBOWORKERS_ROBOWORKER_H
#define ROBOWORKERS_ROBOWORKER_H


#include "request_blocking_queue.h"

class RoboWorker {


public:
    RoboWorker(RequestBlockingQueue &requestBlockingQueue)
            : requestBlockingQueue_(requestBlockingQueue) {}

    void work() {

        //work for as long as there are pending unserved requests.
        // TODO add condition
        while (true) {
            Request &current_request = requestBlockingQueue_.pop_front();
            current_request.get_operation().process();
            served_requests.emplace_back(current_request);
        }
    }

private:
    RequestBlockingQueue &requestBlockingQueue_;
    std::deque served_requests;
};


#endif //ROBOWORKERS_ROBOWORKER_H
