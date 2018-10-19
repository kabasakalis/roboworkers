
#ifndef ROBOWORKERS_ROBOWORKER_H
#define ROBOWORKERS_ROBOWORKER_H


#include "request_blocking_queue.h"

class RoboWorker {

public:
    RoboWorker(RequestBlockingQueue& requestBlockingQueue_, int total_requests_count)
            : requestBlockingQueue_(requestBlockingQueue_), total_requests_count_(total_requests_count){}
    void work();

private:
    std::deque<Request> served_requests;
    RequestBlockingQueue& requestBlockingQueue_;
    const int total_requests_count_;
    bool  pending_requests();
};


#endif //ROBOWORKERS_ROBOWORKER_H
