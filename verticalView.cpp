#include <bits/stdc++.h>
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

// data input
node *build(){
  int d;
  cin>>d;
  if(d == -1) return NULL;

  node *root = new node(d);
  root->left = build();
  root->right = build();

  return root;
}


void currLevel(node* root , map<int , vector<int>>& m ,int hd){
   if(!root) return;
   
   m[hd].push_back(root->val);

//recursive call for left child
   currLevel(root->left , m , hd-1 );

//recursive call for right child
   currLevel(root->right , m , hd+1 );
}

void verticalView(node *root){
    map<int , vector<int>> m;
    int hd = 0 ; //horizontal distance

    currLevel(root , m , hd);
//    print 
    map<int , vector<int>> :: iterator itr;
    for(itr = m.begin() ; itr != m.end() ; itr++){
        for(int i=0;i< itr->second.size();i++)
           cout<<itr->second[i]<<" ";
        cout<<endl;
    }
}

int main() {
    node *root = build();

    cout<<"Vertical view of tree : "<<endl;
    verticalView(root);
}
