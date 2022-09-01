//  test_set.cpp
//  CS 271 Set Project: Unit Test File

#include <iostream>
#include "set.h"
using namespace std;


void test_insert() {
    try {
        Set<int> s;

        s.insert(1);
        string set_str = s.to_string();
        if (s.to_string() != "1") {
            cout << "Incorrect insert result. Expected 1 but got : " << set_str << endl;
        }

        s.insert(2);
        s.insert(3);
        set_str = s.to_string();
        if (s.to_string() != "3 2 1") {
            cout << "Incorrect insert result. Expected 3 2 1 but got : " << set_str << endl;
        }

        // The set remains unchanged when inserting an existing value
        s.insert(2);
        set_str = s.to_string();
        if (s.to_string() != "3 2 1") {
            cout << "Incorrect insert result. Expected 3 2 1 but got : " << set_str << endl;
        }

    } catch (exception& e) {
        cerr << "Error inserting into set : " << e.what() << endl;
    }
}

void test_remove() {
    try {
        Set<int> s;

        // The set remains unchanged when trying to remove a non-existing element
        s.remove(1);
        string set_str = s.to_string();
        if (s.to_string() != "") {
            cout << "Incorrect remove result. Expected but got : " << set_str << endl;
        }

        s.insert(1);
        s.insert(2);
        s.insert(3);
        s.insert(4);
        s.insert(5);

        s.remove(6);
        set_str = s.to_string();
        if (s.to_string() != "5 4 3 2 1") {
            cout << "Incorrect remove result. Expected 5 4 3 2 1 but got : " << set_str << endl;
        }


        // successfully removes the element at the beginning
        s.remove(5);
        set_str = s.to_string();
        if (s.to_string() != "4 3 2 1") {
            cout << "Incorrect remove result. Expected 4 3 2 1 but got : " << set_str << endl;
        }

        // successfully removes the element in the middle
        s.remove(3);
        set_str = s.to_string();
        if (s.to_string() != "4 2 1") {
            cout << "Incorrect remove result. Expected 4 2 1 but got : " << set_str << endl;
        }

        // successfully removes the element at the end
        s.remove(1);
        set_str = s.to_string();
        if (s.to_string() != "4 2") {
            cout << "Incorrect remove result. Expected 4 2 but got : " << set_str << endl;
        }


    } catch (exception &e) {
        cerr << "Error removing from set : " << e.what() << endl;
    }
}

void test_cardinality() {
    try {
        Set<int> s;
        int c = s.cardinality();

        // An empty set has the cardinality 0
        if(c != 0) {
            cout << "Incorrect cardinality. Expected 0 but got : " << c << endl;
        }

        s.insert(10);
        s.insert(9);
        s.insert(8);
        s.insert(7);
      
        c = s.cardinality();
        if(c != 4) {
            cout << "Incorrect cardinality. Expected 4 but got : " << c << endl;
        }

        // if an element is removed, the cardinality of the set decrements by 1
        s.remove(8);
        s.remove(7);
        c = s.cardinality();
        if(c != 2) {
            cout << "Incorrect cardinality. Expected 2 but got : " << c << endl;
        }

        // if an element is inserted, the cardinality of the set increments by 1
        s.insert(6);
        s.insert(5);
        s.insert(4);
        c = s.cardinality();
        if (c != 5) {
            cout << "Incorrect cardinality. Expected 5 but got : " << c << endl;
        }

        // if we try to insert an existing element, the cardinality remains unchanged
        s.insert(4);
        c = s.cardinality();
        if (c != 5) {
            cout << "Incorrect cardinality. Expected 5 but got : " << c << endl;
        }
    } catch (exception &e) {
        cerr << "Error in determining set cardinality : " << e.what() << endl;
    }
}

void test_empty() {
    try {
        Set<int> s;
        if(!s.empty()){
            cout << "Empty set identified as non-empty" << endl;
        }

        s.insert(1);
        s.insert(2);
        if(s.empty()) {
            cout << "Non-empty set identified as empty" << endl;
        }

        s.remove(1);
        if(s.empty()) {
            cout << "Non-empty set identified as empty" << endl;
        }

        s.remove(2);
        if(!s.empty()) {
            cout << "Empty set identified as non-empty" << endl;
        }

    } catch (exception &e) {
        cerr << "Error in determining if set is the empty set : " << e.what() << endl;
    }
}

