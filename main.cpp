#include <iostream>
#include <fstream>
#include "BST.h"
#include "Utils.h"

using namespace std;

// Prompt the user for a file name to load all the numbers from 
void promptLoadFromFile(BST& bst) {
  char filePath[200];
  cout << "Enter the file path: ";
  cin.ignore();
  cin.getline(filePath, 200);
  ifstream fin(filePath);
  if (!fin.good()) {
    cout << "Invalid file path!\n";
    return;
  }
  int ct = 0;
  int t;
  while (fin >> t) {
    bst.insert(t);
    ct++;
  }
  cout << "Loaded " << ct << " number(s)!\n";
}

// Prompt the user for a number to add to the BST
bool promptAddNumber(BST& bst) {
  int num;
  cout << "Enter a number: ";
  cin >> num;
  return bst.insert(num);
}

// Prompt the user for a number to delete from the BST
bool promptDeleteNumber(BST& bst) {
  int num;
  cout << "Enter a number: ";
  cin >> num;
  return bst.remove(num);
}

// Prompt the user for a number to search so we can check if it's in the BST 
bool promptSearchNumber(BST& bst) {
  int num;
  cout << "Enter a number: ";
  cin >> num;
  return bst.contains(num);
}

int main() {
  BST bst;
  char in[35];
  while (true) {
    cout << "Enter command (ADD, PRINT, DELETE, LOAD, SEARCH, or QUIT): ";
    cin >> in;
    if (Utils::chkcmd(in, "add")) cout << (promptAddNumber(bst) ? "Added!" : "Couldn't add, we hit a duplicate!") << endl;
    else if (Utils::chkcmd(in, "print")) bst.print();
    else if (Utils::chkcmd(in, "delete")) cout << (promptDeleteNumber(bst) ? "Deleted!" : "Couldn't delete, number not found!") << endl;
    else if (Utils::chkcmd(in, "load")) promptLoadFromFile(bst);
    else if (Utils::chkcmd(in, "search")) cout << (promptSearchNumber(bst) ? "Found!" : "Couldn't find!") << endl;
    else if (Utils::chkcmd(in, "quit")) break;
    else cout << "Invalid command!\n"; 
  }
  return 0;
}