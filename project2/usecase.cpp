#include "minqueue.h"

#include <algorithm>
#include <iostream>
#include <string>
#include <sstream>
#include <unordered_map>
#include <vector>

std::string sliding_window(int arr[], int len, int k) {
  if (len == 0) {
    return "";
  }
  MinQueue<int> mq;
  std::unordered_map<int,int> index_map;
  int min_value = INT_MAX;
  for (int i = 0; i < k; ++i) {
    if (arr[i] < min_value) {
      min_value = arr[i];
    }
    mq.insert(arr[i]);
    index_map[arr[i]] = i;
  }
  std::vector<int> result;
  result.push_back(min_value);
  for (int end = k; end < len; ++end) {
    int start = end - k + 1;
    while (index_map[min_value] < start) {
      mq.extract_min();
      if (mq.empty()) {
        min_value = INT_MAX;
        break;
      }
      min_value = mq.min();
    }
    if (arr[end] < min_value) {
      min_value = arr[end];
    }
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