void test_contains() {
    try {
        Set<int> s;

        // an empty set does not contain any element
        if(s.contains(1)) {
            cout << "Incorrectly identified 1 as in the set " << s.to_string() << endl;
        }

        s.insert(4);
        if (!s.contains(4)) {
            cout << "incorrectly identified 4 as in the set " << s.to_string() << endl;
        }

        s.insert(1);
        s.insert(2);
        s.insert(3);
        if(s.contains(7)) {
            cout << "Incorrectly identified 7 as in the set " << s.to_string() << endl;
        }
        if(!s.contains(2)) {
            cout << "Incorrectly identified 2 as NOT in the set " << s.to_string() << endl;
        }

        // successfully identifies the element that was removed
        s.remove(2);
        if (s.contains(2)) {
            cout << "Incorrectly identified 2 as in the set " << s.to_string() << endl;
        }

    } catch (exception &e) {
        cerr << "Error in determining if value contained in se : " << e.what() << endl;
    }
}

void test_equality() {
    try {
        Set<int> s;
        Set<int> t;

        // Two empty sets are equal
        if(!(s==t)) {
            cout << "Empty sets should be considered equal" << endl;
        }
        s.insert(4);
        s.insert(5);
        s.insert(6);
        s.insert(7);
        if(s==t) {
            cout << "Incorrectly identified set " << s.to_string() << " as equivalent to " << t.to_string() << endl;
        }

        t.insert(7);
        t.insert(6);
        t.insert(5);
        t.insert(4);
        if(!(s==t)) {
            cout << "Sets " << s.to_string() << " and " << t.to_string() << " should be considered equal." << endl;
        }

        // after removing an element from one set, it is no longer equal to the other set
        s.remove(5);
        if(s==t) {
            cout << "Incorrectly identified set " << s.to_string() << " as equivalent to " << t.to_string() << endl;
        }

        // after removing the same element from both sets that are equal, the sets remain equal
        t.remove(5);
        if (!(s==t)) {
            cout << "Sets " << s.to_string() << " and " << t.to_string() << " should be considered equal." << endl;
        }

        
    } catch (exception &e) {
        cerr << "Error in determining set equality : " << e.what() << endl;
    }
}

void test_subset() {
    try {
        Set<int> s;
        Set<int> t;

        // an empty set is a subset of an empty set
        if(!(s<=t)) {
            cout << "Set " << s.to_string() << " should be considered a subset of the set " << t.to_string() << endl;
        }

        t.insert(7);
        t.insert(3);

        // an empty set is a subset of all sets
        if(!(s<=t)) {
            cout << "Set " << s.to_string() << " should be considered a subset of the set " << t.to_string() << endl;
        }

        // Equal sets are subsets of each other
        s.insert(3);
        s.insert(7);
        if(!(s<=t)) {
            cout << "Set " << s.to_string() << " should be considered a subset of the set " << t.to_string() << endl;
        }

        t.insert(1);
        if(!(s<=t)) {
            cout << "Set " << s.to_string() << " should be considered a subset of the set " << t.to_string() << endl;
        }

        s.insert(9);
        if(s<=t) {
            cout << "Set " << s.to_string() << " should NOT be considered a subset of the set " << t.to_string() << endl;
        }

        s.remove(9);
        s.remove(3);
        if (!(s<=t)) {
            cout << "Set " << s.to_string() << " should be considered a subset of the set " << t.to_string() << endl;
        }

        // the only subset of an empty set is another empty set
        t.remove(1);
        t.remove(7);
        t.remove(3);
        if ((s<=t)) {
            cout << "Set " << s.to_string() << " should NOT be considered a subset of the set " << t.to_string() << endl;
        }
        
    } catch (exception& e) {
        cerr << "Error in determining subset : " << e.what() << endl;
    }
}

