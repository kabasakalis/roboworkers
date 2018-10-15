#include "warehouse.h"

#include <iostream>

Warehouse::Warehouse(int workers_count) {
  // TODO: Implement me
  std::cout << "Workers count: " << workers_count << std::endl;
}

void Warehouse::wait() {
  // TODO: Implement me
}

void Warehouse::onNewRequests(std::vector<Request> &new_requests) {
  // TODO: Implement me

  //         >>> This function should *never* block <<<


  for (Request &r : new_requests) {
      r.get_operation().process();
//    std::cout << r.operation_ << "," << r.product_ << " ";
  }
  std::cout << std::endl;

}
