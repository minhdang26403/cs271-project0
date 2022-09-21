//  test_minqueue.cpp
//  Priority Queue Project
//  Unit Tests 
#include <iostream>
#include <string>
#include "minqueue.h"
#include "usecase.cpp"

using namespace std;


void test_insert() {
  try {

    // when a heap is empty
    MinQueue<int> empty;
    string mq_str = empty.to_string();
    if(mq_str != "") {
      cout << "Incorrect initialization. Expected an empty string but got : " << mq_str << endl; 
    }

    // when one element is inserted 
    empty.insert(3);
    mq_str = empty.to_string();
    if(mq_str != "3") {
      cout << "Incorrect insert result. Expected 3 but got : " << mq_str << endl;
    }

    // when an element that is smaller than the current root is inserted, it maintains the heap property
    empty.insert(2);
    empty.insert(1);
    mq_str = empty.to_string();
    if (mq_str != "1 3 2") {
      cout << "Incorrect insert result. Expected 1 3 2 but got : " << mq_str << endl;
    }
    
    // creates a min priority queue from an array of elements
    int* int_data = new int[10];
    for(int i = 0; i < 10; i++) {
      int_data[i] = 10-i;
    }
    MinQueue<int> mq(int_data, 10);
    mq.insert(25);
    mq.insert(0);
    mq_str = mq.to_string();
    if(mq_str != "0 2 1 3 6 4 8 10 7 9 25 5") {
      cout << "Incorrect insert result. Expected 0 2 1 3 6 4 8 10 7 9 25 5 but got : " << mq_str << endl;
    }

    // if the array is already sorted, it is already a heap
    int_data = new int[10];
    for(int i = 0; i < 10; i++) {
      int_data[i] = i;
    }
    MinQueue<int> mq_sorted(int_data, 10);
    mq_str = mq_sorted.to_string();
    if(mq_str != "0 1 2 3 4 5 6 7 8 9") {
      cout << "Incorrect insert result. Expected 0 1 2 3 4 5 6 7 8 9 but got : " << mq_str << endl;
    }

    // when duplicates are inserted, it maintains the heap property 
    mq.insert(2);
    mq.insert(2);
    mq_str = mq.to_string();
    if(mq_str != "0 2 1 3 6 2 2 10 7 9 25 5 4 8") {
      cout << "Incorrect insert result. Expected 0 2 1 3 6 2 2 10 7 9 25 5 4 8 but got : " << mq_str << endl;
    }

    // when negative elements are inserted 
    int_data = new int[10];
    for(int i = 0; i < 10; i++) {
      int_data[i] = -1 *(10-i);
    }
    MinQueue<int> mq_neg(int_data, 10);
    mq_neg.insert(-99);
    mq_str = mq_neg.to_string();
    if(mq_str != "-99 -10 -8 -7 -9 -5 -4 -3 -2 -1 -6") {
      cout << "Incorrect insert result. Expected -99 -10 -8 -7 -9 -5 -4 -3 -2 -1 -6 but got : " << mq_str << endl;
    }

    // works correctly with objects with different data types 
    char* char_data = new char[10];
    char_data[0] = 'z';
    char_data[1] = 'c';
    char_data[2] = 's';
    char_data[3] = 't';
    char_data[4] = 'o';
    char_data[5] = 'u';
    MinQueue<char> mq_char(char_data, 6);
    mq_char.insert('b');
    mq_char.insert('a');
    mq_char.insert('v');
    mq_str = mq_char.to_string();
    if(mq_str != "a b c o z u s t v") {
      cout << "Incorrect insert result. Expected a b c o z u s t v but got : " << mq_str << endl;
    }

    MinQueue<double> mq_double; 
    for (int i = 0; i < 10; i++) {
      mq_double.insert(2.2 * i);
    }
    mq_str = mq_double.to_string();
    if(mq_str != "0 2.2 4.4 6.6 8.8 11 13.2 15.4 17.6 19.8") {
      cout << "Incorrect insert result. Expected  0 2.2 4.4 6.6 8.8 11 13.2 15.4 17.6 19.8but got : " << mq_str << endl;
    }

  } catch (exception& e) {
    cerr << "Error inserting into the priority queue : " << e.what() << endl;
  }
}

