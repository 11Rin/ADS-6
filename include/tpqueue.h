// Copyright 2022 NNTU-CS
#ifndef INCLUDE_TPQUEUE_H_
#define INCLUDE_TPQUEUE_H_
#include <string>

template<typename T, int size>
class TPQueue {
 private:
    T* arr;
    int head, tail, cnt;

 public:
    TPQueue() : head(0), tail(0), cnt(0) {
      arr = new T[size];
    }
    ~TPQueue() {
      delete[] arr;
    }
    bool isEmpty() const {
      return cnt == 0;
    }
    bool isFull() const {
      return cnt == size;
    }
    void push(const T& value) {
      if (isFull()) {
        throw std::string("Full");
      }
      cnt++;
      int curr = tail;
      for (int i = head; i < tail; i++) {
        if (arr[i].prior < value.prior) {
          curr = i;
          break;
        }
      }
      for (int i = tail; i > curr; i--) {
        arr[i % size] = arr[(i - 1) % size];
      }
      arr[curr % size] = value;
      tail += 1;
    }
    T& pop() {
      if (isEmpty()) {
        throw std::string("Empty");
      }
      cnt--;
      return arr[head++ % size];
    }
};

struct SYM {
  char ch;
  int prior;
};

#endif  // INCLUDE_TPQUEUE_H_
