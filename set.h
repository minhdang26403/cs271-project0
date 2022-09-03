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

  /** Destructor */
  ~Set();

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
   * Postcondition: Returns the cardinality of the set.
   */
  std::size_t cardinality() const { return size_; }

  /**
   * Precondition: None
   * Postcondition: Returns true if the set is empty and false otherwise.
   */
  bool empty() const { return size_ == 0; }

  /**
   * Precondition: None
   * Postcondition: Returns the head of the set.
   */
  Node *begin() const { return head_; }

  /**
   * Precondition: None
   * Postcondition: Returns true if the set contains the element x and false otherwise.
   */
  bool contains(const ValueType &x) const;

  /* == operator
   * Precondition: this and other are Set objects.
   * Postcondition: None
   */
  bool operator==(const Set &other) const;

  /* <= operator
   * Precondition: this and other are Set objects.
   * Postcondition: None
   */
  bool operator<=(const Set &other) const;

  /* + operator
   * Precondition: this and t are Set objects.
   * Postcondition: a new set containing all elements from both set
   * is returned
   */
  Set<ValueType> operator+(const Set &t);

  /* & operator
   * Precondition: this and t are Set objects
   * Postcondition: a new set containing elements that exist in both two sets
   * is returned
   */
  Set<ValueType> operator&(const Set &t);

  /* - operator
   * Precondition: this and t are Set objects
   * Postcondition: a new set containing elements that are in set `s`
   * but not in set `t`
   */
  Set<ValueType> operator-(const Set &t);

  /**
   * Precondition: None
   * Postcondition: Returns a string representation of the Set object.
   */
  std::string to_string();

 private:
  Node *head_{};
  std::size_t size_{};
};

#include "set.cpp"

#endif // SET_H_
