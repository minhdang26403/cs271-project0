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
  /**
   * Default constructor
   * Precondition: None
   * Postcondition: creates a new MinQueue object
   */
  MinQueue() = default;

  /**
   * Custom Constructor
   * Precondition: `A` is a pointer to an array and `n` is
   * the size of that array
   * Postcondition: creates a MinQueue object whose elements
   * are elements of the array `A`
   */
  MinQueue(KeyType *A, int n);

  /**
   * Check if the priority queue is empty
   * Precondition: None
   * Postcondition: returns true if the priority queue is empty and false otherwise
   */
  constexpr bool empty() const noexcept { return data_.empty(); }

  /**
   * Inserts an element to the priority queue
   * Precondition: `x` is the value of the element to insert
   * Postcondition: the element `x` is inserted and the min-heap property
   * is preserved
   */
  void insert(const KeyType &x);
  
  /**
   * Gets the smallest value in the priority queue
   * Precondition: the priority queue satisfies the min-heap property
   * Postcondition: returns the smallest element in the queue; if the queue
   * is empty, returns a default element.
   */
  KeyType min();

  /**
   * Extracts and returns the smallest element in the priority queue
   * Precondition: the priority queue has the min-heap property
   * Postcondition: the smallest element is removed and the min-heap property 
   * is preserved
   */
  KeyType extract_min();

  /**
   * Decreases the value at index `i` to the new value `k`
   * Precondition: `i` is a valid index and `k` is not larger than the current key
   * Postcondition: the value at index `i` is changed to `k` and that value may
   * go up the binary heap to preserve the min heap property
   */
  void decrease_key(int i, const KeyType &k);

  /**
   * Sorts the elements of the priority queue and stores them in the `data` array
   * Precondition: the priority queue satisfies the min-heap property
   * Postcondition: the `data_` array of the priority queue and `data` array is
   * sorted in ascending order
   */
  void sort(KeyType *data);

  /**
   * Precondition: None
   * Postcondition: returns a string representation of the MinQueue object.
   */
  std::string to_string();
 private:
  /**
   * Calculates the index of the parent of the element at index `i`
   * Precondition: None
   * Postcondition: None
   */
  constexpr int parent(int i) const noexcept { return (i - 1) / 2; }

  /**
   * Calculates the index of the left child of the element at index `i`
   * Precondition: None
   * Postcondition: None
   */
  constexpr int left(int i) const noexcept { return 2 * i + 1; }

  /**
   * Calculates the index of the right child of the element at index `i`
   * Precondition: None
   * Postcondition: None
   */
  constexpr int right(int i) const noexcept { return 2 * i + 2; }

  /**
   * Maintains the min-heap property by floating down the element at index `i`
   * Precondition: the left child and right child subtrees of this
   * element are min-heaps
   * Postcondition: the subtree rooted at index `i` is min-heap
   */
  void heapify(int i);

  /**
   * Moves an element at index `i` up the heap
   * Precondition: the left child and right child subtrees of this element are min-heaps
   * Postcondition: the min-heap property is preserved
   */
  void sift_up(int i);

  /**
   * Precondition: None
   * Postcondition: the `data_` vector satisfies the min-heap property
   */
  void build_min_heap();

  /**
   * Sorts the elements of the priority queue and stores them in the `A` array
   * Precondition: the priority queue satisfies the min-heap property
   * Postcondition: the `data_` array of the priority queue and `A` array is
   * sorted in ascending order
   */
  void heapsort(KeyType *A);

  // The `data_` vector storing heap elements
  std::vector<KeyType> data_;
  // The current heap size (different from `data_` size)
  int heap_size_{0};
};

#include "minqueue.cpp"

#endif // MIN_QUEUE_H_