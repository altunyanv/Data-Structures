#pragma once

class vector {
private:
  int * container;
  int size;
public:
  vector(int * _container, int _size) : size(_size), container(_container) {
    for(int i = 0; i < size; ++i)
      container[i] = _container[i];
  }
};