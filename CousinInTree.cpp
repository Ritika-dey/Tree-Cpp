//leetcode #993
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
node *build(){
    int d;
    cin>>d;
    if(d== -1) return NULL;

    node *root = new node(d);
    root->left = build();
    root->right = build();

    return root;
}

int heightX = 0, heightY = 0, parentX = -1, parentY = -1;
void checkCousin(node *root, int x, int y, int h, int parent){
        if(!root) return;  
        if(root->val == x) {
            heightX = h;
            parentX = parent;
            return;
        }
        if(root->val == y) {
            heightY = h;
            parentY = parent;
            return;
        }
        if(root->left) checkCousin(root->left, x, y, h+1, root->val);
        if(root->right) checkCousin(root->right, x, y, h+1, root->val);   
    }
    
bool isCousins(node* root, int x, int y) {
        if(root->val == x or root->val == y) return false;
        if(root->left){ 
            if(root->left->val == x or root->left->val == y) return false;
        }
        if(root->right){ 
            if(root->right->val == x or root->right->val == y)return false;
        }
        
        checkCousin(root, x, y, 0,0);  
        if(parentX != parentY and heightX == heightY) return true;
        return false;
}

int main() {
    node *root = build();

    int x, y;
    cin>>x>>y;
  
    if(isCousins(root, x, y)) cout<<"Yes"<<endl;
    else cout<<"No"<<endl;
}
