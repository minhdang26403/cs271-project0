//
// Unit test for Set class
// 

#include "set.h"

#include <exception>
#include <iostream>
#include <string>

void test_insert() {
  try {
    Set<int> s;
    s.insert(1);
    std::string set_str = s.to_string();
    if (s.to_string() != "1") {
      std::cout << "Incorrect insert result. Expected 1 but got : " << set_str << std::endl;
    }
    s.insert(2);
    s.insert(3);
    set_str = s.to_string();
    if (s.to_string() != "3 2 1") {
      std::cout << "Incorrect insert result. Expected 3 2 1 but got : " << set_str << std::endl;
    }

    s.insert(1);
    set_str = s.to_string();
    // The set remains unchanged when inserting an existing value
    if (s.to_string() != "3 2 1") {
      std::cout << "Incorrect insert result. Expected 3 2 1 but got : " << set_str << std::endl;
    }
  } catch (std::exception& e) {
    std::cerr << "Error inserting into set : " << e.what() << std::endl;
  }
}

void test_remove() {
  try {
    Set<int> s;
    // Nothing happens when remove an element that doesn't exist in the set
    s.remove(1);
    s.insert(1);
    s.insert(2);
    s.insert(3);
    s.insert(4);
    s.remove(5);
    std::string set_str = s.to_string();
    if (s.to_string() != "4 3 2 1") {
      std::cout << "Incorrect remove result. Expected 4 3 2 1 but got : " << set_str << std::endl;
    }
    s.remove(3);
    set_str = s.to_string();
    if(s.to_string() != "4 2 1") {
      std::cout << "Incorrect remove result. Expected 4 2 1 but got : " << set_str << std::endl;
    }
  } catch (std::exception &e) {
    std::cerr << "Error removing from set : " << e.what() << std::endl;
  }
}


int main() {
  test_insert();
  // test_remove();
  // test_cardinality();
  // test_empty();
  // test_contains();
  // test_equality();
  // test_subset();
  // test_union();
  // test_intersection();
  // test_diff();

  std::cout << "Testing completed" << std::endl;

  return 0;
}