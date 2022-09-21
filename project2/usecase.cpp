#include "minqueue.h"

#include <iostream>

std::string sliding_window(int arr[], int len, int k) {
  if (len == 0) {
    return "";
  }
  MinQueue<int> mq;
  std::unordered_map<int,int> index_map;
  int min_value = INT_MAX;
  // First, finds the minimum value in the window of size k
  // and maps the value to its index
  for (int i = 0; i < k; ++i) {
    if (arr[i] < min_value) {
      min_value = arr[i];
    }
    mq.insert(arr[i]);
    index_map[arr[i]] = i;
  }
  std::vector<int> result;
  result.push_back(min_value);
  // Moves the window of size k by one step at each iteration
  for (int end = k; end < len; ++end) {
    // the start index of the current window
    int start = end - k + 1;
    // At each iteration, check if the current min value is out of the window
    // by using index map (if its index < start index of the window). If true,
    // we find a new min value in the window by extracting the root of the min-heap
    while (index_map[min_value] < start) {
      mq.extract_min();
      // The heap is empty, so let min_value be a default value
      if (mq.empty()) {
        min_value = INT_MAX;
        break;
      }
      min_value = mq.min();
    }
    // Find a smaller value
    if (arr[end] < min_value) {
      min_value = arr[end];
    }

    // Inserts value into the min queue and performs index map
    mq.insert(arr[end]);
    index_map[arr[end]] = end;
    result.push_back(min_value);
  }
  std::stringstream ss;
  int n = result.size();
  for (int i = 0; i < n - 1; ++i) {
    ss << result[i] << " ";
  }
  ss << result[n - 1];
  return ss.str();
}
