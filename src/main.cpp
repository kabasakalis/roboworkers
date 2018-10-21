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
#include "roboworker.h"
#include "operation.h"
#include <boost/timer.hpp>
int main(int argc, char **argv) {
    using namespace std::placeholders;
    srand(time(NULL));



boost::timer t;


//   Sofa sofa;
//    Chair chair;

//    Operation inbound(Operation::Type::INBOUND, sofa);
//    Operation outbound(Operation::Type::DELIVER, chair);
//
//    inbound.process();
//    outbound.process();
//    Move move("OpID_100", sofa);
//    Lift lift("OpID_200", chair);
//    PutDown putDown("OpID_300", chair);
//    Package package("OpID_400", sofa);
//    move.execute();
//    lift.execute();
//    putDown.execute();
//    package.execute();
//    std::cout << chair.getId() << std::endl;
//    std::cout << chair.getName() << std::endl;
//
//    std::cout << sofa.getId() << std::endl;
//    std::cout << sofa.getName() << std::endl;


//     boost::condition_variable lolo;


    std::string filename = argc > 1 ? argv[1] : "../data.txt";
    Backoffice backoffice(filename);
    Warehouse warehouse(backoffice);
    backoffice.receive_batched_requests();
    warehouse.wait_for_workers_to_finish();
    std::cout << "ALL FINISHED in"  << t.elapsed() <<  std::endl;

    return 0;
}
