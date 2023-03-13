#include <cstring>

using std::cout;
using std::endl;

struct Node {
  int data;
  Node* parent, *left, *right;

  Node() {
    memset(this, 0x0, sizeof(Node));
  }

  Node(int data) {
    memset(this, 0x0, sizeof(Node));
    this->data = data;
  }
};

struct BST {
  Node* root;
  
  BST() {
    this->root = nullptr;
  }

  bool empty() {
    return root == nullptr;
  }

  void print(Node* n = reinterpret_cast<Node*>(69420), int depth = 0) {
    if (reinterpret_cast<unsigned long long>(n) == 69420) n = this->root; // terrible fix but im lazy 
    if (n == nullptr) return;
    depth++;
    print(n->right, depth);
    for (int i = 0; i < depth - 1; i++) {
      cout << "          ";
    }
    cout << n->data << endl;
    print(n->left, depth);
  }
  
  bool insert(int data) {
    if (root == nullptr) {
      root = new Node(data);
      return true;
    }
    Node* prev = nullptr;
    Node* curr = root;
    while (curr != nullptr) {
      prev = curr;
      if (data > curr->data) curr = curr->right;
      else if (data < curr->data) curr = curr->left;
      else return false; // We have a duplicate :(
    }
    ((data < prev->data) ? prev->left : prev->right) = new Node(data);
    return true;
  }

  bool contains(int data) {
    // Search for a value
    Node* curr = root;
    while (curr != nullptr) {
      if (curr->data == data) return true;
      if (data > curr->data) curr = curr->right;
      else curr = curr->left;
    }
    return false;
  }

  
};