void test_union() {
    try {
        Set<int> s;
        Set<int> t;

        // union of empty sets is an empty set
        string set_str = (s+t).to_string();
        if(set_str != "") {
            cout << "Union of the empty sets should be the empty set. Instead got : " << set_str << endl;
        }

        s.insert(1);
        t.insert(1);
        set_str = (s+t).to_string();
        if(set_str != "1") {
            cout << "Union of " << s.to_string() << " and " << t.to_string() << " was expected to be 1 but instead got : " << set_str << endl;
        }

        t.insert(2);
        t.insert(3);
        set_str = (s+t).to_string();
        if(set_str != "1 2 3") {
            cout << "Union of " << s.to_string() << " and " << t.to_string() << " was expected to be 1 2 3 but instead got : " << set_str << endl;
        }

        s.insert(4);
        s.insert(5);
        set_str = (s+t).to_string();
        if(set_str != "4 5 1 2 3") {
            cout << "Union of " << s.to_string() << " and " << t.to_string() << " was expected to be 4 5 1 2 3 but instead got : " << set_str << endl;
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
            cout << "Union of " << s.to_string() << " and " << t.to_string() << " was expected to be 1 7 but instead got : " << set_str << endl;
        }

    } catch (exception& e) {
        cerr << "Error in generating the union set : " << e.what() << endl;
    }
}

void test_intersection() {
    try {
        Set<int> s;
        Set<int> t;
        string set_str = (s&t).to_string();

        // intersection of empty sets is an empty set
        if(set_str != "") {
            cout << "Intersection of the empty sets should be the empty set. Instead got : " << set_str << endl;
        }

        s.insert(7);
        s.insert(8);
        t.insert(9);

        // if one of the sets is empty, then the intersection set is also empty
        set_str = (s&t).to_string();
        if(set_str != "") {
            cout << "Intersection of " << s.to_string() << " and " << t.to_string() << " was expected to be the empty set but instead got : " << set_str << endl;
        }

        // if none of the elements from the two sets overlap, then the intersection set is empty
        t.insert(5);
        t.insert(6);
        set_str = (s&t).to_string();
        if(set_str != "") {
            cout << "Intersection of " << s.to_string() << " and " << t.to_string() << " was expected to be the empty set but instead got : " << set_str << endl;
        }

        t.insert(8);
        set_str = (s&t).to_string();
        if(set_str != "8") {
            cout << "Intersection of " << s.to_string() << " and " << t.to_string() << " was expected to be 8 but instead got : " << set_str << endl;
        }

        t.remove(5);
        t.remove(6);
        t.remove(9);
        t.insert(7);
        set_str = (s&t).to_string();

        // if two sets are equal, the intersection set is also equal
        if (!(s==t)) {
            cout << "Sets " << s.to_string() << " and " << t.to_string() << " are not equal." << endl;
        }

        if(set_str != "7 8") {
            cout << "Intersection of " << s.to_string() << " and " << t.to_string() << " was expected to be 7 8 9 but instead got : " << set_str << endl;
        }

    } catch (exception& e) {
        cerr << "Error in generating the intersection set : " << e.what() << endl;
    }
}

void test_diff() {
    try {
        Set<int> s;
        Set<int> t;
        string set_str = (s-t).to_string();

        // difference of empty sets is an empty set
        if(set_str != "") {
            cout << "Difference of the empty sets should be the empty set. Instead got : " << set_str << endl;
        }

        s.insert(5);
        s.insert(6);
        set_str = (s-t).to_string();

        // difference of a non-empty set and an empty set is just the non-empty set
        if(set_str != "5 6") {
            cout << "Set " << s.to_string() << " \\ Set " << t.to_string() << " was expected to be 5 6 set but instead got : " << set_str << endl;
        }

        // difference of an empty set and a non-empty set is an empty set
        set_str = (t-s).to_string();
        if (set_str != "") {
            cout << "Set " << s.to_string() << " \\ Set " << t.to_string() << " was expected to be the empty set but instead got : " << set_str << endl;
        }

        // if the two sets are equal, their difference is an empty set
        t.insert(6);
        t.insert(5);
        set_str = (s-t).to_string();
        if(set_str != "") {
            cout << "Set " << s.to_string() << " \\ Set " << t.to_string() << " was expected to be the empty set but instead got : " << set_str << endl;
        }

        s.insert(7);
        s.insert(8);
        set_str = (s-t).to_string();
        if(set_str != "7 8") {
            cout << "Set " << s.to_string() << " \\ Set " << t.to_string() << " was expected to be 7 8 set but instead got : " << set_str << endl;
        }

    } catch (exception& e) {
        cerr << "Error in generating the intersection set : " << e.what() << endl;
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
    
    cout << "Testing completed" << endl;
    
    return 0;
}




