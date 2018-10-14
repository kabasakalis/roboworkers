
#ifndef ROBOWORKERS_TIMESTAMPABLE_H
#define ROBOWORKERS_TIMESTAMPABLE_H

#include "utilities.h"
using Timepoint = std::chrono::system_clock::time_point;

class Timestampable {
public:
    Timestampable() : created_(getTimestamp()) {};
    constexpr virtual Timepoint getCreated() const { return created_; }
    constexpr virtual Timepoint getStarted() const { return started_; };
    constexpr virtual Timepoint getFinished() const { return finished_; };
    void setStarted() { started_ = getTimestamp(); };
    void setFinished() { finished_ = getTimestamp(); };
private:
    const Timepoint created_;
    Timepoint started_;
    Timepoint finished_;
};

#endif //ROBOWORKERS_TIMESTAMPABLE_H
