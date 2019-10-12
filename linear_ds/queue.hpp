#pragma once

class Queue {
  /*
    Queue Data Structure
    Must be implemented by singly linked list

    Constuctors:
      Empty constructor - creates empty queue
    
    Methods:
      push - add element from one end
      front - get element from other end
      pop - erase the front element
      size - count of elements in queue
      empty - boolean function to check if queue is empty
  */
};

template<int MAX_SIZE>
class QueueCyclic {
private:
  int container[MAX_SIZE];

  /*
    Queue Data Structure Using Static Array
    The template above must be left unchanged, i.e. no dynamic array must be used
    Declaration of obejct is done as follows
    QueueCyclic<100> q; // creates queue with maximal available size of 100
    HINT: All the elements are placed in static array sequentially and you only need to know the front and tail element indices
  */

};
