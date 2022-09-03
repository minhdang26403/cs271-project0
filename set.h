#ifndef SET_H_
#define SET_H_

#include <string>
#include <sstream>
#include <utility>

template<typename ValueType>
class Set {
 private:
  struct Node {
    // value of the node
    ValueType value_;
    // a pointer to the next element
    Node *next_{};

    /**
     * Constructor
     * Precondition: `value` is the value of the node and 
     * `next` is the pointer to the next node
     * Postcondition: creates a Node object 
     */
    Node(const ValueType &value, Node *next=nullptr) : value_(value), next_(next) {}
  };
 public:
  /** 
   * Default constructor 
   * Precondition: None
   * Postcondition: creates a new Set object
   */
  Set() = default;

  /** 
   * Copy constructor 
   * Precondition: `src` is a source object to construct from
   * Postcondition: creates a new Set object, which is a copy of the `src`
   * Set object
   */
  Set(const Set &src);

  /** 
   * Destructor 
   * Precondition: None
   * Postcondition: destroys the current Set object
   */
  ~Set();

  /** 
   * Copy assignment operator 
   * Precondition: `this` and `src` are two Set objects
   * Postcondition: `this` Set object is assigned to `src` Set object
   * */
  Set& operator=(const Set &src);

  /**
   * Precondition: `x` is the value of the element to insert
   * Postcondition: a new element is inserted to the set if
   * that element doesn't exist in the set before. Otherwise,
   * the set remains unchanged
   */
  void insert(const ValueType &x);

  /**
   * Precondition: `x` is the value of the element to remove
   * Postcondition: the specified element is removed from the set if 
   * it exists. Otherwise, the set remains unchanged.
   */
  void remove(const ValueType &x);

  /** 
   * Precondition: None
   * Postcondition: returns the cardinality of the set.
   */
  std::size_t cardinality() const { return size_; }

  /**
   * Precondition: None
   * Postcondition: returns true if the set is empty and false otherwise.
   */
  bool empty() const { return size_ == 0; }

  /**
   * Precondition: None
   * Postcondition: returns a pointer the head of the linked list
   */
  Node *begin() const { return head_; }

  /**
   * Precondition: `x` is the value of the element to check
   * Postcondition: returns true if the set contains the element `x` and false otherwise.
   */
  bool contains(const ValueType &x) const;

  /* == operator
   * Precondition: `this` and `t` are Set objects.
   * Postcondition: returns true if two sets are equal; otherwise, returns false
   */
  bool operator==(const Set &t) const;

  /* <= operator
   * Precondition: `this` and `t` are Set objects.
   * Postcondition: returns true if `t` is a subset of `t`; otherwise, returns false
   */
  bool operator<=(const Set &t) const;

  /* + operator (union operator)
   * Precondition: `this` and `t` are Set objects.
   * Postcondition: returns a new set containing all elements from both set
   */
  Set<ValueType> operator+(const Set &t);

  /* & operator (intersection operator)
   * Precondition: `this` and `t` are Set objects
   * Postcondition: returns a new set containing elements that exist in both two sets
   */
  Set<ValueType> operator&(const Set &t);

  /* - operator (difference operator)
   * Precondition: `this` and `t` are Set objects
   * Postcondition: returns a new set containing elements that are in set `s`
   * but not in set `t`
   */
  Set<ValueType> operator-(const Set &t);

  /**
   * Precondition: None
   * Postcondition: returns a string representation of the Set object.
   */
  std::string to_string();

 private:
  /**
   * Precondition: `src` is a source Set object to copy from
   * Postcondition: Creates a deep copy of the source Set object
   */
  void deep_copy(const Set& src);

  /**
   * Swaps the member variables of `this` Set object and `rhs` Set object
   * Precondition: `rhs` is the Set object to swap from
   * Postcondition: `this` is a new Set object with member variables of
   * the `rhs` Set object
   */
  void swap(const Set &rhs);

  // The head of the linked list
  Node *head_{};
  // The length of it
  std::size_t size_{};
};

#include "set.cpp"

#endif // SET_H_
