#include "minqueue.h"

template<typename KeyType>
MinQueue<KeyType>::MinQueue(KeyType *A, int n) : data_(n), heap_size_(n) {
  // Copy elements from input array `A` to the member vector
  for (int i = 0; i < n; ++i) {
    data_[i] = A[i];
  }
  // Build min-heap from the initial vector
  build_min_heap();
}

template<typename KeyType>
void MinQueue<KeyType>::insert(const KeyType &x) {
  // Insert an element at the end of the array
  data_.push_back(x);
  // Move that element up the heap to preserve min-heap property
  sift_up(data_.size() - 1);
  ++heap_size_;
}

template<typename KeyType>
KeyType MinQueue<KeyType>::min() {
  if (data_.empty()) {
    return KeyType();
  }
  // The first element of a min-heap is the smallest element
  return data_.front();
}

template<typename KeyType>
KeyType MinQueue<KeyType>::extract_min() {
  if (data_.empty()) {
    return KeyType();
  }
  KeyType min = data_.front();
  // Copy the last element to the root of the heap
  // since the root is removed
  data_[0] = data_.back();
  data_.pop_back();
  // Heapify from the root to preserve the min-heap property
  heapify(0);
  --heap_size_;
  return min;
}

template<typename KeyType>
void MinQueue<KeyType>::decrease_key(int i, const KeyType &k) {
  // Input validation
  if (i < 0 || i >= data_.size()) {
    return;
  }
  if (k >= data_[i]) {
    return;
  }

  // Change key and moves an element up (if necessary) to 
  // maintain the heap property
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
  // Empty priority queue
  if (data_.empty()) {
    return "";
  }
  std::stringstream ss;
  // Goes through each element except the last element and inserts
  // its value into the string stream
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
  // Compare with left and right child to find the smallest value
  if (l < heap_size_ && data_[smallest] > data_[l]) {
    smallest = l;
  }
  if (r < heap_size_ && data_[smallest] > data_[r]) {
    smallest = r;
  }

  // If we found that there is a value smaller than the 
  // current value, swap it and heapify at the `smallest` index
  if (smallest != i) {
    std::swap(data_[i], data_[smallest]);
    heapify(smallest);
  }
}

template<typename KeyType>
void MinQueue<KeyType>::sift_up(int i) {
  // Repeatedly compares the current node's value with its
  // parent and swaps if the parent's value is larger than its child
  // to maintain the min-heap property
  while (i > -1 && data_[parent(i)] > data_[i]) {
    std::swap(data_[parent(i)], data_[i]);
    i = parent(i);
  }
}

template<typename KeyType>
void MinQueue<KeyType>::build_min_heap() {
  int n = data_.size();
  // data_[n/2...data.length] are all leaves, thus trivial min-heaps.
  // Iterates in descending order to corrects the min-heap property with
  // assumption that left(i) and right(i) are min-heaps
  for (int i = n / 2 - 1; i > -1; --i) {
    heapify(i);
  }
}

template<typename KeyType>
void MinQueue<KeyType>::heapsort(KeyType *A) {
  int n = data_.size();
  // Repeatedly swaps the root with the last element, then exclude the last 
  // element from the heap (decrements the heap size), and heapify from the 
  // root to correct the min-heap property
  for (int i = n - 1; i > 0; --i) {
    A[n - 1 - i] = data_[0];
    std::swap(data_[0], data_[i]);
    --heap_size_;
    heapify(0);
  }
  A[n - 1] = data_[0];
  // Preserve the initial heap size
  heap_size_ = data_.size();
  // Preserve the min-heap property since `data_` is sorted in descending order
  build_min_heap();
}