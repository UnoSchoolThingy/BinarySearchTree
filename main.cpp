#include <iostream>
#include "BST.h"

using namespace std;

int main() {
  srand(time(NULL));
  BST tree;
  for (int i = 0; i < 10; i++) {
    while (!tree.insert(rand() % 20 + 1));
  }
  tree.print();
  for (int i = 0; i < 20; i++) {
    cout << i;
    if (tree.contains(i)) cout << " CONTAINED!";
    cout << endl;
  }
  return 0;
}
