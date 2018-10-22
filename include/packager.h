
#ifndef ROBOWORKERS_PACKAGER_H
#define ROBOWORKERS_PACKAGER_H

#include "product.h"
#include "task.h"
#include "utilities.h"

class Packager {
public:
    static Packager &getInstance() {
        static Packager instance;
        return instance;
    }

private:
    Packager() {}

public:
    Packager(Packager const &) = delete;

    void operator=(Packager const &)  = delete;

   std::atomic_bool is_busy{false};

    void package(int workload) {
        std::cout << "Packaging " << " Thread: " << boost::this_thread::get_id() << "  " << std::endl;
//        is_busy = true;
        usleep(static_cast<useconds_t >(workload) * 1000);
//        is_busy = false;
        std::cout << "Finished Packaging " << " Thread: " << boost::this_thread::get_id() << "  " << std::endl;
    }
};

#endif //ROBOWORKERS_PACKAGER_H
