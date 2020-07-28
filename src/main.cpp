/**
 * @file main.cpp
 *
 * @brief Main
 *
 * @version 1.0
 *
 * @author Spiros Kabasakalis
 * Contact: kabasakalis@gmail.com
 *
 * @copyright 2018 Spiros Kabasakalis
 * This code is licensed under MIT license (see LICENSE for details)
 *
 */

#include <iostream>
#include "backoffice.h"
#include "warehouse.h"

int main(int argc, char **argv) {
    srand(time(NULL));
    // If you are using CLion IDE set the file path as "../data.txt"
    std::string filename = argc > 1 ? argv[1] : "../data.txt";
    Backoffice backoffice(filename);
    Warehouse warehouse(backoffice);
    backoffice.accept_requests();

    warehouse.wait_for_workers_to_finish();

    return 0;
}
