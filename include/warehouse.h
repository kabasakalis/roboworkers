/**
 * @file warehouse.h
 *
 * @brief Warehouse class
 *
 * @version 1.0
 *
 * @author Spiros Kabasakalis
 * Contact: kabasakalis@gmail.com
 *
 * @copyright 2018 Spiros Kabasakalis
 * This code is licensed under MIT license (see LICENSE for details)
 *
 */

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
 */
class Warehouse {
public:
    /**
     * @brief Constructor
     * @param backoffice  a reference to the backoffice
     */
    Warehouse(Backoffice& backoffice);


    /**
     * @brief wait_for_workers_to_finish Waits until all the requests are handled by the roboworkers.
     *
     */
    void wait_for_workers_to_finish();

private:
    Backoffice& backoffice_;
    std::vector<RoboWorker> workers_;
    std::vector<boost::thread> worker_threads_;

    /**
     * @brief   initialize_workers
     *
     * @details Initializes as many roboworkers as specified in the file
     *          used to initialize the backoffice and stores them in the member
     *          vector variable workers_.
     */
    std::vector<RoboWorker> initialize_workers();

    /**
     * @brief   initialize_threads
     *
     * @details Initializes a thread for every roboworker so that
     *          they can process the operations in parallel.
     */
    std::vector<boost::thread> initialize_threads();
};

#endif  // WAREHOUSE_H
