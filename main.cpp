#include <iostream>
// #include "linear_ds\vector.hpp"
#include <ctime>
#include <vector>

using namespace std;

int main() {
  vector<pair<int, int>> vec;
  vec.push_back(make_pair(1, 1));
  vec.emplace_back(1, 1);

  return 0;
  // int a[] = {1, 2};
  // vector vec(a, 2);
  // clock_t start = clock();
  // for(int i = 0; i < 10000000; i++) {
  //   vec.push_back(i);
  // }
  // for(int i = 0; i < 10000000; i++) {
  //   vec.pop_back();
  // }
  // cout << (clock() - start + 0.) / CLOCKS_PER_SEC << endl;

  // vectorNaive vect(a, 2);
  // clock_t star = clock();
  // for(int i = 0; i < 10000; i++) {
  //   vect.push_back(i);
  // }
  // for(int i = 0; i < 10000; i++) {
  //   vect.pop_back();
  // }
  // cout << (clock() - star + 0.) / CLOCKS_PER_SEC << endl;
  
  system("pause");
  return 0;
}