/**
 * @file packager.h
 *
 * @brief Packager singleton class
 *
 * @version 1.0
 *
 * @ingroup tasks
 *
 * @author Spiros Kabasakalis
 * Contact: kabasakalis@gmail.com
 *
 * @copyright 2018 Spiros Kabasakalis
 * This code is licensed under MIT license (see LICENSE for details)
 *
 */

#ifndef ROBOWORKERS_PACKAGER_H
#define ROBOWORKERS_PACKAGER_H

#include "utilities/utilities.h"

class Packager {
public:
    static Packager& getInstance() {
        static Packager instance;
        return instance;
    }

private:
    Packager() {}

public:
    Packager(Packager const&) = delete;

    void operator=(Packager const&)  = delete;

    /**
     * @brief package package the provided workload
     *
     * @details Executes the package task for all roboworkers.
     *          When packager is busy, roboworkers wait until they
     *          are notified.
     *
     * @param workload  the workload passed from package task
     */
    void package(int workload);

    bool is_busy{false};
    boost::condition_variable available;
};

#endif //ROBOWORKERS_PACKAGER_H
