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

    Node(const ValueType &value) : value_(value) {}
    Node(const ValueType &value, Node *next) : value_(value), next_(next) {}
    Node(ValueType&& value) : value_(std::move(value)) {}
    Node(ValueType&& value, Node *next) : value_(std::move(value)), next_(next) {}
  };
 public:
  /** Default constructor */
  Set() = default;

  ~Set() {
    Node *current = head_;
    Node *node_to_delete;
    while (current != nullptr) {
      node_to_delete = current;
      current = current->next_;
      delete node_to_delete;
    }
  }

  /**
   * Inserts an element into the set
   * @param x the value of the element to insert
   */
  void insert(const ValueType &x) {
    if (contains(x)) {
      return;
    }
    auto new_node = new Node(x);
    new_node->next_ = head_;
    head_ = new_node;
    ++size_;
  }

  void remove(const ValueType &x) {
    Node *prev = nullptr;
    Node *node_to_delete = head_;
    while (node_to_delete != nullptr && node_to_delete->value_ != x) {
      prev = node_to_delete;
      node_to_delete = node_to_delete->next_;
    }

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

  std::size_t cardinality() const { return size_; }
  bool empty() const { return size_ == 0; }

  Node *begin() { return head_; }
  Node *begin() const { return head_; }

  bool contains(const ValueType &x) const {
    Node *current = head_;
    while (current != nullptr) {
      if (current->value_ == x) {
        return true;
      }
      current = current->next_;
    }
    return false;
  }

  bool operator==(const Set &other) const {
    return *this <= other && other <= *this;
  }

  bool operator<=(const Set &other) const {
    Node *current = head_;
    while (current != nullptr) {
      if (!other.contains(current->value_)) {
        return false;
      }
      current = current->next_;
    }
    return true;
  }

  Set<ValueType> operator+(const Set &t) {
    Set<ValueType> result;
    Node *t_element = t.begin();
    while (t_element != nullptr) {
      result.insert(t_element->value_);
      t_element = t_element->next_;
    }

    Node *s_element = head_;
    while (s_element != nullptr) {
      if (!t.contains(s_element->value_)) {
        result.insert(s_element->value_);
      }
      s_element = s_element->next_;
    }

    return result;
  }

  Set<ValueType> operator&(const Set &t) {
    Set<ValueType> result;
    Node *s_element = head_;
    while (s_element != nullptr) {
      if (t.contains(s_element->value_)) {
        result.insert(s_element->value_);
      }
      s_element = s_element->next_;
    }
    return result;
  }

  Set<ValueType> operator-(const Set &t) {
    Set<ValueType> result;
    Node *s_element = head_;
    while (s_element != nullptr) {
      if (!t.contains(s_element->value_)) {
        result.insert(s_element->value_);
      }
      s_element = s_element->next_;
    }
    return result;
  }

  std::string to_string() {
    Node *current = head_;
    if (current == nullptr) {
      return "";
    }
    std::stringstream set_str;
    while (current->next_ != nullptr) {
      set_str << current->value_ << " ";
      current = current->next_;
    }
    set_str << current->value_;
    return set_str.str();
  }

 private:

  Node *head_{};
  std::size_t size_{};
};

#endif // SET_H_