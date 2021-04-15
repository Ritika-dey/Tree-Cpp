#include <iostream>
using namespace std;

class node{
    public:
      int val;
      node* left , *right ;
      node(int d){
          val = d;
          left = right = NULL;
      }
};

node* build(){
    int d;
    cin>>d;
    if(d == -1) return NULL;

    node *root = new node(d);
    root->left = build();
    root->right = build();
    return root;
}
// height of tree
int height(node *root){
   if(!root) return 0;
   return max(height(root->left) , height(root->right))+1;
}

// for printing the level left to right
void leftToRight(node* root , int level){
   if(!root) return;
   if(level == 1) cout<<root->val<<" ";

   if(root->left) leftToRight(root->left , level-1);
   if(root->right) leftToRight(root->right , level-1);
} 

// for printing the level right to left
void rightToLeft(node* root , int level){
   if(!root) return;
   if(level == 1) cout<<root->val<<" ";

   if(root->right) rightToLeft(root->right , level-1);
   if(root->left) rightToLeft(root->left , level-1);
} 

void zigZag(node *root){
    for(int i=1;i<=height(root);i++)
    {
      if(i%2 ==0) leftToRight(root , i);
      else rightToLeft(root , i);

      cout<<endl;
    }
}

int main() {
    node *root = build();

    cout<<"Zig Zag traversal : "<<endl;
    zigZag(root);
}

