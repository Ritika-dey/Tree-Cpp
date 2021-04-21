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

bool searchNode(node *root, int node){
    if(!root) return false;
    if(root->val == node) return true;
     
    if(root->val < node) return searchNode(root->right, node);
    return searchNode(root->left, node); 
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

    int node ; // node to be searched
    cin>>node;

    if(searchNode(root, node)) cout<<"Found"<<endl;
    else cout<<"Not Found"<<endl;
}
