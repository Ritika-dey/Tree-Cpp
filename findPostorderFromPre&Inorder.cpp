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

node *constructTree(int inorder[], int preorder[], int start, int end, int& index){
    if(start>end) return NULL;

    node *root = new node(preorder[index++]);

    int i;
    for(i=start;i<= end;i++)
        if(inorder[i] == root->val) break;

    root->left = constructTree(inorder, preorder, start, i-1, index);
    root->right = constructTree(inorder, preorder, i+1, end, index);

    return root;
}

void postorder(node *root){
  if(!root) return;

  if(root->left) postorder(root->left);
  if(root->right) postorder(root->right);
  cout<<root->val<<" ";
}

int main() {
    // number of nodes
    int n;
    cin>>n;

    int inorder[n], preorder[n];
    for(int i=0;i<n;i++) cin>>inorder[i];
    for(int i=0;i<n;i++) cin>>preorder[i];

    int index =0;
    node* root = constructTree(inorder, preorder, 0, n-1, index);

    // postorder print
    cout<<"Postorder traversal of given tree : ";
    postorder(root);
}
