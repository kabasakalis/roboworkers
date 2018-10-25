#include <iostream>
#include "backoffice.h"
#include "warehouse.h"

int main(int argc, char **argv) {
    srand(time(NULL));

    std::string filename = argc > 1 ? argv[1] : "../data.txt";
    Backoffice backoffice(filename);
    log_startup(backoffice.workers_count, backoffice.total_requests_count, backoffice.lines_.size());

    Warehouse warehouse(backoffice);
    backoffice.accept_requests();
    warehouse.wait_for_workers_to_finish();

    return 0;
}
