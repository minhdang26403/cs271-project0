//
//  test_minqueue_example.cpp
//  Priority Queue Project
//
//  Created by Stacey Truex
//
#include <iostream>
#include "minqueue.h"
#include "usecase.cpp"

using namespace std;


void test_insert() {
    try {
        MinQueue<int> empty;
        empty.insert(0);
        string mq_str = empty.to_string();
        if(mq_str != "0") {
            cout << "Incorrect insert result. Epected 0 but got : " << mq_str << endl;
        }
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
    } catch (exception& e) {
        cerr << "Error inserting into the priority queue : " << e.what() << endl;
    }
}

void test_min() {
    try {
        MinQueue<int> empty;
        int min = empty.min();
        if(min != 0) {
            cout << "Incorrect min result. Expect 0 but got : " << min << endl;
        }
        int* int_data = new int[10];
        for(int i = 0; i < 10; i++){
            int_data[i] = 10-i;
        }
        MinQueue<int> mq(int_data, 10);
        min = mq.min();
        if(min != 1) {
            cout << "Incorrect min result. Expect 0 but got : " << min << endl;
        }
    } catch (exception& e) {
        cerr << "Error in determining min of the priority queue : " << e.what() << endl;
    }
}

void test_extract_min() {
    try {
        MinQueue<int> empty;
        int min = empty.extract_min();
        string mq_str = empty.to_string();
        if(min != 0 || mq_str != "") {
            cout << "Incorrect extract min result. Expected 0 and an empty queue but got : " << min << " and a queue of : " << mq_str << endl;
        }
        int* int_data = new int[10];
        for(int i = 0; i < 10; i++){
            int_data[i] = 10-i;
        }
        MinQueue<int> mq(int_data, 10);
        min = mq.extract_min();
        mq_str = mq.to_string();
        if(min != 1 || mq_str != "2 3 4 7 6 5 8 10 9") {
            cout << "Incorrect extract min result. Expected 0 and the queue 2 3 4 7 6 5 8 10 9 but got : " << min << " and a queue of : " << mq_str << endl;
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
        int* int_data = new int[10];
        for(int i = 0; i < 10; i++){
            int_data[i] = 10-i;
        }
        MinQueue<int> mq(int_data, 10);
        mq.decrease_key(0, -6);
        mq.decrease_key(9, -1);
        mq_str = mq.to_string();
        if (mq_str != "-6 -1 4 3 2 5 8 10 7 6") {
            cout << "Incorrect decrease key result. Expected empty queue but got : " << mq_str << endl;
        }
    } catch (exception &e) {
        cerr << "Error in decreasing key : " << e.what() << endl;
    }
}

void test_heapsort() {
    try {
        MinQueue<int> empty;
        int* empty_data = new int[0];
        empty.sort(empty_data);
        int* int_data = new int[10];
        for(int i = 0; i < 10; i++){
            int_data[i] = 10-i;
        }
        MinQueue<int> heap(int_data, 10);
        heap.sort(int_data);
        string sorted_str = to_string(int_data[0]);
        for(int i = 1; i < 10; i++) {
            sorted_str += (" " + to_string(int_data[i]));
        }
        if(sorted_str != "1 2 3 4 5 6 7 8 9 10") {
            cout << "Incorrect heapsort result. Expected 1 2 3 4 5 6 7 8 9 10 but got : " << sorted_str << endl;
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
        int nums[8] = {1,3,-1,-3,5,3,6,7};
        window_result = sliding_window(nums, 8, 3);
        if(window_result != "-1 -3 -3 -3 3 3") {
            cout << "Incorrect sliding window result. Expected -1 -3 -3 -3 3 3 but got : " << window_result << endl;
        }
        window_result = sliding_window(nums, 1, 1);
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