void test_min() {
  try {
    // when a min-priority queue is empty, the minimum element is 0
    MinQueue<int> empty;
    int min = empty.min();
    if(min != 0) {
      cout << "Incorrect min result. Expect 0 but got : " << min << endl;
    }

    // when a min-priority queue has only one element, that element is the minimum element 
    MinQueue<float> empty_fl;
    empty_fl.insert(5.0);
    float min_fl = empty_fl.min();
    if(min_fl != 5.0) {
      cout << "Incorrect min result. Expect 5.0 but got : " << min_fl << endl;
    } 

    // when a min-priority queue has more than one element, the smallest element is the minimum element 
    int* int_data = new int[10];
    for(int i = 0; i < 10; i++) {
      int_data[i] = 35-i;
    }
    MinQueue<int> mq(int_data, 10);
    mq.insert(25);
    mq.insert(7);
    int mq_min = mq.min();
    if(mq_min != 7) {
      cout << "Incorrect min result. Expect 7 but got : " << min_fl << endl;
    } 

    // works correctly with objects with different data types 
    MinQueue<long> mq_long;
    mq_long.insert(5000000);
    mq_long.insert(7000000);
    mq_long.insert(10000000);
    mq_long.insert(1500000);
    long min_l = mq_long.min();
    if(min_l != 1500000) {
      cout << "Incorrect min result. Expect 1500000 but got : " << min_l << endl;
    } 

    MinQueue<string> mq_string;
    mq_string.insert("Josh");
    mq_string.insert("Daniel");
    mq_string.insert("Adam");
    mq_string.insert("Tyler");
    string min_str = mq_string.min();
    if(min_str != "Adam") {
      cout << "Incorrect min result. Expect Adam but got : " << min_str << endl;
    }

    char* char_data = new char[7];
    char_data[0] = 'g';
    char_data[1] = 'f';
    char_data[2] = 'e';
    char_data[3] = 'd';
    char_data[4] = 'c';
    char_data[5] = 'b';
    char_data[6] = 'a';
    MinQueue<char> mq_ch(char_data, 7);
    char min_ch = mq_ch.min();
    if(min_ch != 'a') {
      cout << "Incorrect min result. Expect a but got : " << min_ch << endl;
    }

    bool* A = new bool[3];
    A[0] = true;
    A[1] = false;
    A[2] = false;
    MinQueue<bool> mq_bool(A, 3);
    bool min_bl = mq_bool.min();
    if(min_bl != false) {
      cout << "Incorrect min result. Expect 0 but got : " << min_bl << endl;
    }

  } catch (exception& e) {
    cerr << "Error in determining min of the priority queue : " << e.what() << endl;
  }
}

void test_extract_min() {
  try {
    // when a min-priority queue is empty, the minimum element is 0 and it stays empty
    MinQueue<int> empty;
    int min = empty.extract_min();
    string mq_str = empty.to_string();
    if(min != 0 || mq_str != "") {
      cout << "Incorrect extract min result. Expected 0 and an empty queue but got : " << min << " and a queue of : " << mq_str << endl;
    }

    // correctly returns the minimum element and remove it from the object
    int* int_data = new int[5];
    for(int i = 0; i < 5; i++){
      int_data[i] = i+1;
    }
    MinQueue<int> mq(int_data, 5);
    min = mq.extract_min();
    mq_str = mq.to_string();
    if(min != 1 || mq_str != "2 4 3 5") {
      cout << "Incorrect extract min result. Expected 1 and the queue 2 4 3 5 but got : " << min << " and a queue of : " << mq_str << endl;
    }

    min = mq.extract_min();
    mq_str = mq.to_string();
    if(min != 2 || mq_str != "3 4 5") {
      cout << "Incorrect extract min result. Expected 2 and the queue 3 4 5 but got : " << min << " and a queue of : " << mq_str << endl;
    }

    min = mq.extract_min();
    mq_str = mq.to_string();
    if(min != 3 || mq_str != "4 5") {
      cout << "Incorrect extract min result. Expected 3 and the queue 4 5 but got : " << min << " and a queue of : " << mq_str << endl;
    }

    min = mq.extract_min();
    mq_str = mq.to_string();
    if(min != 4 || mq_str != "5") {
      cout << "Incorrect extract min result. Expected 4 and the queue 5 but got : " << min << " and a queue of : " << mq_str << endl;
    }

    min = mq.extract_min();
    mq_str = mq.to_string();
    if(min != 5 || mq_str != "") {
      cout << "Incorrect extract min result. Expected 5 and the empty queue but got : " << min << " and a queue of : " << mq_str << endl;
    }

    // works correctly with objects with different data types 
    MinQueue<string> mq_s;
    mq_s.insert("computer science");
    mq_s.insert("philosophy");
    mq_s.insert("math");
    mq_s.insert("psychology");
    string min_str = mq_s.extract_min();
    mq_str = mq_s.to_string();
    if(min_str != "computer science" || mq_str != "math philosophy psychology") {
      cout << "Incorrect extract min result. Expected computer science and the queue math philosophy psychology but got : " << min << " and a queue of : " << mq_str << endl;
    }

  } catch (exception& e) {
    cerr << "Error in determining min of the priority queue : " << e.what() << endl;
  }
}

