/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

class Solution {
public:
    TreeNode *searchLCA(TreeNode* root, TreeNode* p, TreeNode* q){
        if(!root) return NULL; 
        //inorder traversal to serach the nodes
        root->left = searchLCA(root->left,p,q);
        if(root == p or root == q) return root;
        root->right = searchLCA(root->right,p,q);
        
        if(!root->left and !root->right) return NULL; //if not found
        if(!root->left) return root->right; 
        if(!root->right) return root->left;
        
        return root;
    }
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        if(root == p) return p;
        if(root == q) return q;
        
        return searchLCA(root, p, q);
    }
};
