//  test_set.cpp
//  CS 271 Set Project: Unit Test File
#include "set.h"

#include <iostream>
#include <string>


void test_insert() {
  try {
    Set<std::string> s;
    std::string set_str = s.to_string();
    if (set_str != "") {
      std::cout << "Incorrect insert result. Expected \"\" but got: " << set_str << '\n';
    }

    s.insert("abc");
    set_str = s.to_string();
    if (set_str != "abc") {
      std::cout << "Incorrect insert result. Expected abc but got: " << set_str << '\n';
    }

    s.insert("def");
    s.insert("ghi");
    s.insert("def");

    // The set doesn't accept duplicate values
    set_str = s.to_string();
    if (set_str != "ghi def abc") {
      std::cout << "Incorrect insert result. Expected \"ghi def abc\" but got: " << set_str << '\n';
    }

    // Try to insert an empty string
    s.insert("");
    set_str = s.to_string();
    if (set_str != " ghi def abc") {
      std::cout << "Incorrect insert result. Expected \" ghi def abc\" but got: " << set_str << '\n';
    }

  } catch (std::exception &e){
    std::cerr << "Error inserting into set : " << e.what() << std::endl;
  }
}

void test_remove() {
  try {
    Set<int> s;
    // The set remains unchanged when trying to remove a non-existing element
    s.remove(1);
    std::string set_str = s.to_string();
    if (s.to_string() != "") {
        std::cout << "Incorrect remove result. Expected but got : " << set_str << std::endl;
    }

    s.insert(1);
    s.insert(2);
    s.insert(3);
    s.insert(4);
    s.insert(5);

    s.remove(6);
    set_str = s.to_string();
    if (s.to_string() != "5 4 3 2 1") {
      std::cout << "Incorrect remove result. Expected 5 4 3 2 1 but got : " << set_str << std::endl;
    }

    // successfully removes the element at the beginning
    s.remove(5);
    set_str = s.to_string();
    if (s.to_string() != "4 3 2 1") {
      std::cout << "Incorrect remove result. Expected 4 3 2 1 but got : " << set_str << std::endl;
    }

    // successfully removes the element in the middle
    s.remove(3);
    set_str = s.to_string();
    if (s.to_string() != "4 2 1") {
      std::cout << "Incorrect remove result. Expected 4 2 1 but got : " << set_str << std::endl;
    }

    // successfully removes the element at the end
    s.remove(1);
    set_str = s.to_string();
    if (s.to_string() != "4 2") {
      std::cout << "Incorrect remove result. Expected 4 2 but got : " << set_str << std::endl;
    }
  } catch (std::exception &e) {
    std::cerr << "Error removing from set : " << e.what() << std::endl;
  }
}

void test_cardinality() {
  try {
    Set<char> s;
    int c = s.cardinality();

    // An empty set has the cardinality 0
    if(c != 0) {
        std::cout << "Incorrect cardinality. Expected 0 but got : " << c << std::endl;
    }

    s.insert('a');
    s.insert('b');
    s.insert('c');
    s.insert('d');

    c = s.cardinality();
    if(c != 4) {
        std::cout << "Incorrect cardinality. Expected 4 but got : " << c << std::endl;
    }

    // if an element is removed, the cardinality of the set decrements by 1
    s.remove('a');
    s.remove('d');
    c = s.cardinality();
    if(c != 2) {
        std::cout << "Incorrect cardinality. Expected 2 but got : " << c << std::endl;
    }

    // if an element is inserted, the cardinality of the set increments by 1
    s.insert('e');
    s.insert('w');
    s.insert('o');
    c = s.cardinality();
    if (c != 5) {
        std::cout << "Incorrect cardinality. Expected 5 but got : " << c << std::endl;
    }

    // if we try to insert an existing element, the cardinality remains unchanged
    s.insert('b');
    c = s.cardinality();
    if (c != 5) {
        std::cout << "Incorrect cardinality. Expected 5 but got : " << c << std::endl;
    }
  } catch (std::exception &e) {
      std::cerr << "Error in determining set cardinality : " << e.what() << std::endl;
  }
}

void test_empty() {
  try {
    Set<float> s;
    if(!s.empty()){
      std::cout << "Empty set identified as non-empty" << std::endl;
    }

    s.insert(1.2);
    s.insert(2.4);
    if(s.empty()) {
      std::cout << "Non-empty set identified as empty" << std::endl;
    }

    // Remove non-exist element
    s.remove(1.4);
    if (s.empty()) {
      std::cout << "Non-empty set identified as empty" << std::endl;
    }

    s.remove(1.2);
    if(s.empty()) {
      std::cout << "Non-empty set identified as empty" << std::endl;
    }

    s.remove(2.4);
    if(!s.empty()) {
      std::cout << "Empty set identified as non-empty" << std::endl;
    }
  } catch (std::exception &e) {
    std::cerr << "Error in determining if set is the empty set : " << e.what() << std::endl;
  }
}

