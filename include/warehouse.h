#ifndef WAREHOUSE_H
#define WAREHOUSE_H

#include <vector>
#include "request.h"
#include "request_blocking_queue.h"
#include "roboworker.h"
#include "backoffice.h"

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
    bool pending_requests();
    Backoffice&  get_backoffice();

    static std::atomic_int completed_operations_count;

private:
    std::vector<RoboWorker> workers_;
    std::vector<boost::thread> worker_threads_;
    RequestBlockingQueue backoffice_requests_;
    Backoffice& backoffice_;
};

#endif  // WAREHOUSE_H
