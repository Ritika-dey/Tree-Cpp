#include <iostream>
using namespace std;

class Node{
    public:
    int val;
    Node *left , *right;
    Node(int data){
      val = data;
      left = NULL;
      right = NULL;
    }
};

Node* build(){
    int data;
    cin>> data;
    if(data == -1) return NULL;
    Node *root = new Node(data);
    root->left = build();
    root->right = build();
    return root;
}
// preorder recursive function
void preOrder(Node *root){
  if(root == NULL) return;

  cout<<root->val<<" ";
  preOrder(root->left);
  preOrder(root->right);

}

// postorder recursive function
void postOrder(Node* root){
    if(root == NULL) return;

    postOrder(root->left);
    postOrder(root->right);
    cout<<root->val<<" ";
}
// inorder recursive funcion
void inOrder(Node* root){
   if(root == NULL) return;
   inOrder(root->left);
   cout<<root->val<<" ";
   inOrder(root->right);
}

int main() {
    Node* root = build();
    cout<<"Preorder traversal : ";
    preOrder(root);
    cout<<endl;

    cout<<"Postorder traversal : ";
    postOrder(root);
    cout<<endl;
    
    cout<<"Inorder traversal : ";
    inOrder(root);
    cout<<endl;
}
