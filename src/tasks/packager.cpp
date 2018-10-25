/**
 * @file packager.cpp
 *
 * @brief Packager singleton class, definition
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

#include "tasks/packager.h"
/**
 * Executes the package task for all roboworkers.
 * When packager is busy, roboworkers wait until they
 * are notified.
 *
 * @param workload  the workload passed from package task
 */
void Packager::package(int workload) {
    is_busy = true;
    usleep(static_cast<useconds_t>(workload) * 1000);
    is_busy = false;
    available.notify_all();
}
