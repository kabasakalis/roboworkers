
#ifndef ROBOWORKERS_ROBOWORKER_H
#define ROBOWORKERS_ROBOWORKER_H


#include "request_blocking_queue.h"
#include "warehouse.h"
class Warehouse;
class RoboWorker {


public:
    RoboWorker(Warehouse &warehouse)
            : warehouse_(warehouse) {}
    void work() {

        //work for as long as there are pending unserved requests.
        while (warehouse_.pending_requests()) {
            Request &current_request = warehouse_.get_backoffice().get_request_queue().pop_front();
            current_request.get_operation().process();
            Warehouse::completed_operations_count += 1;
            served_requests.emplace_back(current_request);
        }

    }

private:
    std::deque<Request> served_requests;
    Warehouse &warehouse_;
};


#endif //ROBOWORKERS_ROBOWORKER_H
