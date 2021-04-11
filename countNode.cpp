#include <iostream>
using namespace std;

class node{
    public:
      int val;
      node *left, *right;

      node(int data){
          val = data;
          left = right = NULL;
      }
};
// data input
node *build(){
  int d;
  cin>>d;
  if(d == -1) return NULL;
  node *root = new node(d);

  root->right = build();
  root->left = build();

  return root;
}

int Count(node* root){
    if(!root) return 0;
    return Count(root->left) + Count(root->right) + 1;
}

int main() {
    node * root = build();

    cout<<"Number of nodes : "<<Count(root);
}
