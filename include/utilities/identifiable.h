#ifndef ROBOWORKERS_INDENTIFIABLE_H
#define ROBOWORKERS_INDENTIFIABLE_H

#include "utilities.h"

#define stringify( name ) # name

class Identifiable {
public:
    Identifiable() : id(getUUID()) {};
    virtual std::string getId()  { return id; };
protected:
    std::string id;
};

#endif //ROBOWORKERS_INDENTIFIABLE_H
