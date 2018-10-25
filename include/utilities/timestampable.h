/**
 * @file timestampable.h
 *
 * @brief  Timestampable class, subclasses inherit timestamps.
 *
 * @version 1.0
 *
 * @ingroup utilities
 *
 * @author Spiros Kabasakalis
 * Contact: kabasakalis@gmail.com
 *
 * @copyright 2018 Spiros Kabasakalis
 * This code is licensed under MIT license (see LICENSE for details)
 *
 */

#ifndef ROBOWORKERS_TIMESTAMPABLE_H
#define ROBOWORKERS_TIMESTAMPABLE_H

#include "utilities.h"

using Timepoint = std::chrono::system_clock::time_point;

class Timestampable {
public:
    Timestampable() : creation_time(getTimestamp()) {};

    virtual void set_start_time() { start_time = getTimestamp(); };

    virtual void set_finish_time() { finish_time = getTimestamp(); };
protected:
    Timepoint creation_time;
    Timepoint start_time;
    Timepoint finish_time;
};

#endif //ROBOWORKERS_TIMESTAMPABLE_H
