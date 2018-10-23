#include <iostream>
#include "backoffice.h"
#include "warehouse.h"

int main(int argc, char **argv) {
    using namespace std::placeholders;
    srand(time(NULL));

    log_current_date_time();
    std::string filename = argc > 1 ? argv[1] : "../data.txt";
    Backoffice backoffice(filename);
    Warehouse warehouse(backoffice);
    backoffice.receive_batched_requests();
    warehouse.wait_for_workers_to_finish();
//    std::cout << backoffice.total_requests_count << " requests have been served"
//              << " by " << backoffice.workers_count << " Roboworkers."
//              << std::endl;

    log_current_date_time();

    return 0;
}
