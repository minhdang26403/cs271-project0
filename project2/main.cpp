#include "usecase.cpp"
#include <cassert>

using namespace std;

int main() {
  try {
    int* empty = new int[0];
    string window_result = sliding_window(empty, 0, 0);
    if(window_result != "") {
      cout << "Incorrect sliding window result. Expected an empty string but got : " << window_result << endl;
    }
    int arr1[8] = {-2,3,-1,-3,-5,3,10,7};
    window_result = sliding_window(arr1, 8, 3);
    if(window_result != "-2 -3 -5 -5 -5 3") {
      cout << "Incorrect sliding window result. Expected -2 -3 -5 -5 -5 3 but got : " << window_result << endl;
    }
    int arr2[2] = {1, -1};
    window_result = sliding_window(arr2, 1, 1);
    if(window_result != "1") {
      cout << "Incorrect sliding window result. Expected 1 but got : " << window_result << endl;
    }
  } catch(exception &e) {
    cerr << "Error in generating sliding window result : " << e.what() << endl;
  }

  std::cout << "Testing completed\n";
}