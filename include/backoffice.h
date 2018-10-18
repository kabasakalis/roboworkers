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
    int get_total_requests_count() const { return total_requests_count_; }
    RequestBlockingQueue &get_request_queue();
    void receive_batched_requests();
private:
    std::vector<std::string> splitStr(std::string str, std::string delimiter);

    int calculate_total_requests();

    std::vector<std::string> lines_;
     int workers_count_;
    const int total_requests_count_;
    RequestBlockingQueue requestBlockingQueue_;
};

#endif  // BACKOFFICE_H
