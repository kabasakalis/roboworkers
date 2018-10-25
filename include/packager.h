
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
    bool is_busy{false};
    boost::condition_variable available;
    void package(int workload) {
        is_busy = true;
        usleep(static_cast<useconds_t>(workload) * 1000);
        is_busy = false;
        available.notify_all();
    }
};

#endif //ROBOWORKERS_PACKAGER_H
