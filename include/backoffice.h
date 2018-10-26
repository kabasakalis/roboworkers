/**
 * @file backoffice.h
 *
 * @brief Backoffice class
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

#ifndef BACKOFFICE_H
#define BACKOFFICE_H

#include <string>
#include <vector>
#include "request.h"

class Backoffice {
public:
    /**
     * @brief Constructor.
     *
     * @details Ctor initializer initializes the number of roboworkers, the total number of requests
     * and the batches (lines_). The file is opened two times, once to get the request batches and once
     * more to read the total number of roboworkers,  which is not very efficient, but it's more explicit in
     * terms of making clear what variables are initialized. The total number of requests (from all batches)
     * is needed to keep track of remaining unserved requests and to know when to shut down the roboworkers.
     *
     * @param filename filename with the requests
     */
    Backoffice(std::string filename);

    /**
     * @brief accept_requests Processes file with raw text requests as one batch per line
     *
     * @details Backoffice reads the request batches from the file,
     * and translates them to request objects which are immediately added to the
     * requests queue. By this time, roboworkers have already started looking for work,
     * as they have access to a reference of the queue - they do not wait for the batch
     * to complete, they start looking for work as soon as the first request is placed
     * in the queue. This is obviously a single procucer-multiple consumers multithreaded case,
     * so it's synchronized with a lock and conditional variable which puts to sleep roboworkers
     * who find an empty queue. That way, they do not block the queue and give it up for other
     * roboworkers to have a chance at it.
     *
     */
    void accept_requests();

    std::deque<Request>& get_request_queue();

    std::vector<std::string> lines_;
    const int workers_count;
    const int total_requests_count;
    static std::atomic_int assigned_requests_count;
private:
    std::deque<Request> requests_;

    int read_workers_count_from_file(std::string filename);

    std::vector<std::string> read_requests_from_file(std::string filename);

    /**
     * @brief Calculates total number of requests
     *
     * @return the number of total requests, summed up for all batches
     */
    int calculate_total_requests();

    std::vector<std::string> splitStr(std::string str, std::string delimiter);
};

#endif  // BACKOFFICE_H
