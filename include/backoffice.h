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
    Backoffice(std::string filename);
    std::deque<Request>& get_request_queue() ;
    void accept_requests();
    std::vector<std::string> lines_;
    const int workers_count;
    const int total_requests_count;
    static std::atomic_int assigned_requests_count;
private:
    std::deque<Request> requests_;
    int read_workers_count_from_file(std::string filename);
    std::vector<std::string> read_requests_from_file(std::string filename);
    int calculate_total_requests();
    std::vector<std::string> splitStr(std::string str, std::string delimiter);
};

#endif  // BACKOFFICE_H
