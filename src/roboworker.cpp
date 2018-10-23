
#include <backoffice.h>
#include <stdatomic.h>
#include <warehouse.h>
#include "roboworker.h"

boost::mutex RoboWorker::serve_requests_mutex_;
boost::condition_variable RoboWorker::available_requests_event;

void RoboWorker::work() {
    while (pending_requests()) {
        boost::mutex::scoped_lock lock(RoboWorker::serve_requests_mutex_);
        bool found(false);
        Request request;
        if (!backoffice_requests_.empty()) {
            found = true;
            request = std::move(backoffice_requests_.front());
            backoffice_requests_.pop_front();
            std::cout << "TOOK ONE" << std::endl;
            Backoffice::processed_requests_count++;
            std::cout << "Processed requests : " << Backoffice::processed_requests_count.load() << std::endl;
            available_requests_event.notify_all();
        }
        if (Backoffice::processed_requests_count < total_requests_count_) available_requests_event.wait(lock);
        lock.unlock();
        if (found) {
            request.get_operation().process();
            served_requests.emplace_back(std::move(request));
        }
    }
    log_shutdown();
}

void RoboWorker::log_shutdown() {

    std::cout << "---------------------------------------------------------------"
              << "---------------------------------------------------------------" << std::endl;
    std::cout << name << " HAS FINISHED WORK AND IS SHUTTING DOWN. " << " | "
              << "THREAD ID: " << boost::this_thread::get_id() << " | "
              << "NUMBER OF REQUESTS SERVED: " << served_requests.size()
              << std::endl;
    std::cout << "---------------------------------------------------------------"
              << "---------------------------------------------------------------" << std::endl;
}

bool RoboWorker::pending_requests() {
    return Backoffice::processed_requests_count < total_requests_count_;
}
