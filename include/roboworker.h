
#ifndef ROBOWORKERS_ROBOWORKER_H
#define ROBOWORKERS_ROBOWORKER_H


#include "request_blocking_queue.h"

class RoboWorker {

public:
    RoboWorker(RequestBlockingQueue& requestBlockingQueue_, int total_requests_count, std::deque<Request>& reqs)
            : requestBlockingQueue_(requestBlockingQueue_), total_requests_count_(total_requests_count), reqs_(reqs){}
    void work();

private:
    std::deque<Request> served_requests;
    RequestBlockingQueue& requestBlockingQueue_;
    std::deque<Request>& reqs_;
    const int total_requests_count_;
    bool  pending_requests();
};


#endif //ROBOWORKERS_ROBOWORKER_H
