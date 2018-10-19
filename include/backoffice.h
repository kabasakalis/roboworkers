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
    void start(std::function<void(std::vector<Request> &)> callback);
    int get_workers_count() const { return workers_count_; }
     RequestBlockingQueue &get_request_queue() ;
    void receive_batched_requests();
    std::vector<std::string> lines_;
    const int total_requests_count;
    static std::atomic_int completed_operations_count;
    RequestBlockingQueue requestBlockingQueue_;
private:
    int workers_count_;
    int read_workers_count_from_file(std::string filename);
    std::vector<std::string> read_requests_from_file(std::string filename);
    int calculate_total_requests();
    std::vector<std::string> splitStr(std::string str, std::string delimiter);
};

#endif  // BACKOFFICE_H
