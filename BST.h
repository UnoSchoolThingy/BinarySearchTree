#include <cstring>

// Just making this binary search tree a red black tree so I can copy paste into the next assignment

// Looked at https://en.wikipedia.org/wiki/Red%E2%80%93black_tree 

enum class Color : uint8_t {
  BLACK,
  RED
};

struct Node {
  int data;
  Node* parent, left, right;
  Color color;

  Node() {
    memset(this, 0x0, sizeof(Node));
  }
};

struct BST {
  Node* root;

  BST() {
    this->root = nullptr;
  }
};