void test_contains() {
  try {
    Set<std::string> s;

    // an empty set does not contain any element
    if(s.contains("good")) {
        std::cout << "Incorrectly identified good as in the set " << s.to_string() << std::endl;
    }

    s.insert("hello");
    if (!s.contains("hello")) {
        std::cout << "incorrectly identified hello as in the set " << s.to_string() << std::endl;
    }

    s.insert("abc");
    s.insert("def");
    s.insert("ghi");
    if(s.contains("iop")) {
        std::cout << "Incorrectly identified iop as in the set " << s.to_string() << std::endl;
    }
    if(!s.contains("ghi")) {
        std::cout << "Incorrectly identified ghi as NOT in the set " << s.to_string() << std::endl;
    }

    // successfully identifies the element that was removed
    s.remove("def");
    if (s.contains("def")) {
        std::cout << "Incorrectly identified def as in the set " << s.to_string() << std::endl;
    }
  } catch (std::exception &e) {
      std::cerr << "Error in determining if value contained in se : " << e.what() << std::endl;
  }
}

void test_equality() {
    try {
        Set<int> s;
        Set<int> t;

        // Two empty sets are equal
        if(!(s==t)) {
            std::cout << "Empty sets should be considered equal" << std::endl;
        }
        s.insert(4);
        s.insert(5);
        s.insert(6);
        s.insert(7);
        if(s==t) {
            std::cout << "Incorrectly identified set " << s.to_string() << " as equivalent to " << t.to_string() << std::endl;
        }

        t.insert(7);
        t.insert(6);
        t.insert(5);
        t.insert(4);
        if(!(s==t)) {
            std::cout << "Sets " << s.to_string() << " and " << t.to_string() << " should be considered equal." << std::endl;
        }

        // after removing an element from one set, it is no longer equal to the other set
        s.remove(5);
        if(s==t) {
            std::cout << "Incorrectly identified set " << s.to_string() << " as equivalent to " << t.to_string() << std::endl;
        }

        // after removing the same element from both sets that are equal, the sets remain equal
        t.remove(5);
        if (!(s==t)) {
            std::cout << "Sets " << s.to_string() << " and " << t.to_string() << " should be considered equal." << std::endl;
        }

        
    } catch (std::exception &e) {
        std::cerr << "Error in determining set equality : " << e.what() << std::endl;
    }
}

void test_subset() {
    try {
        Set<int> s;
        Set<int> t;

        // an empty set is a subset of an empty set
        if(!(s<=t)) {
            std::cout << "Set " << s.to_string() << " should be considered a subset of the set " << t.to_string() << std::endl;
        }

        t.insert(7);
        t.insert(3);

        // an empty set is a subset of all sets
        if(!(s<=t)) {
            std::cout << "Set " << s.to_string() << " should be considered a subset of the set " << t.to_string() << std::endl;
        }

        // Equal sets are subsets of each other
        s.insert(3);
        s.insert(7);
        if(!(s<=t)) {
            std::cout << "Set " << s.to_string() << " should be considered a subset of the set " << t.to_string() << std::endl;
        }

        t.insert(1);
        if(!(s<=t)) {
            std::cout << "Set " << s.to_string() << " should be considered a subset of the set " << t.to_string() << std::endl;
        }

        s.insert(9);
        if(s<=t) {
            std::cout << "Set " << s.to_string() << " should NOT be considered a subset of the set " << t.to_string() << std::endl;
        }

        s.remove(9);
        s.remove(3);
        if (!(s<=t)) {
            std::cout << "Set " << s.to_string() << " should be considered a subset of the set " << t.to_string() << std::endl;
        }

        // the only subset of an empty set is another empty set
        t.remove(1);
        t.remove(7);
        t.remove(3);
        if ((s<=t)) {
            std::cout << "Set " << s.to_string() << " should NOT be considered a subset of the set " << t.to_string() << std::endl;
        }
        
    } catch (std::exception& e) {
        std::cerr << "Error in determining subset : " << e.what() << std::endl;
    }
}

