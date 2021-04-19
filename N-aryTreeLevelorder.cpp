// leetcode #429

/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> children;

    Node() {}

    Node(int _val) {
        val = _val;
    }

    Node(int _val, vector<Node*> _children) {
        val = _val;
        children = _children;
    }
};
*/

class Solution {
public:
    vector<vector<int>> levelOrder(Node* root) {
        if(!root) return {};
        vector<vector<int>> ans;
        
        queue<Node*> q;
        q.push(root);
        while(!q.empty()){
            vector<int> temp;
            int size = q.size();
            
            while(size--){
                Node* curr = q.front();
                q.pop();
                for(auto child : curr->children)
                    q.push(child); 
                temp.push_back(curr->val);
            }
            ans.push_back(temp);
        }
        return ans;
        
    }
};
