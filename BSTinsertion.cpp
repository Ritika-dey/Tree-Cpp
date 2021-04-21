#include <iostream>
using namespace std;
class node{
    public:
     int val;
     node* left, *right;
     node(int data){
         val = data;
         left = right = NULL;
     }
};

node *build(node *root, int value){ 
    if(!root) {return new node(value);}
    if(root->val > value) root->left = build(root->left, value);
    if(root->val < value) root->right = build(root->right, value);

    return root;
}

void Inorder(node *root){
    if (!root) {
        return;
    }
    Inorder(root->left);
    cout << root->val << " ";
    Inorder(root->right);
}

int main() { 
    // number of nodes
    int n;
    cin>>n;

    // root node
    int data ;
    cin>>data;

    node *root = NULL;
    root = build(root, data); //inserting root

    for(int i=1;i<n;i++){
       cin>>data;
       build(root, data);
    } 

    cout<<"Inorder of BST : ";
    Inorder(root);
}
