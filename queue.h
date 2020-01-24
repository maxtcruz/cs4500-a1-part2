// lang::CwC

#pragma once
#include <stddef.h>
#include "object.h"

/**
 * a class that represents a FIFO queue of Objects
 * @author Max Cruz <cruz.max@husky.neu.edu>, Sean Connolly <connolly.s@husky.neu.edu>
 */
class Queue : public Object {
  public:
    // constructs an empty Queue
    Queue();

    // constructs an empty Queue of a desired size
    Queue(size_t size);

    // frees the Queue from memory
    ~Queue();

    // determines if this Queue is equal to the given Object o
    bool equals(Object* o);

    // computes a hash for this Queue
    size_t hash();

    // pushes the given Object to the end of the Queue
    void push(Object* o);

    // removes and returns the Object at the front of the Queue if one exists
    // else returns nullptr
    Object* pop();

    // clears the elements in this Queue
    void clear();

    // returns the number of elements in this Queue
    size_t size();

    // returns a string representation of this Queue
    char* to_string();
};
