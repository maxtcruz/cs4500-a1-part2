// lang::CwC

#pragma once
#include <stddef.h>
#include <string.h>
#include "object.h"

/**
 * a class that represents an immutable string
 * @author Max Cruz <cruz.max@husky.neu.edu>, Sean Connolly <connolly.s@husky.neu.edu>
 */
class String : public Object {
  public:
    // copies a string literal/constant array of characters into this String
    String(const char* s);

    // copies an array of characters into this String
    String(char* s);

    // copies a String's characters into this String
    String(String* s);

    // frees this String's internal array of characters
    ~String();

    // determines if this String is equal to a given Object o
    bool equals(Object* o);

    // returns 0 if this String equals the given String
    // returns -1 if this String is lesser than the given String
    // returns 1 if this String is greater than the given String
    int compareTo(String* other);

    // computes a hash for this String
    size_t hash();

    // returns a new String that is the result of concatenating this String's characters
    // with those of a given String
    String* concat(String * other);

    // returns the length of this String
    size_t length();

    // returns a copy of this String's characters
    char* to_string();
};
