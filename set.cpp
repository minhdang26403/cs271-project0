#include "set.h"

template<typename ValueType>
Set<ValueType>::~Set() {
  Node *current = head_;
  Node *node_to_delete;
  // Goes through each node and frees it
  while (current != nullptr) {
    node_to_delete = current;
    current = current->next_;
    delete node_to_delete;
  }
}

template <typename ValueType>
void Set<ValueType>::insert(const ValueType &x) {
  if (contains(x)) {
    return;
  }
  // Inserts a new node if it doesn't exist
  auto new_node = new Node(x);
  new_node->next_ = head_;
  head_ = new_node;
  ++size_;
}

template <typename ValueType>
void Set<ValueType>::remove(const ValueType &x) {
  Node *prev = nullptr;
  Node *node_to_delete = head_;
  // Finds the element to remove and keeps a pointer to the previous node
  // of that element
  while (node_to_delete != nullptr && node_to_delete->value_ != x) {
    prev = node_to_delete;
    node_to_delete = node_to_delete->next_;
  }

  // Does nothing if that element doesn't exist
  if (node_to_delete == nullptr) {
    return;
  }

  if (prev == nullptr) {
    head_ = head_->next_;
  } else {
    prev->next_ = node_to_delete->next_;
  }
  delete node_to_delete;
  --size_;
}

template <typename ValueType>
bool Set<ValueType>::contains(const ValueType &x) const {
  Node *current = head_;
  // Goes through each node to check if it contains the element `x`
  while (current != nullptr) {
    if (current->value_ == x) {
      return true;
    }
    current = current->next_;
  }
  return false;
}

template <typename ValueType>
bool Set<ValueType>::operator==(const Set &t) const {
  // two sets are equal if they are subsets of each other
  return *this <= t && t <= *this;
}

template <typename ValueType>
bool Set<ValueType>::operator<=(const Set &t) const
{
  Node *current = head_;
  // Goes through each element in the first set to make sure it 
  // exists in the second set
  while (current != nullptr) {
    if (!t.contains(current->value_)) {
      return false;
    }
    current = current->next_;
  }
  return true;
}

template <typename ValueType>
Set<ValueType> Set<ValueType>::operator+(const Set &t) {
  Set<ValueType> result;
  Node *t_element = t.begin();
  // Inserts all elements from set `t` first
  while (t_element != nullptr) {
    result.insert(t_element->value_);
    t_element = t_element->next_;
  }

  Node *s_element = head_;
  // Inserts all elements from set `s` (insert method will skip
  // duplicate values)
  while (s_element != nullptr) {
    result.insert(s_element->value_);
    s_element = s_element->next_;
  }

  return result;
}

template <typename ValueType>
Set<ValueType> Set<ValueType>::operator&(const Set &t) {
  Set<ValueType> result;
  Node *s_element = head_;
  // Goes through each element in set `s` and inserts it into
  // the `result` set if it also exists in set `t`
  while (s_element != nullptr) {
    if (t.contains(s_element->value_)) {
      result.insert(s_element->value_);
    }
    s_element = s_element->next_;
  }
  return result;
}

template<typename ValueType>
Set<ValueType> Set<ValueType>::operator-(const Set &t) {
  Set<ValueType> result;
  Node *s_element = head_;
  // Goes through each element in set `s` and inserts it into
  // the `result` set if it doesn't exist in set `t`
  while (s_element != nullptr) {
    if (!t.contains(s_element->value_)) {
      result.insert(s_element->value_);
    }
    s_element = s_element->next_;
  }
  return result;
}

template <typename ValueType>
std::string Set<ValueType>::to_string() {
  Node *current = head_;
  if (current == nullptr) {
    return "";
  }
  std::stringstream set_str;
  // Goes through each element except the last element and inserts 
  // its value into the string stream
  while (current->next_ != nullptr) {
    set_str << current->value_ << " ";
    current = current->next_;
  }
  set_str << current->value_;
  return set_str.str();
}