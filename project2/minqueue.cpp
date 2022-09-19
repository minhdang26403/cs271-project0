#include "minqueue.h"

template<typename KeyType>
MinQueue<KeyType>::MinQueue(KeyType *A, int n) : data_(n), heap_size_(n) {
  for (int i = 0; i < n; ++i) {
    data_[i] = A[i];
  }
  build_min_heap();
}

template<typename KeyType>
void MinQueue<KeyType>::insert(const KeyType &x) {
  data_.push_back(x);
  sift_up(data_.size() - 1);
  ++heap_size_;
}

template<typename KeyType>
KeyType MinQueue<KeyType>::min() {
  if (data_.empty()) {
    return KeyType();
  }
  return data_.front();
}

template<typename KeyType>
KeyType MinQueue<KeyType>::extract_min() {
  if (data_.empty()) {
    return KeyType();
  }
  KeyType min = data_.front();
  data_[0] = data_.back();
  data_.pop_back();
  heapify(0);
  --heap_size_;
  return min;
}

template<typename KeyType>
void MinQueue<KeyType>::decrease_key(int i, const KeyType &k) {
  if (data_.empty()) {
    return;
  }
  if (k >= data_[i]) {
    return;
  }
  data_[i] = k;
  sift_up(i);
}

template<typename KeyType>
void MinQueue<KeyType>::sort(KeyType *A) {
  if (data_.empty()) {
    return;
  }
  heapsort(A);
}

template<typename KeyType>
std::string MinQueue<KeyType>::to_string() {
  if (data_.empty()) {
    return "";
  }
  std::stringstream ss;
  for (int i = 0; i < data_.size() - 1; ++i) {
    ss << data_[i] << " ";
  }
  ss << data_.back();
  return ss.str();
}

template<typename KeyType>
void MinQueue<KeyType>::heapify(int i) {
  int smallest = i;
  int l = left(i);
  int r = right(i);
  if (l < heap_size_ && data_[smallest] > data_[l]) {
    smallest = l;
  }
  if (r < heap_size_ && data_[smallest] > data_[r]) {
    smallest = r;
  }
  if (smallest != i) {
    std::swap(data_[i], data_[smallest]);
    heapify(smallest);
  }
}

template<typename KeyType>
void MinQueue<KeyType>::sift_up(int i) {
  while (i > -1 && data_[parent(i)] > data_[i]) {
    std::swap(data_[parent(i)], data_[i]);
    i = parent(i);
  }
}

template<typename KeyType>
void MinQueue<KeyType>::build_min_heap() {
  int n = data_.size();
  for (int i = n / 2 - 1; i > -1; --i) {
    heapify(i);
  }
}

template<typename KeyType>
void MinQueue<KeyType>::heapsort(KeyType *A) {
  int n = data_.size();
  for (int i = n - 1; i > 0; --i) {
    A[n - 1 - i] = data_[0];
    std::swap(data_[0], data_[i]);
    --heap_size_;
    heapify(0);
  }
  A[n - 1] = data_[0];
  // Reserve the initial heap size
  heap_size_ = data_.size();
}