#pragma once
#include <iostream>
#include <algorithm>
using namespace std;

class BinarySearchTree {
private:
  struct Node {
    int value, height;
    Node *leftChild, *rightChild, *parent;

    Node(int value) {
      this->height = 0;
      this->value = value;
      leftChild = rightChild = parent = nullptr;
    }

    void update() {
      this->height = max((this->leftChild ? -1 : this->leftChild->height),
                        (this->rightChild ? -1 : this->rightChild->height)) + 1;
    }

    Node * rightRotate(Node*& root) {
      if (this == root) {
        Node *A = this->leftChild->leftChild;
        Node *B = this->leftChild->rightChild;
        Node *C = this->rightChild;
        Node *y = this->leftChild;
        
        y->rightChild = this;
        this->parent = y;
        this->leftChild = B;
        if (B)  B->parent = this;
        root = y;
        return root;
      }
      else {
        Node *par = this->parent;
        Node *A = this->leftChild->leftChild;
        Node *B = this->leftChild->rightChild;
        Node *C = this->rightChild;
        Node *y = this->leftChild;
        if (par->leftChild == this) par->leftChild = y;
        else                        par->rightChild = y;

        y->rightChild = this;
        this->parent = y;
        this->leftChild = B;
        if (B)  B->parent = this;
        return y;
      }
    }


    // TODO: Add leftRotate function
  };

  Node *root;

  // Not balanced
  // TODO: Add balancing
  void insertHelper(Node *root, int value) {
    if (root == nullptr) { this->root = new Node(value); return; }

    if (root->value < value) {
      if (!root->rightChild) {
        root->rightChild = new Node(value);
        root->rightChild->parent = root;
        return;
      }
      insertHelper(root->rightChild, value);
    }
    else {
      if (!root->leftChild) {
        root->leftChild = new Node(value);
        root->leftChild->parent = root;
        return;
      }
      insertHelper(root->leftChild, value);
    }
  }

  bool searchHelper(Node *root, int value) {
    if (root == nullptr) {
      return false;
    }
    if (root->value == value) {
      return true;
    }
    return root->value < value ? searchHelper(root->rightChild, value) :
                                searchHelper(root->leftChild, value);
  }

  // Not balanced:
  // TODO: Add balancing
  void eraseHelper(Node *root, int value) {
    if (root == this->root && (!root->leftChild || !root->rightChild)) {
      if (root->leftChild == root->rightChild) { 
        this->root = nullptr;
        delete root;
      }
      else {
        if (root->leftChild) {
          this->root = root->leftChild;
          this->root->parent = nullptr;
        }
        else {
          this->root = root->rightChild;
          this->root->parent = nullptr;
        }
        delete root;
      }
      return;
    }
    if (root->value == value) {
      if (root->leftChild && root->rightChild) {
        Node *tmp = root->rightChild;
        while(tmp->leftChild) {
          tmp = tmp->leftChild;
        }
        root->value = tmp->value;
        eraseHelper(root->rightChild, tmp->value);
      }
      else if (root->leftChild || root->rightChild) {
        Node * par = root->parent, *child = (root->leftChild ? root->leftChild : root->rightChild);
        if (par->leftChild == root) {
          par->leftChild = child;
          child->parent = par;
        }
        else {
          par->rightChild = child;
          child->parent = par;
        }
        delete root;
      }
      else {
        if (root->parent->leftChild == root) {
          root->parent->leftChild = nullptr;
        }
        else {
          root->parent->rightChild = nullptr;
        }
        delete root;
      }
    }
    else if (root->value < value) {
      eraseHelper(root->rightChild, value);
    }
    else {
      eraseHelper(root->leftChild, value);
    }
  }

  void printHelper(Node *root, string indent = "") {
    if (!root) return;
    printHelper(root->leftChild, indent + "\t");
    cout << indent << root->value << endl;
    printHelper(root->rightChild, indent + "\t");
  }

public:
  BinarySearchTree() : root(nullptr) {}

  void insert(int value) { insertHelper(root, value); }

  bool search(int value) { return searchHelper(root, value); }

  void erase(int value) { eraseHelper(root, value); }

  void print() { printHelper(root); }
};