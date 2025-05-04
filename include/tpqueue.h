// Copyright 2022 NNTU-CS
#ifndef INCLUDE_TPQUEUE_H_
#define INCLUDE_TPQUEUE_H_

struct SYM {
  char ch;
  int prior;
};

struct Node {
  SYM data;
  Node* next;
  Node(SYM sym) : data(sym), next(nullptr) {}
};
class TPQueue {
private:
  Node* head;
public:
  TPQueue() : head(nullptr) {}
  ~TPQueue() {
    while (!isEmpty()) {
      pop();
    }
  }
  void push(SYM sym) {
    Node* newNode = new Node(sym);
    if (head == nullptr || sym.prior > head->data.prior) {
      newNode->next = head;
      head = newNode;
    } else {
      Node* current = head;
      while (current->next != nullptr && sym.prior <= current->next->data.prior) {
        current = current->next;
      }
      newNode->next = current->next;
      current->next = newNode;
    }
  }
  SYM pop() {
    if (isEmpty()) {
      return { '\0', 0 };
    }
    Node* temp = head;
    SYM data = head->data;
    head = head->next;
    delete temp;
    return data;
  }
  bool isEmpty() const {
    return head == nullptr;
  }
};
#endif  // INCLUDE_TPQUEUE_H_
