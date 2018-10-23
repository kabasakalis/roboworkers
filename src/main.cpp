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

#include "date/date.h"
#include "date/tz.h"
#include "date/tz_private.h"
#include "date/ptz.h"

int main(int argc, char **argv) {
    using namespace std::placeholders;
    srand(time(NULL));




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
//    Task& package2 = package;
//    package2.execute();
//    move.execute();
//    lift.execute();
//    putDown.execute();
//    package.execute();
//    std::cout << chair.getId() << std::endl;
//    std::cout << chair.getName() << std::endl;



    Sofa sofa;
    Sofa sofa2;
//    Package package("OpID_400", sofa);
//    Task &packageRef = package;
//
//    Sofa sofa2;
//    Package package2("OpID_401", sofa2);
//    Task &package2Ref = package2;


//    std::unique_ptr<Task> a(new Package("OpID_401", sofa));
//
//
//    std::vector<std::unique_ptr<Task>> tasks;
//    tasks.emplace_back(std::move(a));
//    tasks.front()->execute();
//
//
//    std::vector<std::unique_ptr<Task>> tasks2(32);
//    std::unique_ptr<Task> b(new Package("OpID_401", sofa));
//    tasks2.emplace_back(std::move(b));
//    tasks2.back()->execute();
//    std::vector<std::unique_ptr<int>> v(10);









    log_current_date_time();

    std::string filename = argc > 1 ? argv[1] : "../data.txt";
    Backoffice backoffice(filename);
    Warehouse warehouse(backoffice);
    backoffice.receive_batched_requests();
    warehouse.wait_for_workers_to_finish();
    std::cout << "ALL FINISHED in" << std::endl;

    return 0;
}
