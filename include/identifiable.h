#ifndef ROBOWORKERS_INDENTIFIABLE_H
#define ROBOWORKERS_INDENTIFIABLE_H

#include <string>
#include "utilities.h"

#define stringify( name ) # name

class Identifiable {
public:
    Identifiable() : id(getUUID()) {};
    virtual std::string getId() const { return id; };
private:
    std::string id;
};

#endif //ROBOWORKERS_INDENTIFIABLE_H
