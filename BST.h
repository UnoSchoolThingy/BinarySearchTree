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
    Node* newNode = new Node(data);
    newNode->parent = prev;
    ((data < prev->data) ? prev->left : prev->right) = newNode;
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

  bool remove(int data) {
     // Search 
    Node* curr = root;
    while (curr != nullptr) {
      if (curr->data == data) {
        // curr is the node we want to get rid of
        if (curr->left == nullptr && curr->right == nullptr) { // We have no children 
          if (curr->parent == nullptr) {
            // We're the root
            root = nullptr; // Bye bye root
          } else {
            // We're not the root
            if (curr->parent->left == curr) curr->parent->left = nullptr;
            else curr->parent->right = nullptr; 
          }
          delete curr;
        } else if (curr->left == nullptr || curr->right == nullptr) {
          // One child
          Node* child = (curr->left == nullptr) ? curr->right : curr->left;
          if (curr->parent == nullptr) {
            // We're the root
            root = child;
          } else {
            // We're not the root, so we connect the parent to the child (yay) 
            if (curr->parent->left == curr) curr->parent->left = child;
            else curr->parent->right = child; 
          }
          child->parent = curr->parent;
          delete curr;
        } else {
          // Two children
          Node* successor = curr->right; 
          while (successor->left != nullptr) successor = successor->left; // Find the smallest value in the right subtree
          curr->data = successor->data; // We can safely swap cuz any values in the right subtree are greater than the current node cuz successor is the next largest value from curr 
          (successor->parent->left == successor ? successor->parent->left : successor->parent->right) = successor->right; // We are replacing the successor with its right child
          if (successor->right != nullptr) successor->right->parent = successor->parent;
          delete successor; // Get rid of the sacrificial node (your sacrifice will not be forgotten)
        }
        return true;
      }
      if (data > curr->data) curr = curr->right;
      else curr = curr->left;
    }
    return false;
  }
  
};
