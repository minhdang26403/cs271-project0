#include "usecase.cpp"
#include <cassert>

int main() {
  int arr1[2] = {1, -1};
  assert(sliding_window(arr1, 2, 1) == "1 -1");

  int arr2[8] = {-2,3,-1,-3,-5,3,10,7};
  assert(sliding_window(arr2, 8, 3) == "-2 -3 -5 -5 -5 3");

  std::cout << "Testing completed\n";
}