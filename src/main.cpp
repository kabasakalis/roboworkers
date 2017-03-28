#include <iostream>
#include <functional>

#include "utilities.h"
#include "backoffice.h"
#include "warehouse.h"

int main(int argc, char **argv) {
  using namespace std::placeholders;
  srand(time(NULL));

  std::string filename = argc > 1 ? argv[1] : "data.txt";
  Backoffice backoffice(filename);
  Warehouse warehouse(backoffice.workers_count());
  backoffice.start(std::bind(&Warehouse::onNewRequests, &warehouse, _1));

  warehouse.wait();

  return 0;
}
