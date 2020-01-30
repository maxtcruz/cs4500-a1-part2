// lang::CwC

#pragma once
#include <stddef.h>

/**
 * a class that represents the root of object ancestral tree
 * @author Max Cruz <cruz.max@husky.neu.edu>, Sean Connolly <connolly.s@husky.neu.edu>
 * Reference: https://piazza.com/class/k51bluky59n2jr?cid=166
 */
class Object {
  public:
    // constructs an Object
    Object();

    // virtual destructor for subclasses
    virtual ~Object();

    // computes a hash for this Object
    virtual size_t hash();

    // determines if this Object equals another Object o
    virtual bool equals(Object* o);

    // generates a string representation for this Object
    virtual char* to_string();

    // print to stdout
    virtual void print();
};
