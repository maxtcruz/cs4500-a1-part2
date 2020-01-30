# a1 part 2

* **object.h**
  - an API spec for a top-level Object class. An Object should include functions to determine equality between two Objects and to generate a hashcode for an Object.
* **string.h**
  - an API spec for an immutable String class, which is a child of the Object class. This spec was included mainly to aid in testing that a Queue can contain objects other than the top-level Object class. A String should support comparisons for equality and rankings (i.e. alphabetic ordering), generating a hashcode, concatenation, and returning the length of the string. 
* **queue.h**
  - an API spec for a dynamically-sized FIFO Queue class, which is a child of the Object class. A Queue should be able to support comparisons for equality, generating a hashcode, pushing elements onto the end of the queue, popping elements off of the front of the queue, peeking at the front element, clearing the queue's contents, detecting when it's empty, and returning the size of the queue. 
* **test-queue.cpp**
  - compiling and executing this file successfully with a Queue implementation will verify the correctness of said Queue.
