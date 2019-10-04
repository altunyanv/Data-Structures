#pragma once

class Vector {
private:
  int * container;
  int size, capacity;
public:
  Vector(int * _container, int _size) : size(_size), container(new int[_size]), capacity(_size) {
    for(int i = 0; i < size; ++i)
      container[i] = _container[i];
  }

  void push_back(int value) {
    if (size < capacity) {
      container[size] = value;
      size++;
    }
    else {
      int nCapacity = 2 * capacity;
      int * nContainer = new int[nCapacity];
      for(int i = 0; i < size; i++) {
        nContainer[i] = container[i];
      }
      capacity = nCapacity;
      int * tmp = container;
      container = nContainer;
      delete[] tmp;
      container[size] = value;
      size++;
    }
  }

  void pop_back() {
    if (size * 4 > capacity) {
      size--;
    }
    else {
      int nCapacity = capacity / 2;
      int * nContainer = new int[nCapacity];
      for(int i = 0; i < size - 1; i++) {
        nContainer[i] = container[i];
      }
      capacity = nCapacity;
      int * tmp = container;
      container = nContainer;
      delete[] tmp;
      size--;
    }
  }
};


class VectorNaive {
private:
  int * container;
  int size, capacity;
public:
  VectorNaive(int * _container, int _size) : size(_size), container(new int[_size]), capacity(_size) {
    for(int i = 0; i < size; ++i)
      container[i] = _container[i];
  }

  void push_back(int value) {
    int * nContainer = new int[size + 1];
    for(int i = 0; i < size; i++) {
      nContainer[i] = container[i];
    }
    nContainer[size] = value;
    size++;
    int * tmp = container;
    container = nContainer;
    delete[] tmp;
  }

  void pop_back() {
    int * nContainer = new int[size - 1];
    for(int i = 0; i < size - 1; i++) {
      nContainer[i] = container[i];
    }
    size--;
    int * tmp = container;
    container = nContainer;
    delete[] tmp;
  }
};