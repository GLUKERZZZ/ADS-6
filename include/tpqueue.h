// Copyright 2022 NNTU-CS
#ifndef INCLUDE_TPQUEUE_H_
#define INCLUDE_TPQUEUE_H_

struct SYM {
  char ch;
  int prior;
};

template <typename T>
class TPQueue {
 private:
  struct Node {
    T data;
    Node* next;
    explicit Node(const T& sym) : data(sym), next(nullptr) {}
  };
  Node* head;

 public:
  TPQueue() : head(nullptr) {}
  ~TPQueue() {
    while (!isEmpty()) {
      pop();
    }
  }
  void push(const T& sym) {
    Node* newNode = new Node(sym);
    if (head == nullptr || sym.prior > head->data.prior) {
      newNode->next = head;
      head = newNode;
    } else {
      Node* cur = head;
      while (cur->next != nullptr && sym.prior <= cur->next->data.prior) {
        cur = cur->next;
      }
      newNode->next = cur->next;
      cur->next = newNode;
    }
  }
  T pop() {
    if (isEmpty()) {
      return { '\0', 0 };
    }
    Node* temp = head;
    T data = head->data;
    head = head->next;
    delete temp;
    return data;
  }
  bool isEmpty() const {
    return head == nullptr;
  }
};
#endif  // INCLUDE_TPQUEUE_H_
