#include <iostream>
#include <stack>
using namespace std;

class node{
    public:
    int val;
    node *left, *right;
    node(int data){
        val = data;
        left =NULL;
        right = NULL;
    }
};


stack<node*> s;

node* build(){
    int d;
    cin>>d;
    if(d == -1) return NULL;
    node *root = new node(d);
    root->left = build();
    root->right = build();

    return root;
}

// preorder iterative function
void preOrder(node *root){
    s.push(root);

    while(!s.empty()){
        node *curr = s.top() ;
        cout<<curr->val<<" ";
        s.pop();
        
        if(curr->right) s.push(curr->right);
        if(curr->left) s.push(curr->left);
    }
}

// inorder iterative function
void inOrder(node *root){ 
   node *curr = root;
   while(curr != NULL || !s.empty()){
       while(curr != NULL){
          s.push(curr);
          curr =curr->left;
       }
       curr = s.top();
       s.pop();

       cout<<curr->val<<" ";
       curr = curr->right;
   }
}

// postorder iterative function
void PostOrder(node* root){
    stack<node*> s2;
    s.push(root);

    while(!s.empty()){
        node *curr = s.top();
        s.pop();
        s2.push(curr);
        if(curr->left) s.push(curr->left);
        if(curr->right) s.push(curr->right);
    }

    while(!s2.empty()){
        cout<<s2.top()->val<<" ";
        s2.pop();
    }
}

int main() {
     node* root = build();

     cout<<"Preorder traversal : ";
     preOrder(root);
     cout<<endl;

     cout<<"Inorder traversal : ";
     inOrder(root);
     cout<<endl;

     cout<<"Postorder traversal : ";
     PostOrder(root);
     cout<<endl;
}
