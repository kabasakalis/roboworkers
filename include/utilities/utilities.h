#ifndef UTILITIES_H
#define UTILITIES_H

#include <string>
#include <cstdlib>
#include <ctime>
#include <chrono>
#include <iostream>
#include <boost/uuid/uuid.hpp>
#include <boost/uuid/uuid_io.hpp>
#include <boost/uuid/uuid_generators.hpp>
#include <boost/thread.hpp>
#include "date/date.h"

using namespace date;
using namespace std::chrono;
using Timepoint = std::chrono::system_clock::time_point;

/**
 * @brief getUUID Returns a UUID as a string
 */
inline std::string getUUID() {
    boost::uuids::uuid uuid = boost::uuids::random_generator()();
    return boost::uuids::to_string(uuid);
}

/**
 * @brief getUniform Returns a uniformly destributed random integer in [from,to)
 */
inline int getUniform(short from, int to) { return rand() % to + from; }

/**
 * @brief getTimestamp Returns the current timestamp
 */
inline std::chrono::system_clock::time_point getTimestamp() {
    return std::chrono::system_clock::now();
}

/**
 * @brief timePointToLong Returns a long from a time_point
 */
inline long timePointToLong(std::chrono::system_clock::time_point tp) {
    return tp.time_since_epoch().count();
}

inline time_of_day<nanoseconds> utc_format(std::chrono::system_clock::time_point timepoint) {
    auto daypoint = floor < days > (timepoint);
    return make_time(timepoint - daypoint);
}

inline void log_current_date_time() {
    std::string Months[] = {"January", "February", "March", "April", "May", "June",
                            "July", "August", "September", "October", "November", "December"};
    auto now = std::chrono::system_clock::now();
    auto daypoint = floor < days > (now);
    auto tod = make_time(now - daypoint);
    auto ymd = year_month_day(daypoint);
    auto y = int(ymd.year());
    auto m = unsigned(ymd.month());
    auto d = unsigned(ymd.day());
    auto h = tod.hours().count();
    auto min = tod.minutes().count();
    auto s = tod.seconds().count();
    std::cout << "The current date is " << Months[m - 1] << " " << d << ", " << y << ". \n";
    std::cout << "The current time is  " << h << ":" << m << ":" << s << " UTC\n";
}


inline void log_startup(int workers_count, int total_requests_count, unsigned long batches_count) {

    log_current_date_time();
    std::cout << "Roboworkers starting up." << std::endl;
    std::cout << workers_count << " roboworkers will handle "
              << total_requests_count << " requests "
              << "in " << batches_count << " batches. "
              << "Incoming Requests, handling starts now." << std::endl;
}

inline void log_operation(std::string operation_id,
                          std::string name,
                          std::string product_name,
                          int total_workload,
                          Timepoint creation_time,
                          Timepoint start_time,
                          Timepoint finish_time) {
    std::cout << "## OPERATION ## |  ID: " << operation_id << " | "
              << name << " | "
              << " " << product_name << " | "
              << "TOTAL WORKLOAD: " << total_workload << "ms" << " | "
              << " CREATED AT: " <<
              utc_format(creation_time)
              << " | "
              << "START TIME: " <<
              utc_format(start_time)
              << " | "
              << "FINISH TIME: " <<
              utc_format(finish_time)
              << " | " <<
              std::endl;
}

/**
* @brief log_task Logs an operation following the required format
*/
inline void log_task(std::string name,
                     std::string operation_id,
                     std::string id,
                     std::string product_name,
                     int workload,
                     Timepoint creation_time,
                     Timepoint start_time,
                     Timepoint finish_time) {
    std::cout << "# " << name << " #" << " | "
              << "OPERATION ID: " << operation_id << " | "
              << "TASK ID: " << id << " | "
              << " " << product_name << " | "
              << "WORKLOAD: " << workload << "ms" << " | "
              << "CREATED AT: " << utc_format(creation_time) << " | "
              << "START TIME: " << utc_format(start_time) << " | "
              << "FINISH TIME: " << utc_format(finish_time) << " | " << std::endl;
}


/**
* @brief log_task Logs an operation following the required format
*/
inline void log_roboworker_shutdown(
        std::string name,
        boost::thread::id thread_id,
        ulong requests_served_count) {
    std::cout << "---------------------------------------------------------------"
              << "---------------------------------------------------------------" << std::endl;
    std::cout << name
              << " HAS FINISHED WORK AND IS SHUTTING DOWN. " << " | "
              << "THREAD ID: " << thread_id << " | "
              << "NUMBER OF REQUESTS SERVED: " << requests_served_count
              << std::endl;
    std::cout << "---------------------------------------------------------------"
              << "---------------------------------------------------------------" << std::endl;
}


/**
* @brief log_task Logs an operation following the required format
*/
inline void log_backoffice_wait_between_batches(int wait_for) {
    std::cout << "Backoffice waiting for " << wait_for << "ms until the next batch of requests." << std::endl;
}

/**
* @brief log_task Logs an operation following the required format
*/
inline void log_roboworker_request_assignment(std::string name,
                                              std::string operation_id,
                                              std::string operation_type,
                                              std::string product_type) {
    std::cout << "REQUEST ASSIGNMENT: "
              << name << " has just been assigned a request." << " | "
              << "OPERATION ID: " << operation_id << ", "
              << operation_type << ", "
              << product_type << "."
              << std::endl;
}

/**
* @brief log_task Logs an operation following the required format
*/
inline void log_assigned_requests_count(int assigned_requests_count,
                                              int total_requests_count){
    std::cout << "Assigned Requests: " << assigned_requests_count << ", "
              << "Remaining: " << (total_requests_count - assigned_requests_count) << "."
              << std::endl;
}
/**
* @brief log_task Logs an operation following the required format
*/
inline void log_shutdown(int total_requests_count, int workers_count) {

    std::cout << "FINISHED:  All " << total_requests_count << " requests have been served." << std::endl;
    std::cout << "All " << workers_count << " roboworkers have finished work and have been shut down." << std::endl;
    std::cout << "WAREHOUSE SHUTTING DOWN." << std::endl;
    std::cout << "BACKOFFICE SHUTTING DOWN." << std::endl;
    log_current_date_time();
    std::cout << "Goodbye." << std::endl;

}


#endif  // UTILITIES_H
