// lang::CwC

#include <stdlib.h>
#include <stdio.h>
#include "object.h"
#include "string.h"
#include "queue.h"

/**
 * a main program to test the functionality of a Queue
 * @author: Max Cruz <cruz.max@husky.neu.edu>, Sean Connolly <connolly.s@husky.neu.edu>
 */

// prints a fail message to stderr then exits the process
void FAIL(const char* msg) {
  fprintf(stderr, "failed: %s\n", msg);
  exit(1);
}

// prints a success message to stdout
void OK(const char* msg) {
  printf("success: %s\n", msg);
}

// fails the process if a given boolean expression p is false, continues otherwise
void t_true(bool p, const char* msg) {
  if (!p) FAIL(msg); 
}

// two Queue's are equal if they contain the same elements in the same order
void queue_equality() {
  String* s1 = new String("one");
  String* s2 = new String("two");
  Queue* q1 = new Queue();
  Queue* q2 = new Queue();
  q1->push(s1);
  t_true(!q1->equals(q2), "q1 should not equal q2");
  q2->push(s2);
  t_true(q1->equals(q2), "q1 should equal q2");
  q1->push(s1);
  q1->push(s2);
  q2->push(s2);
  q2->push(s1);
  t_true(!q1->equals(q2), "q1 should not equal q2");

  OK("queue equality");

  delete q1;
  delete q2;
  delete s1;
  delete s2;
}

// two Queue's have the same hash if they are equal
void queue_hashes() {
  String* s1 = new String("puma");
  String* s2 = new String("puma");
  Queue* q1 = new Queue();
  Queue* q2 = new Queue();
  q1->push(s1);
  q2->push(s2);
  t_true(q1->equals(q2), "q1 should equal q2");
  t_true(q1->hash() == q2->hash(), "two equal queues have the same hash");

  OK("queue hashes");

  delete q1;
  delete q2;
  delete s1;
  delete s2;
}

// pushing elements onto a Queue should reflect a size increase
void queue_push_increase_size() {
  Object* o1 = new Object();
  Object* o2 = new Object();
  Queue* q1 = new Queue();
  t_true(q1->size() == 0, "initial size is 0");
  q1->push(o1);
  t_true(q1->size() == 1, "size increases to 1");
  q1->push(o2);
  t_true(q1->size() == 2, "size increases to 2");
  q1->push(o1);
  q1->push(o1);
  q1->push(o1);
  q1->push(o1);
  t_true(q1->size() == 6, "size increases to 6");

  OK("queue push increase size");

  delete q1;
  delete o1;
  delete o2;
}

// popping elements off of a Queue should reflect a size decrease
void queue_pop_decrease_size() {
  Object* o1 = new Object();
  Queue* q1 = new Queue();
  q1->push(o1);
  q1->push(o1);
  q1->push(o1);
  q1->push(o1);
  q1->push(o1);
  t_true(q1->size() == 5, "size should be 5");
  q1->pop();
  t_true(q1->size() == 4, "size decreases to 4");
  q1->pop();
  t_true(q1->size() == 3, "size decreases to 3");

  OK("queue pop decrease size");

  delete q1;
  delete o1;
}

// a Queue's elements should be popped in the same order they are pushed
void queue_pop_order() {
  String* s1 = new String("one");
  String* s2 = new String("two");
  String* s3 = new String("three");
  Queue* q1 = new Queue();
  q1->push(s1);
  q1->push(s2);
  q1->push(s3);
  t_true(s1->equals(q1->pop()), "s1 is the first element popped");
  t_true(s2->equals(q1->pop()), "s2 is the second element popped");
  t_true(s3->equals(q1->pop()), "s3 is the third element popped");

  OK("queue pop order");

  delete q1;
  delete s1;
  delete s2;
  delete s3;
}

// peeking returns the Queue's top element but does not remove it
void queue_peek() {
  String* s1 = new String("first");
  String* s2 = new String("second");
  Queue* q1 = new Queue();
  q1->push(s1);
  q1->push(s2);
  t_true(q1->size() == 2, "size is 2 before the peek");
  t_true(s1->equals(q1->peek()), "s1 is the top element");
  t_true(q1->size() == 2, "size is 2 after the peek");

  OK("queue peek");

  delete q1;
  delete s1;
  delete s2;
}

// popping or peeking an empty Queue should return a nullptr
void queue_pop_peek_empty() {
  String* s1 = new String("dummy");
  Queue* q1 = new Queue();
  q1->push(s1);
  t_true(s1->equals(q1->pop()), "popping once returns s1");
  t_true(q1->is_empty(), "queue should now be empty");
  t_true(q1->pop() == nullptr, "popping twice returns nullptr");
  t_true(q1->peek() == nullptr, "peeking return nullptr");

  OK("queue pop peek empty");

  delete q1;
  delete s1;
}

// clearing a Queue should empty it
void queue_clear() {
  String* s1 = new String("sean:)");
  Queue* q1 = new Queue();
  q1->push(s1);
  q1->push(s1);
  q1->push(s1);
  q1->push(s1);
  t_true(q1->size() == 4 && !q1->is_empty(), "queue has size 4 prior to clearing");
  q1->clear();
  t_true(q1->is_empty(), "queue is empty after clearing");

  OK("queue clear");

  delete q1;
  delete s1;
}

// runs the tests
int main() {
  queue_equality();
  queue_hashes();
  queue_push_increase_size();
  queue_pop_decrease_size();
  queue_pop_order();
  queue_peek();
  queue_pop_peek_empty();
  queue_clear();
  return 0;
}
