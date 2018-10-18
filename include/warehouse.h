#ifndef WAREHOUSE_H
#define WAREHOUSE_H

#include <vector>
#include "request.h"

/**
 * @brief The Warehouse class models the Warehouse
 *
 *      *** COMPLETE CODE AT WILL ***
 */
class Warehouse {
 public:
  Warehouse(int workers_count);

  /**
   * @brief wait Waits until all the requests are handled.
   */
  void wait();

  /**
   * @brief onNewRequests This method is called when new requests arrive from
   * the back-office.
   * @param new_requests The list of new requests
   */
  void onNewRequests(std::vector<Request> &new_requests);

 private:
    std::deque<boost::thread> worker_threads;
};

#endif  // WAREHOUSE_H
