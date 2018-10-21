
#ifndef ROBOWORKERS_PACKAGER_H
#define ROBOWORKERS_PACKAGER_H


#include "product.h"
#include "task.h"

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

    void package(Task task) {
// TODO: Add locks
        task.execute();
    }
};

#endif //ROBOWORKERS_PACKAGER_H
