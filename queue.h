// lang::CwC

#pragma once
#include <stddef.h>
#include "object.h"

/**
 * a class that represents a dynamically-sized FIFO queue of Objects
 * @author Max Cruz <cruz.max@husky.neu.edu>, Sean Connolly <connolly.s@husky.neu.edu>
 */
class Queue : public Object {
  public:
    // constructs an empty Queue
    Queue();

    // frees the Queue from memory
    virtual ~Queue();

    // determines if this Queue is equal to the given Object o
    virtual bool equals(Object* o);

    // computes a hash for this Queue
    virtual size_t hash();

    // pushes the given Object to the end of the Queue
    virtual void push(Object* o);

    // removes and returns the Object at the front of the Queue if one exists
    // else returns nullptr
    virtual Object* pop();

    // returns the Object at the front of the Queue, but does not remove it, if one exists
    // else returns nullptr
    virtual Object* peek();

    // clears the elements in this Queue
    virtual void clear();

    // determines if this Queue is empty
    virtual bool is_empty();

    // returns the number of elements in this Queue
    virtual size_t size();

    // returns a string representation of this Queue (optional)
    virtual char* to_string();
};
