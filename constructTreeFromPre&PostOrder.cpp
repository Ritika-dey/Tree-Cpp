#include <iostream>
#include <queue>
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

int preIndex = 0, posIndex = 0;
node* constructTree(int pre[], int post[]) {
    node* root = new node(pre[preIndex++]);
    if(root->val != post[posIndex]) {
        root->left = constructTree(pre,post); 
        root->right = constructTree(pre,post);
    }
    posIndex++;
    return root;
}

void levelOrder(node *root){
   if(!root) return;

   queue<node*> q;
   q.push(root);
   while(!q.empty()){
       int size = q.size();
       while(size--){
           node* curr = q.front();
           q.pop();

           if(curr->left) q.push(curr->left);
           if(curr->right) q.push(curr->right);

           cout<<curr->val<<" ";
       }
       cout<<endl;
   }
}

int main() {
    int n;
    cin>>n;
    if(n%2 != 1) {
       cout<<"All nodes of binary tree must have 2 or 0 childs"; //check tree is full binary tree or not
       return 0;
    }
    int pre[n], post[n];
    for(int i=0;i<n;i++) cin>>pre[i];
    for(int i=0;i<n;i++) cin>>post[i];

    node *root = constructTree(pre, post);

    // tree output
    levelOrder(root);
}
