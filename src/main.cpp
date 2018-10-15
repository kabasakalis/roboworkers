#include <iostream>
#include <functional>
#include <product.h>
#include <sofa.h>
#include <chair.h>
#include <move.h>
#include <lift.h>
#include <lift.h>
#include <package.h>
#include <putdown.h>

#include "utilities.h"
#include "backoffice.h"
#include "warehouse.h"
#include "operation.h"

int main(int argc, char **argv) {
    using namespace std::placeholders;
    srand(time(NULL));

    Sofa sofa;
    Chair chair;

//    Move move("OpID_100", sofa);
//    Lift lift("OpID_200", chair);
//    PutDown putDown("OpID_300", chair);
//    Package package("OpID_400", sofa);
//    move.execute();
//    lift.execute();
//    putDown.execute();
//    package.execute();

    Operation inbound(Operation::Type::INBOUND, sofa);
    Operation outbound(Operation::Type::DELIVER, chair);

        inbound.process();
        outbound.process();


//    std::cout << chair.getId() << std::endl;
//    std::cout << chair.getName() << std::endl;
//
//    std::cout << sofa.getId() << std::endl;
//    std::cout << sofa.getName() << std::endl;

    std::string filename = argc > 1 ? argv[1] : "../data.txt";
    Backoffice backoffice(filename);
    Warehouse warehouse(backoffice.workers_count());
    backoffice.start(std::bind(&Warehouse::onNewRequests, &warehouse, _1));

    warehouse.wait();

    return 0;
}