void test_union() {
    try {
        Set<int> s;
        Set<int> t;

        // union of empty sets is an empty set
        std::string set_str = (s+t).to_string();
        if(set_str != "") {
            std::cout << "Union of the empty sets should be the empty set. Instead got : " << set_str << std::endl;
        }

        s.insert(1);
        t.insert(1);
        set_str = (s+t).to_string();
        if(set_str != "1") {
            std::cout << "Union of " << s.to_string() << " and " << t.to_string() << " was expected to be 1 but instead got : " << set_str << std::endl;
        }

        t.insert(2);
        t.insert(3);
        set_str = (s+t).to_string();
        if(set_str != "1 2 3") {
            std::cout << "Union of " << s.to_string() << " and " << t.to_string() << " was expected to be 1 2 3 but instead got : " << set_str << std::endl;
        }

        s.insert(4);
        s.insert(5);
        set_str = (s+t).to_string();
        if(set_str != "4 5 1 2 3") {
            std::cout << "Union of " << s.to_string() << " and " << t.to_string() << " was expected to be 4 5 1 2 3 but instead got : " << set_str << std::endl;
        }

        s.remove(4);
        s.remove(5);
        t.remove(2);
        t.remove(3);

        s.insert(7);
        t.insert(7);

        // if two sets are equal, the union set is also equal
        set_str = (s+t).to_string();
        if(set_str != "1 7" && !(s==t)) {
            std::cout << "Union of " << s.to_string() << " and " << t.to_string() << " was expected to be 1 7 but instead got : " << set_str << std::endl;
        }

    } catch (std::exception& e) {
        std::cerr << "Error in generating the union set : " << e.what() << std::endl;
    }
}

void test_intersection() {
    try {
        Set<int> s;
        Set<int> t;
        std::string set_str = (s&t).to_string();

        // intersection of empty sets is an empty set
        if(set_str != "") {
            std::cout << "Intersection of the empty sets should be the empty set. Instead got : " << set_str << std::endl;
        }

        s.insert(7);
        s.insert(8);
        t.insert(9);

        // if one of the sets is empty, then the intersection set is also empty
        set_str = (s&t).to_string();
        if(set_str != "") {
            std::cout << "Intersection of " << s.to_string() << " and " << t.to_string() << " was expected to be the empty set but instead got : " << set_str << std::endl;
        }

        // if none of the elements from the two sets overlap, then the intersection set is empty
        t.insert(5);
        t.insert(6);
        set_str = (s&t).to_string();
        if(set_str != "") {
            std::cout << "Intersection of " << s.to_string() << " and " << t.to_string() << " was expected to be the empty set but instead got : " << set_str << std::endl;
        }

        t.insert(8);
        set_str = (s&t).to_string();
        if(set_str != "8") {
            std::cout << "Intersection of " << s.to_string() << " and " << t.to_string() << " was expected to be 8 but instead got : " << set_str << std::endl;
        }

        t.remove(5);
        t.remove(6);
        t.remove(9);
        t.insert(7);
        set_str = (s&t).to_string();

        // if two sets are equal, the intersection set is also equal
        if (!(s==t)) {
            std::cout << "Sets " << s.to_string() << " and " << t.to_string() << " are not equal." << std::endl;
        }

        if(set_str != "7 8") {
            std::cout << "Intersection of " << s.to_string() << " and " << t.to_string() << " was expected to be 7 8 9 but instead got : " << set_str << std::endl;
        }

    } catch (std::exception& e) {
        std::cerr << "Error in generating the intersection set : " << e.what() << std::endl;
    }
}

void test_diff() {
    try {
        Set<int> s;
        Set<int> t;
        std::string set_str = (s-t).to_string();

        // difference of empty sets is an empty set
        if(set_str != "") {
            std::cout << "Difference of the empty sets should be the empty set. Instead got : " << set_str << std::endl;
        }

        s.insert(5);
        s.insert(6);
        set_str = (s-t).to_string();

        // difference of a non-empty set and an empty set is just the non-empty set
        if(set_str != "5 6") {
            std::cout << "Set " << s.to_string() << " \\ Set " << t.to_string() << " was expected to be 5 6 set but instead got : " << set_str << std::endl;
        }

        // difference of an empty set and a non-empty set is an empty set
        set_str = (t-s).to_string();
        if (set_str != "") {
            std::cout << "Set " << s.to_string() << " \\ Set " << t.to_string() << " was expected to be the empty set but instead got : " << set_str << std::endl;
        }

        // if the two sets are equal, their difference is an empty set
        t.insert(6);
        t.insert(5);
        set_str = (s-t).to_string();
        if(set_str != "") {
            std::cout << "Set " << s.to_string() << " \\ Set " << t.to_string() << " was expected to be the empty set but instead got : " << set_str << std::endl;
        }

        s.insert(7);
        s.insert(8);
        set_str = (s-t).to_string();
        if(set_str != "7 8") {
            std::cout << "Set " << s.to_string() << " \\ Set " << t.to_string() << " was expected to be 7 8 set but instead got : " << set_str << std::endl;
        }

    } catch (std::exception& e) {
        std::cerr << "Error in generating the intersection set : " << e.what() << std::endl;
    }
}

int main() {
  test_insert();
  test_remove();
  test_cardinality();
  test_empty();
  test_contains();
  test_equality();
  test_subset();
  test_union();
  test_intersection();
  test_diff();

  std::cout << "Testing completed" << std::endl;
    
  return 0;
}




