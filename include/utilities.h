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

/**
 * @brief logTask Logs a task following the required format
 */
inline void logTask(std::string operation_id, std::string task_id,
                    std::chrono::system_clock::time_point start_time,
                    std::chrono::system_clock::time_point finish_time,
                    int workload) {
  std::cout << "#- " << operation_id << " " << task_id << " "
            << timePointToLong(start_time) << " "
            << timePointToLong(finish_time) << " " << workload << std::endl;
}

/**
 * @brief logOperation Logs an operation following the required format
 */
inline void logOperation(std::string operation_id,
                         std::chrono::system_clock::time_point creation_time,
                         std::chrono::system_clock::time_point start_time,
                         std::chrono::system_clock::time_point finish_time) {
  std::cout << "## " << operation_id << " " << timePointToLong(creation_time)
            << " " << timePointToLong(start_time) << " "
            << timePointToLong(finish_time) << std::endl;
}

#endif  // UTILITIES_H
