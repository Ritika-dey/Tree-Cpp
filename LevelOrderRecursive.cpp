#include <iostream>
using namespace std;

class node{
    public: 
    int val;
    node *left , *right;
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
  root->left = build();
  root->right = build();

  return root;
}

// height function
int height(node* root){
    if(!root) return 0;
    return max(height(root->left) , height(root->right))+1;
}

// function for printing level i
void printLevel(node *root , int level){
    if(!root) return;
    if (level == 1) cout<<root->val<<" ";
    else if(level >1){
       printLevel(root->left , level-1);
       printLevel(root->right , level-1);
    }
}

// level order function
void leveOrder(node *root){
  for(int i=1;i<=height(root);i++)
  {
      printLevel(root , i);
      cout<<endl;
  }
}

int main() {
    node *root = build();
    leveOrder(root);
    return 0;
}
