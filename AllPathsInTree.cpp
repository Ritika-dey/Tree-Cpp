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

node *build(){
    int d;
    cin>>d;
    if(d== -1) return NULL;

    node* root = new node(d);
    root->left = build();
    root->right = build();

    return root;
}
// utility function
void pathsUtility(node *root, string value){
  if(!root->left and !root->right){
      cout<<value<<endl;
      return;
  }

  if(root->left) pathsUtility(root->left , value + "->" + to_string(root->left->val));
  if(root->right) pathsUtility(root->right , value + "->" + to_string(root->right->val));
}

// find all paths
void findPaths(node *root){ 
    pathsUtility(root, to_string(root->val));
}
int main() {
    node *root = build(); 
    findPaths(root);
    return 0;
}
