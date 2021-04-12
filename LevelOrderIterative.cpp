 #include <iostream>
 #include <queue>
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

node *build(){
    int d;
    cin>>d;
    if(d== -1 ) return NULL;
    node *root = new node(d);
    root->left = build();
    root->right = build();
    return root;
}
 
void levelOrder(node *root){
    queue<node*> q;
    q.push(root);

    while(!q.empty()){
        node *curr = q.front();
        cout<<curr->val<<" ";
        q.pop();
        if(curr->left) q.push(curr->left);
        if(curr->right) q.push(curr->right);
    }
}

int main() {
    node *root = build();

    cout<<"Level order traversal : ";
    levelOrder(root);
}
