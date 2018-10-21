
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
            request = backoffice_requests_.front();
            backoffice_requests_.pop_front();
            std::cout << "TOOK ONE" << std::endl;
            Backoffice::completed_operations_count++;
            std::cout << "Completed Operations : " << Backoffice::completed_operations_count.load() << std::endl;
            available_requests_event.notify_all();
        }
        if (Backoffice::completed_operations_count < total_requests_count_) available_requests_event.wait(lock);
        lock.unlock();
        if (found) {
            request.get_operation().process();
            served_requests.emplace_back(request);
        }
    }

    std::cout << "FINISHED WORK " << " Thread: " << boost::this_thread::get_id() << " Ops served: "
              << served_requests.size() << std::endl;
}


bool RoboWorker::pending_requests() {
    return Backoffice::completed_operations_count < total_requests_count_;
}
