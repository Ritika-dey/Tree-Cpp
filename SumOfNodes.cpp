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
// taking input
node *build(){
    int d;
    cin>>d;
    if(d== -1 ) return NULL;
    node *root = new node(d);
    root->left = build();
    root->right = build();
    return root;
}
// sum function
int nodeSum(node *root){
    if(!root) return 0;
    return root->val + nodeSum(root->left) + nodeSum(root->right);
}

int main() {
    node *root = build();

    cout<<"Sum of nodes : "<<nodeSum(root)<<endl;
}
