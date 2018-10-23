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
#include "date/date.h"
#include "date/tz.h"
#include "date/tz_private.h"
#include "date/ptz.h"
//#include "operation.h"

using namespace date;
using namespace std::chrono;

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

inline time_of_day<nanoseconds> utc_format(std::chrono::system_clock::time_point timepoint)  {
    auto daypoint = floor < days > (timepoint);
    return make_time(timepoint - daypoint);
}

inline void log_current_date_time() {
    std::string Months[] = {"January", "February", "March", "April", "May", "June", "July", "August", "September",
                            "October", "November", "December"};
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
    std::cout << "The current  time is  " << h << ":" << m << ":" << s << " UTC\n";
}


/**
 * @brief logTask Logs a task following the required format
 */
inline void logTask(std::string operation_id, std::string task_id,
                    std::chrono::system_clock::time_point start_time,
                    std::chrono::system_clock::time_point finish_time,
                    int workload) {
    std::cout << "#- " << boost::this_thread::get_id() << " | " << operation_id << " " << task_id << " "
              << utc_format(start_time) << " "
              << utc_format(finish_time) << " " << workload << std::endl;
}

/**
 * @brief logOperation Logs an operation following the required format
 */
inline void logOperation(std::string operation_id,
                         std::chrono::system_clock::time_point creation_time,
                         std::chrono::system_clock::time_point start_time,
                         std::chrono::system_clock::time_point finish_time) {
    std::cout << "## OPERATION ## |  ID: " << operation_id <<  " | "
              << " TYPE: " << utc_format(creation_time) << " | "
            << " CREATED AT: " << utc_format(creation_time) << " | "
              << "START TIME: " << utc_format(start_time) << " | "
              << "FINISH TIME: " << utc_format(finish_time) << " | " << std::endl;
}


//inline void logOperation(const Operation& operation){
//    std::cout << "## OPERATION ## |  ID: " << operation.id <<  " | "
//              << " TYPE: " << utc_format(operation.get_create_time()) << " | "
//            << " CREATED AT: " << utc_format(operation.get_create_time() << " | "
//              << "START TIME: " << utc_format(operation.get_start_time()) << " | "
//              << "FINISH TIME: " << utc_format(operation.get_finish_time()) << " | " << std::endl;
//}



#endif  // UTILITIES_H
