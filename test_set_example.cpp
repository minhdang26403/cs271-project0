//
//  test_set_example.cpp
//  CS 271 Set Project: Example Test File
//
//  Created by Dr. Stacey Truex
//
#include "set.h"

#include <exception>
#include <iostream>
#include <string>

void test_insert() {
    try {
        Set<int> s;
        s.insert(0);
        std::string set_str = s.to_string();
        if (s.to_string() != "0") {
            std::cout << "Incorrect insert result. Expected 0 but got : " << set_str << std::endl;
        }
        s.insert(2);
        s.insert(-1);
        set_str = s.to_string();
        if (s.to_string() != "-1 2 0") {
            std::cout << "Incorrect insert result. Expected -1 2 0 but got : " << set_str << std::endl;
        }
    } catch (std::exception& e) {
        std::cerr << "Error inserting into set : " << e.what() << std::endl;
    }
}

void test_remove() {
    try {
        Set<int> s;
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

void test_cardinality() {
    try {
        Set<int> s;
        int c = s.cardinality();
        if(c != 0) {
            std::cout << "Incorrect cardinality. Expected 0 but got : " << c << std::endl;
        }
        s.insert(6);
        s.insert(5);
        s.insert(4);
        s.insert(3);
        s.insert(2);
        c = s.cardinality();
        if(c != 5) {
            std::cout << "Incorrect cardinality. Expected 5 but got : " << c << std::endl;
        }
        s.remove(4);
        s.remove(2);
        c = s.cardinality();
        if(c != 3) {
            std::cout << "Incorrect cardinality. Expected 3 but got : " << c << std::endl;
        }
    } catch (std::exception &e) {
        std::cerr << "Error in determining set cardinality : " << e.what() << std::endl;
    }
}

void test_empty() {
    try {
        Set<int> s;
        if(!s.empty()){
            std::cout << "Empty set identified as non-empty" << std::endl;
        }
        s.insert(1);
        s.insert(2);
        if(s.empty()) {
            std::cout << "Non-empty set identified as empty" << std::endl;
        }
        s.remove(2);
        if(s.empty()) {
            std::cout << "Non-empty set identified as empty" << std::endl;
        }
        s.remove(1);
        if(!s.empty()) {
            std::cout << "Empty set identified as non-empty" << std::endl;
        }
    } catch (std::exception &e) {
        std::cerr << "Error in determining if set is the empty set : " << e.what() << std::endl;
    }
}

void test_contains() {
    try {
        Set<int> s;
        if(s.contains(5)) {
            std::cout << "Incorrectly identified 5 as in the set " << s.to_string() << std::endl;
        }
        s.insert(1);
        s.insert(2);
        s.insert(3);
        if(s.contains(5)) {
            std::cout << "Incorrectly identified 5 as in the set " << s.to_string() << std::endl;
        }
        if(!s.contains(2)) {
            std::cout << "Incorrectly identified 2 as NOT in the set " << s.to_string() << std::endl;
        }
    } catch (std::exception &e) {
        std::cerr << "Error in determining if value contained in se : " << e.what() << std::endl;
    }
}

void test_equality() {
    try {
        Set<int> s;
        Set<int> t;
        if(!(s==t)) {
            std::cout << "Empty sets should be considered equal" << std::endl;
        }
        s.insert(1);
        s.insert(2);
        s.insert(3);
        if(s==t) {
            std::cout << "Incorrectly identified set " << s.to_string() << " as equivalent to " << t.to_string() << std::endl;
        }
        t.insert(1);
        t.insert(2);
        t.insert(3);
        if(!(s==t)) {
            std::cout << "Sets " << s.to_string() << " and " << t.to_string() << " should be considered equal." << std::endl;
        }
        s.remove(3);
        if(s==t) {
            std::cout << "Incorrectly identified set " << s.to_string() << " as equivalent to " << t.to_string() << std::endl;
        }
    } catch (std::exception &e) {
        std::cerr << "Error in determining set equality : " << e.what() << std::endl;
    }
}

void test_subset() {
    try {
        Set<int> s;
        Set<int> t;
        if(!(s<=t)) {
            std::cout << "Set " << s.to_string() << " should be considered a subset of the set " << t.to_string() << std::endl;
        }
        t.insert(3);
        t.insert(7);
        if(!(s<=t)) {
            std::cout << "Set " << s.to_string() << " should be considered a subset of the set " << t.to_string() << std::endl;
        }
        s.insert(7);
        s.insert(3);
        if(!(s<=t)) {
            std::cout << "Set " << s.to_string() << " should be considered a subset of the set " << t.to_string() << std::endl;
        }
        t.insert(10);
        if(!(s<=t)) {
            std::cout << "Set " << s.to_string() << " should be considered a subset of the set " << t.to_string() << std::endl;
        }
        s.insert(11);
        if(s<=t) {
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
        std::string set_str = (s+t).to_string();
        if(set_str != "") {
            std::cout << "Union of the empty sets should be the empty set. Instead got : " << set_str << std::endl;
        }
        s.insert(1);
        s.insert(2);
        t.insert(2);
        t.insert(1);
        set_str = (s+t).to_string();
        if(set_str != "2 1") {
            std::cout << "Union of " << s.to_string() << " and " << t.to_string() << " was expected to be 2 1 but instead got : " << set_str << std::endl;
        }
        t.insert(6);
        set_str = (s+t).to_string();
        if(set_str != "2 1 6") {
            std::cout << "Union of " << s.to_string() << " and " << t.to_string() << " was expected to be 2 1 6 but instead got : " << set_str << std::endl;
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
        if(set_str != "") {
            std::cout << "Intersection of the empty sets should be the empty set. Instead got : " << set_str << std::endl;
        }
        s.insert(1);
        s.insert(2);
        t.insert(6);
        set_str = (s&t).to_string();
        if(set_str != "") {
            std::cout << "Intersection of " << s.to_string() << " and " << t.to_string() << " was expected to be the empty set but instead got : " << set_str << std::endl;
        }
        t.insert(2);
        t.insert(1);
        set_str = (s&t).to_string();
        if(set_str != "1 2") {
            std::cout << "Intersection of " << s.to_string() << " and " << t.to_string() << " was expected to be 1 2 but instead got : " << set_str << std::endl;
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
        if(set_str != "") {
            std::cout << "Difference of the empty sets should be the empty set. Instead got : " << set_str << std::endl;
        }
        s.insert(1);
        s.insert(2);
        t.insert(6);
        set_str = (s-t).to_string();
        if(set_str != "1 2") {
            std::cout << "Set " << s.to_string() << " \\ Set " << t.to_string() << " was expected to be 1 2 set but instead got : " << set_str << std::endl;
        }
        t.insert(2);
        t.insert(1);
        set_str = (s-t).to_string();
        if(set_str != "") {
            std::cout << "Set " << s.to_string() << " \\ Set " << t.to_string() << " was expected to be the empty set set but instead got : " << set_str << std::endl;
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



