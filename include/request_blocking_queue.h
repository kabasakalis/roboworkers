
#ifndef ROBOWORKERS_REQUEST_BLOCKING_QUEUE_H
#define ROBOWORKERS_REQUEST_BLOCKING_QUEUE_H


#include <deque>
#include <boost/thread/mutex.hpp>
#include <boost/thread/condition_variable.hpp>
#include "request.h"

class RequestBlockingQueue {
private:
    mutable boost::mutex requests_mutex_;
    const size_t requests_count_;
    bool is_closed = false;

    boost::condition_variable request_added_or_closed_event_;

    boost::condition_variable request_removed_event_;
public:


    RequestBlockingQueue(size_t requests_count = 0) : requests_count_(requests_count) {}
    std::deque<Request> requests_;

   int get_size(){ return requests_.size();};
    std::deque<Request>& get_request(){ return requests_;};


    void add_one(const Request &request) {
        boost::mutex::scoped_lock lock(requests_mutex_);
//        while (requests_.size() >= requests_count_) {
//            request_removed_event_.wait(lock);
//        }
        assert (!is_closed);
        requests_.emplace_back(request);

        lock.unlock();

        request_added_or_closed_event_.notify_one();
    }

    bool try_add_one(const Request &request) {
        boost::mutex::scoped_lock lock(requests_mutex_);
        if (requests_.size() >= requests_count_) {
            return false;
        }
        assert (!is_closed);
        requests_.emplace_back(request);
        lock.unlock();

        request_added_or_closed_event_.notify_one();
        return true;
    }

    void close() {
        boost::mutex::scoped_lock lock(requests_mutex_);
//        assert (!is_closed);
        is_closed = true;
        lock.unlock();

        request_added_or_closed_event_.notify_all();
    }

//    bool pop_front(Request &served_request) {
       Request pop_front() {
        boost::mutex::scoped_lock lock(requests_mutex_);
        while (requests_.empty()) {
            if (is_closed) {
//                return (Request) NULL;
                return Request(Product::Type::CHAIR,  Operation::Type::INBOUND);
            }
            request_added_or_closed_event_.wait(lock);
        }

        Request current_request = requests_.front();
        requests_.pop_front();
        request_removed_event_.notify_one();
//        return true;
        return  current_request;
    }

    bool try_pop_front() {
        boost::mutex::scoped_lock lock(requests_mutex_);
        if (requests_.empty()) {
            return false;
        }
        Request &current_request = requests_.front();
        requests_.pop_front();
        request_removed_event_.notify_one();
        return true;
    }

    bool empty() const {
        boost::mutex::scoped_lock lock(requests_mutex_);
        return requests_.empty();
    }

    bool closed() const {
        boost::mutex::scoped_lock lock(requests_mutex_);
        return is_closed;
    }

    size_t get_requests_count() const {
        return requests_count_;
    }

    size_t get_current_count() const {
        boost::mutex::scoped_lock lock(requests_mutex_);
        return requests_.size();
    }

};


#endif //ROBOWORKERS_REQUEST_BLOCKING_QUEUE_H
