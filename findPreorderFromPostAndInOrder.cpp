#include <bits/stdc++.h>
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

node *constructTree(int inorder[], int postorder[], int start, int end, int &index){
    if(start>end) return NULL;

    node *root = new node(postorder[index--]); 

    int i;
    for(i= start;i<= end;i++)
        if(inorder[i] == root->val) break;
    
    root->right = constructTree(inorder, postorder, i+1, end, index);
    root->left = constructTree(inorder, postorder, start, i-1, index); 
    return root;
}

void PrintpreOrder(node* root){
    if(!root) return;

    cout<<root->val<<" ";
    PrintpreOrder(root->left);
    PrintpreOrder(root->right);
}

int main() { 
    int n;
    cin>>n;
    int in[n], post[n];
    for(int i=0;i<n;i++) cin>>in[i];
    for(int i=0;i<n;i++) cin>>post[i];
 
    // construction function call
    int index = n-1;
    node *root = constructTree(in, post, 0, n-1, index);

    // print preorder of resultant tree
    cout<<"Preorder traversal of given tree : ";
    PrintpreOrder(root);
 
}
