#include <iostream>
#include <ctime>
#include "linear_ds\vector.hpp"

using namespace std;

int main() {
  int a[] = {1, 2};
  Vector vec(a, 2);
  clock_t start = clock();
  for(int i = 0; i < 10000000; i++) {
    vec.push_back(i);
  }
  for(int i = 0; i < 10000000; i++) {
    vec.pop_back();
  }
  cout << (clock() - start + 0.) / CLOCKS_PER_SEC << endl;

  VectorNaive vect(a, 2);
  clock_t star = clock();
  for(int i = 0; i < 10000; i++) {
    vect.push_back(i);
  }
  for(int i = 0; i < 10000; i++) {
    vect.pop_back();
  }
  cout << (clock() - star + 0.) / CLOCKS_PER_SEC << endl;
  
  system("pause");
  return 0;
}