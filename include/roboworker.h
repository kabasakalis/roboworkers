/**
 * @file roboworker.h
 *
 * @brief Roboworker class
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

#ifndef ROBOWORKERS_ROBOWORKER_H
#define ROBOWORKERS_ROBOWORKER_H

#include "request.h"

class RoboWorker {

public:
    /**
     * @brief Constructor
     *
     * @details Constructs a roboworker with a reference to the backoffice requests queue,
     *          the number of total requests, and a counter id.
     *
     * @param backoffice_requests  the requests queue which the roboworker consume
     * @param total_requests_count  the total number of requests for all batches
     * @param worker_id             an integer as a simple tag for the roboworker
     */
    RoboWorker(std::deque<Request>& backoffice_requests, int total_requests_count, int worker_id)
            : backoffice_requests_(backoffice_requests),
              total_requests_count_(total_requests_count),
              name("RoboWorker_" + std::to_string(worker_id)) {}

    static boost::mutex serve_requests_mutex_;
    static boost::condition_variable available_requests_event;

    /**
     * @brief work Consume requests queue until all requests are served
     *
     * @details Concurrently accesses the requests queue to grab and serve a request.
     *          A lock and a conditional variable are used to synchronize with other
     *          robworkers and the backoffice which pushes requests in batches.
     */
    void work();

    std::string name;
private:
    std::deque<Request> served_requests;
    std::deque<Request>& backoffice_requests_;
    const int total_requests_count_;

    /**
     * @brief  pending_requests  Are there any requests not assigned to a roboworker?
     *
     * @return  predicate indicating whether all requests have been assigned to roboworkers or not
     */
    bool pending_requests();
};

#endif //ROBOWORKERS_ROBOWORKER_H
