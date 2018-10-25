#include <backoffice.h>
#include <warehouse.h>

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
            Backoffice::assigned_requests_count++;
            log_roboworker_request_assignment(name,
                                              request.get_operation().getId(),
                                              request.get_operation().get_type_name(),
                                              request.get_operation().get_product_name());

            log_assigned_requests_count(Backoffice::assigned_requests_count, total_requests_count_);
            available_requests_event.notify_all();
        }
        if (Backoffice::assigned_requests_count < total_requests_count_) available_requests_event.wait(lock);
        lock.unlock();
        if (found) {
            request.get_operation().process();
            served_requests.emplace_back(std::move(request));
        }
    }
    log_roboworker_shutdown(name, boost::this_thread::get_id(), served_requests.size());
}

bool RoboWorker::pending_requests() {
    return Backoffice::assigned_requests_count < total_requests_count_;
}
