// lang::CwC

#pragma once
#include <stddef.h>

/**
 * a class that represents the root of object ancestral tree
 * @author Max Cruz <cruz.max@husky.neu.edu>, Sean Connolly <connolly.s@husky.neu.edu>
 */
class Object {
  public:
    // determines if this Object equals another Object o
    virtual bool equals(Object* o);

    // computes a hash for this Object
    virtual size_t hash();

    // generates a string representation for this Object
    virtual char* to_string();
};
