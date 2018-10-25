
#ifndef ROBOWORKERS_TIMESTAMPABLE_H
#define ROBOWORKERS_TIMESTAMPABLE_H

#include "utilities.h"

using Timepoint = std::chrono::system_clock::time_point;

class Timestampable {
public:
    Timestampable() : creation_time(getTimestamp()) {};

    virtual Timepoint get_create_time() const { return creation_time; }
    virtual Timepoint get_start_time() const { return start_time; };
    virtual Timepoint get_finish_time() const { return finish_time; };
    virtual void set_start_time() { start_time = getTimestamp(); };
    virtual void set_finish_time() { finish_time = getTimestamp(); };
protected:
    Timepoint creation_time;
    Timepoint start_time;
    Timepoint finish_time;
};

#endif //ROBOWORKERS_TIMESTAMPABLE_H
