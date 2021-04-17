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

node *build(){
    int d;
    cin>>d;
    if(d==-1){
      return NULL;
    }
    node *root = new node(d);
    root->left = build();
    root->right = build();

    return root;
}
void pathSum(vector<int> &ans, node *root, int value){
    if(!root->left and !root->right){
        ans.push_back(value);
        return;
    }
    if(root->left) pathSum(ans, root->left, value+root->left->val);
    if(root->right) pathSum(ans, root->right, value+root->right->val);
}

int main() {
    node *root = build();
    vector<int> ans;
  
//   if root is null
    if(!root) {
        cout<<0<<endl;
        return 0;
    }
    pathSum(ans, root, root->val);

    cout<<"Sum of different paths in given tree : ";
    for(int i=0;i<ans.size();i++){
        cout<<ans[i]<<" ";
    }
}
