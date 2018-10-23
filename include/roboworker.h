
#ifndef ROBOWORKERS_ROBOWORKER_H
#define ROBOWORKERS_ROBOWORKER_H

class RoboWorker {

public:
    RoboWorker(std::deque<Request> &backoffice_requests, int total_requests_count, int worker_id)
            : backoffice_requests_(backoffice_requests),
              total_requests_count_(total_requests_count),
              name("RoboWorker_" + std::to_string(worker_id)){}

    static boost::mutex serve_requests_mutex_;
    static boost::condition_variable available_requests_event;
    void work();
    void log_shutdown();
    std::string name;
private:
    std::deque<Request> served_requests;
    std::deque<Request> &backoffice_requests_;
    const int total_requests_count_;
    bool pending_requests();

};

#endif //ROBOWORKERS_ROBOWORKER_H
