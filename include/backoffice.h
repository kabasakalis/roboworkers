#ifndef BACKOFFICE_H
#define BACKOFFICE_H

#include <string>
#include <functional>
#include <vector>

#include "request.h"
#include "request_blocking_queue.h"


class Backoffice {
public:
    Backoffice(std::string filename);
    std::deque<Request>& get_request_queue() ;
    void receive_batched_requests();
    std::vector<std::string> lines_;
    const int workers_count;
    const int total_requests_count;
    static std::atomic_int processed_requests_count;
private:
    std::deque<Request> requests_;
    int read_workers_count_from_file(std::string filename);
    std::vector<std::string> read_requests_from_file(std::string filename);
    int calculate_total_requests();
    std::vector<std::string> splitStr(std::string str, std::string delimiter);
};

#endif  // BACKOFFICE_H
