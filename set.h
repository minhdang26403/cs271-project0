#ifndef SET_H_
#define SET_H_

#include <string>
#include <sstream>
#include <utility>

template<typename ValueType>
class Set {
 private:
  struct Node {
    ValueType value_;
    Node *next_{};

    /** Constructor */
    Node(const ValueType &value) : value_(value) {}
    Node(const ValueType &value, Node *next) : value_(value), next_(next) {}
    Node(ValueType&& value) : value_(std::move(value)) {}
    Node(ValueType&& value, Node *next) : value_(std::move(value)), next_(next) {}
  };
 public:
  /** Default constructor */
  Set() = default;

  /** Copy constructor */
  Set(const Set &other);

  /** Destructor */
  ~Set();

  Set& operator=(const Set& src) {
    Set copy(src);
    copy.swap(*this);
    return *this;
  }


  /**
   * Precondition: None
   * Postcondition: a new element is inserted to the set if
   * that element doesn't exist in the set before. Otherwise,
   * the set remains unchanged
   */
  void insert(const ValueType &x);

  /**
   * Precondition: None
   * Postcondition: The specified element is removed from the set if 
   * it exists. Otherwise, the set remains unchanged.
   */
  void remove(const ValueType &x);

  /** 
   * Precondition: None
   * Postcondition: None
   */
  std::size_t cardinality() const { return size_; }

  /**
   * Precondition: None
   * Postcondition: None
   */
  bool empty() const { return size_ == 0; }

  /**
   * Precondition: None
   * Postcondition: None
   */
  Node *begin() const { return head_; }

  /**
   * Precondition: None
   * Postcondition: None
   */
  bool contains(const ValueType &x) const;

  /**
   * Precondition: None
   * Postcondition: None
   */
  bool operator==(const Set &other) const;

  /**
   * Precondition: None
   * Postcondition: None
   */
  bool operator<=(const Set &other) const;

  /**
   * Precondition: None
   * Postcondition: a new set containing all elements from both set
   * is returned
   */
  Set<ValueType> operator+(const Set &t);

  /**
   * Precondition: None
   * Postcondition: a new set containing elements that exist in both two sets
   * is returned
   */
  Set<ValueType> operator&(const Set &t);

  /**
   * Precondition: None
   * Postcondition: a new set containing elements that are in set `s`
   * but not in set `t`
   */
  Set<ValueType> operator-(const Set &t);

  /**
   * Precondition: None
   * Postcondition: a string representation of the set
   */
  std::string to_string();

 private:
  void deep_copy(const Set& src);

  void swap(const Set &rhs);

  // The head of the linked list
  Node *head_{};
  // The length of it
  std::size_t size_{};
};

#include "set.cpp"

#endif // SET_H_