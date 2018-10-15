#include <iostream>
#include <functional>
#include <product.h>
#include <Sofa.h>
#include <chair.h>

#include "utilities.h"
#include "backoffice.h"
#include "warehouse.h"

int main(int argc, char **argv) {
    using namespace std::placeholders;
    srand(time(NULL));

    Product product;
    Sofa sofa;
    Chair chair;

    std::cout << product.getId() << std::endl;
    std::cout << product.getName() << std::endl;

    std::cout << chair.getId() << std::endl;
    std::cout << chair.getName() << std::endl;

    std::cout << sofa.getId() << std::endl;
    std::cout << sofa.getName() << std::endl;

    std::string filename = argc > 1 ? argv[1] : "../data.txt";
    Backoffice backoffice(filename);
    Warehouse warehouse(backoffice.workers_count());
    backoffice.start(std::bind(&Warehouse::onNewRequests, &warehouse, _1));

    warehouse.wait();

    return 0;
}
