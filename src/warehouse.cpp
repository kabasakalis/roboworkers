/**
 * @file warehouse.cpp
 *
 * @brief Warehouse class, definition
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

#include <iostream>
#include <thread>
#include "warehouse.h"
#include <roboworker.h>
#include <boost/thread.hpp>

Warehouse::Warehouse(Backoffice &backoffice) :
        backoffice_(backoffice),
        workers_(initialize_workers()),
        worker_threads_(initialize_threads()) {}

void Warehouse::wait_for_workers_to_finish() {
    for (auto &worker_thread : worker_threads_) worker_thread.join();
    log_shutdown(backoffice_.total_requests_count, backoffice_.workers_count);
}

std::vector<RoboWorker> Warehouse::initialize_workers() {
    std::vector<RoboWorker> workers;
    for (int i = 0; i < backoffice_.workers_count; ++i) {
        RoboWorker worker(backoffice_.get_request_queue(), backoffice_.total_requests_count, i + 1);
        workers.push_back(worker);
    }
    return std::move(workers);
}

std::vector<boost::thread> Warehouse::initialize_threads() {
    std::vector<boost::thread> worker_threads;
    for (int i = 0; i < backoffice_.workers_count; ++i) {
        worker_threads.emplace_back(boost::thread(&RoboWorker::work, &workers_[i]));
    }
    return std::move(worker_threads);
}

