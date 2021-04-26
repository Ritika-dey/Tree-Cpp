// diameter is number of edges in the longest path

#include <iostream>
#include <climits>
using namespace std;
int diameter = INT_MIN;

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
    if(d == -1) return NULL;
    node *root = new node(d);
    root->left = build();
    root->right = build();

    return root;
}

int traverseTree(node *root){
   if(!root) return 0;
   int leftD = traverseTree(root->left);
   int rightD = traverseTree(root->right);
       
   diameter = max(diameter, leftD+ rightD);
   return max(leftD, rightD)+1; 
}

int main() { 
    node *root = build();

    traverseTree(root);
    cout<<"Diameter of tree is : "<<diameter<<endl;
}
