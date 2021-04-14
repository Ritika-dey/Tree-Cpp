// levels are printed from right to left

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

int height(node *root){
   if(!root) return 0;
   return max(height(root->left) , height(root->right))+1;
}

void printCurrLevel(node *root , int level){
    if(!root) return;
    if(level == 1) cout<<root->val<<" ";

    if(root->right) printCurrLevel(root->right, level-1);
    if(root->left) printCurrLevel(root->left, level-1);
}

void InvertedLevelOrder(node *root){
    for(int i=1;i<=height(root);i++)
    {
        printCurrLevel(root , i);
        cout<<endl;
    }
}

int main() {
    node *root = build();

    cout<<"Inverted Level order traversal : "<<endl;
    InvertedLevelOrder(root);
}