void test_decrease_key() {
  try {
    MinQueue<int> empty;
    empty.decrease_key(0, 0);
    string mq_str = empty.to_string();
    if (mq_str != "") {
      cout << "Incorrect decrease key result. Expected empty queue but got : " << mq_str << endl;
    }

    MinQueue<double> mq_d;
    for (int i = 0; i < 5; i++) {
      mq_d.insert(i+1);
    }

    // when the new value is greater than the current element, decrease_key does not change anything
    mq_d.decrease_key(1, 8);
    mq_str = mq_d.to_string();
    if (mq_str != "1 2 3 4 5") {
      cout << "Incorrect decrease key result. Expected 1 2 3 4 5 but got : " << mq_str << endl;
    }

    mq_d.decrease_key(3, 2.34);
    mq_str = mq_d.to_string();
    if (mq_str != "1 2 3 2.34 5") {
      cout << "Incorrect decrease key result. Expected 1 2 3 2.34 5 but got : " << mq_str << endl;
    }

    // when the new value is already equal to the value of the current element, the object remains unchanged
    mq_d.decrease_key(1, 2);
    mq_str = mq_d.to_string();
    if (mq_str != "1 2 3 2.34 5") {
      cout << "Incorrect decrease key result. Expected 1 2 3 2.34 5 but got : " << mq_str << endl;
    }

    int* int_data = new int[10];
    for(int i = 0; i < 10; i++){
      int_data[i] = 10-i;
    }
    MinQueue<int> mq(int_data, 10);
    mq.decrease_key(0, -7);
    mq.decrease_key(9, -1);
    mq_str = mq.to_string();
    if (mq_str != "-7 -1 4 3 2 5 8 10 7 6") {
      cout << "Incorrect decrease key result. Expected -7 -1 4 3 2 5 8 10 7 6 but got : " << mq_str << endl;
    }

    MinQueue<string> mq_s;
    mq_s.insert("banana");
    mq_s.insert("orange");
    mq_s.insert("dragonfruit");
    mq_s.decrease_key(0, "pineapple");
    mq_s.decrease_key(0, "apple");
    mq_s.decrease_key(2, "coconut");
    mq_str = mq_s.to_string();
    if (mq_str != "apple orange coconut") {
      cout << "Incorrect decrease key result. Expected apple orange coconut but got : " << mq_str << endl;
    }

  } catch (exception &e) {
    cerr << "Error in decreasing key : " << e.what() << endl;
  }
}

void test_heapsort() {
  try {
    // an empty min-priority queue is already sorted
    MinQueue<int> empty;
    int* empty_data = new int[0];
    empty.sort(empty_data);
    string sorted_str = to_string(empty_data[0]);
    if(sorted_str != "0") {
      cout << "Incorrect heapsort result. Expected 0 but got : " << sorted_str << endl;
    }
    
    int* int_data = new int[10];
    for(int i = 0; i < 10; i++){
      int_data[i] = 10-i;
    }

    MinQueue<int> heap_i(int_data, 10);
    heap_i.sort(int_data);
    string sorted_str2 = to_string(int_data[0]);
    for(int i = 1; i < 10; i++) {
      sorted_str2 += (" " + to_string(int_data[i]));
    }
    if(sorted_str2 != "1 2 3 4 5 6 7 8 9 10") {
      cout << "Incorrect heapsort result. Expected 1 2 3 4 5 6 7 8 9 10 but got : " << sorted_str << endl;
    }

    // works correctly with objects with different data types
    char* char_data = new char[4];
    char_data[0] = 'd';
    char_data[1] = 'c';
    char_data[2] = 'b';
    char_data[3] = 'a';
    MinQueue<char> heap_c(char_data, 4);
    heap_c.sort(char_data);
    string sorted_str3 = to_string(char_data[0]);
    for(int i = 1; i < 4; i++) {
      sorted_str3 += (" " + to_string(char_data[i]));
    }
    if(sorted_str3 != "97 98 99 100") {
      cout << "Incorrect heapsort result. Expected 97 98 99 100 but got : " << sorted_str << endl;
    }

    float* float_data = new float[5];
    for (int i = 0; i < 5; i++) {
      float_data[i] = i * 2.1;
    }
    MinQueue<float> heap_f(float_data, 5);
    heap_f.sort(float_data);
    string sorted_str4 = to_string(float_data[0]);
    for(int i = 1; i < 5; i++) {
      sorted_str4 += (" " + to_string(float_data[i]));
    }
    if(sorted_str4 != "0.000000 2.100000 4.200000 6.300000 8.400000") {
      cout << "Incorrect heapsort result. Expected 0.000000 2.100000 4.200000 6.300000 8.400000 but got : " << sorted_str << endl;
    }

  } catch (exception& e) {
      cerr << "Error in sorting : " << e.what() << endl;
  }
}

void test_sliding_window() {
  try {
    int* empty = new int[0];
    string window_result = sliding_window(empty, 0, 0);
    if(window_result != "") {
      cout << "Incorrect sliding window result. Expected an empty string but got : " << window_result << endl;
    }
    int arr1[8] = {-2,3,-1,-3,-5,3,10,7};
    window_result = sliding_window(arr1, 8, 3);
    if(window_result != "-2 -3 -5 -5 -5 3") {
      cout << "Incorrect sliding window result. Expected -2 -3 -5 -5 -5 3 but got : " << window_result << endl;
    }
    int arr2[2] = {1, -1};
    window_result = sliding_window(arr2, 1, 1);
    if(window_result != "1") {
      cout << "Incorrect sliding window result. Expected 1 but got : " << window_result << endl;
    }
  } catch(exception &e) {
    cerr << "Error in generating sliding window result : " << e.what() << endl;
  }
}

int main() {
    
    test_insert();
    test_min();
    test_extract_min();
    test_decrease_key();
    test_heapsort();
    test_sliding_window();
    
    cout << "Testing completed" << endl;
    
    return 0;
}
