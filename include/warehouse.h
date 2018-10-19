#ifndef WAREHOUSE_H
#define WAREHOUSE_H

#include <vector>
#include "request.h"
#include "request_blocking_queue.h"
#include "backoffice.h"

#include <boost/thread.hpp>
class RoboWorker;

//#include "roboworker.h"

/**
 * @brief The Warehouse class models the Warehouse
 *
 *      *** COMPLETE CODE AT WILL ***
 */
class Warehouse {
public:
//    Warehouse(int get_workers_count, RequestBlockingQueue &backoffice_requests);
    Warehouse(Backoffice& backoffice);

    /**
     * @brief wait Waits until all the requests are handled.
     */
    void wait();

    /**
     * @brief onNewRequests This method is called when new requests arrive from
     * the back-office.
     * @param new_requests The list of new requests
     */
    void onNewRequests(std::vector<Request> &new_requests);

    void serve_requests();

    Backoffice&  get_backoffice();


private:
    std::vector<RoboWorker> workers_;
    std::vector<boost::thread> worker_threads_;
    std::vector<RoboWorker> initialize_workers();
    std::vector<boost::thread> initialize_threads();
    Backoffice& backoffice_;
};

#endif  // WAREHOUSE_H
