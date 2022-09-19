#include "minqueue.h"

#include <iostream>

void test_insert() {
  int data1[6] = {2,7,26,25,19,17};
  MinQueue<int> mq(data1, 6);
  mq.insert(5);
  mq.insert(1);
  assert(mq.to_string() == "1 2 5 7 19 26 17 25");

  MinQueue<std::string> empty;
  assert(empty.to_string() == "");
  empty.insert("abc");
  empty.insert("aac");
  assert(empty.to_string() == "aac abc");
  empty.insert(" ");
  empty.insert("s");
  assert(empty.to_string() == "  abc aac s");
}

void test_min() {
  int data1[6] = {4,10,22,26,19,17};
  MinQueue<int> mq(data1, 6);
  mq.insert(6);
  mq.insert(2);
  assert(mq.to_string() == "2 4 6 10 19 22 17 26");
}

int main() {
  test_insert();
  test_min();
  

  std::cout << "Testing completed\n";
}