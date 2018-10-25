/**
 * @file identifiable.h
 *
 * @brief Identifiable class, subclasses inherit a unique id.
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
