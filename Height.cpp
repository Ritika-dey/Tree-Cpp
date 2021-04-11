#include <iostream>
using namespace std;

class node{
    public:
      int val;
      node *left , *right;

      node(int data){
          val = data;
          left = NULL;
          right - NULL;
      }
};

node *build(){
    int d;
    cin>>d;
    if(d == -1) return NULL;
    node* root = new node(d);
    root->left = build();
    root->right = build();

    return root;
}

// height function
int Height(node *root){
    if(!root) return 0;
    return max(Height(root->left) , Height(root->right))+1;
}

int main() {
     node* root = build();

     cout<<"Height of tree : "<<Height(root)<<endl;
     return 0;
}
