#ifndef MIN_QUEUE_H_
#define MIN_QUEUE_H_

#include <algorithm>
#include <string>
#include <sstream>
#include <unordered_map>
#include <vector>


template<typename KeyType>
class MinQueue {
 public:
  MinQueue() = default;

  MinQueue(KeyType *A, int n);

  bool empty() const { return data_.empty(); }

  void insert(const KeyType &x);

  KeyType min();

  KeyType extract_min();

  void decrease_key(int i, const KeyType &k);

  void sort(KeyType *data);

  std::string to_string();
 private:
  int parent(int i) const { return (i - 1) / 2; }
  int left(int i) const { return 2 * i + 1; }
  int right(int i) const { return 2 * i + 2; }

  void heapify(int i);

  void sift_up(int i);

  void build_min_heap();

  void heapsort(KeyType *A);

  // The vector `data` storing heap elements
  std::vector<KeyType> data_;
  // The current heap size (different from `data` size)
  int heap_size_{0};
};

#include "minqueue.cpp"

#endif // MIN_QUEUE_H_