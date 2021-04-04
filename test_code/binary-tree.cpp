#include <bits/stdc++.h>

using namespace std;

class Node
{
public:
  int val;
  Node *left;
  Node *right;

  Node(int _val) : val(_val), left(nullptr), right(nullptr) {}
};

int main()
{
  Node *node = new Node(2);
  node->left = new Node(3);
  cout << node->left->val << endl;
}