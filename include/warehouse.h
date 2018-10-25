#ifndef WAREHOUSE_H
#define WAREHOUSE_H

#include <vector>
#include "request.h"
#include "backoffice.h"

#include <boost/thread/thread.hpp>
#include "roboworker.h"

/**
 * @brief The Warehouse class models the Warehouse
 *
 *      *** COMPLETE CODE AT WILL ***
 */
class Warehouse {
public:
    Warehouse(Backoffice &backoffice);

    /**
     * @brief onNewRequests This method is called when new requests arrive from
     * the back-office.
     * @param new_requests The list of new requests
     */
    void onNewRequests(std::vector<Request> &new_requests);

    /**
     * @brief wait Waits until all the requests are handled.
     */
    void wait_for_workers_to_finish();

private:
    Backoffice &backoffice_;
    std::vector<RoboWorker> workers_;
    std::vector<boost::thread> worker_threads_;

    std::vector<RoboWorker> initialize_workers();

    std::vector<boost::thread> initialize_threads();
};

#endif  // WAREHOUSE_H
