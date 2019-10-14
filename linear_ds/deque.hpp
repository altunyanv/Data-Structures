#pragma once
#include <vector>
#include <list>

class DequeVectors {
private:
  std::vector<int> left, right;
  int left_helper, right_helper;

  /*
    Deque Data Structure
    Must be implemented as two vectors expanding left and right
    If right.empty() left_helper indicates the index of rightmost element in deque (index for 'left' vector)
    If left.empty() right_helper indicates the index of leftmost element in deque (index for 'right' vector)
    If both are non empty then left.back() of front element of deque and right.back() is the back element

    Constuctors:
      Empty constructor - creates empty deque
    
    Methods:
      push_back / push_front - add element from given side
      pop_back / pop_front - pop element from given side
      operator [] - gets element at index
      size - gets elements count in deque
  */
};

template<unsigned int MAX_SIZE>
class DequeCyclic {
private:
  int container[MAX_SIZE];
  int frontId, backId;
  unsigned int size;

public:
  DequeCyclic() {
    frontId = 0;
    backId = MAX_SIZE - 1;
    size = 0;
  }

  void push_back(int value) {
    backId = (backId + 1) % MAX_SIZE;
    container[backId] = value;
    size++;
  }

  void push_front(int value) {
    frontId = (frontId - 1 + MAX_SIZE) % MAX_SIZE;
    container[frontId] = value;
    size++;
  }

  void pop_front() {
    frontId = (frontId + 1) % MAX_SIZE;
    size--;
  }

  void pop_back() {
    backId = (backId - 1 + MAX_SIZE) % MAX_SIZE;
    size--;
  }

  int operator [] (int index) {
    return container[(frontId + index) % MAX_SIZE];
  }
};


class Deque {
private:
  int** containers;
  int frontContainer, backContainer, frontId, backId;

  /*
    Implement...
  */
};

