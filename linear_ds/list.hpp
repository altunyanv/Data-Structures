#pragma once

class SinglyLinkedList {
public:
  struct Node {
    int value;
    Node * next;

    Node(int nvalue) {
      value = nvalue;
      next = nullptr;
    }
  };

  SinglyLinkedList() {
    head = tail = nullptr;
  }

  void push_front(int nvalue) {
    Node *tmp = new Node(nvalue);
    tmp->next = head;
    head = tmp;
    if (tail == nullptr) {
      tail = tmp;
    }
  }

  void pop_front() {
    Node *tmp = head;
    head = head->next;
    delete tmp;
    if (head == nullptr) {
      tail = nullptr;
    }
  }

  void push_back(int nvalue) {
    Node *tmp = new Node(nvalue);
    if (tail == nullptr) {
      tail = tmp;
      head = tmp;
    }
    else {
      tail->next = tmp;
      tail = tmp;
    }
  }

  void pop_back() {
    Node *tmp = head;
    if (head == tail) {
      delete tail;
      head = tail = nullptr;
      return;
    }
    while(tmp->next != tail) {
      tmp = tmp->next;
    }
    delete tail;
    tail = tmp;
    tmp->next = nullptr;
  }

  void insert(Node* prev, int nvalue) {
    Node *tmp = new Node(nvalue);
    tmp->next = prev->next;
    prev->next = tmp;
  }

  void erase(Node* prev) {
    if (prev->next == nullptr) {
      return;
    }
    Node *tmp = prev->next;
    prev->next = prev->next->next;
    delete tmp;
  }

private:
  Node *head, *tail;
};



class DoublyLinkedList {
public:
  struct Node {
    int value;
    Node * next, * previous;

    Node(int nvalue) {
      value = nvalue;
      next = previous = nullptr;
    }
  };
  // TODO:
};